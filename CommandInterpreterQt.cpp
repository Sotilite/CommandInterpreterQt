#include "CommandInterpreterQt.h"
#include "ui_CommandInterpreterQt.h"
#include "MeasureMachine.h"
#include "Report.h"
#include <QFileDialog>
#include <qmessagebox.h>
#include <qhash.h>

using namespace std;

CommandInterpreterQt::CommandInterpreterQt(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	mMachine = new MeasureMachine(this);
	report = new Report(this);

	planeResults = QHash<QString, tuple<double*, double*>>();
	circleResults = QHash<QString, tuple<double*, double*, double*>>();
	commandsHistory = QHash<QString, QString>();
	commandsResults = QHash<int, QHash<QString, QString>>();
	numPreviousLine = 0;
	sequenceNumber = 0;
	//numberOfClicks = 0;
	hasError = false;


	connect(ui.runButton, &QPushButton::clicked, this, &CommandInterpreterQt::runButtonClick);
	//connect(ui.debugButton, &QPushButton::clicked, this, &CommandInterpreterQt::debugButtonClick);
	connect(ui.saveFileButton, &QPushButton::clicked, this, &CommandInterpreterQt::saveFileButtonClick);
	connect(ui.openFileButton, &QPushButton::clicked, this, &CommandInterpreterQt::openFileButtonClick);
	connect(ui.getReportButton, &QPushButton::clicked, this, &CommandInterpreterQt::getReportButtonClick);
	connect(ui.clearInputButton, &QPushButton::clicked, this, &CommandInterpreterQt::clearInputButtonClick);
	connect(ui.clearOutputButton, &QPushButton::clicked, this, &CommandInterpreterQt::clearOutputButtonClick);
	connect(ui.commentButton, &QPushButton::clicked, this, &CommandInterpreterQt::commentButtonClick);
	connect(ui.moveButton, &QPushButton::clicked, this, &CommandInterpreterQt::moveButtonClick);
	connect(ui.pointButton, &QPushButton::clicked, this, &CommandInterpreterQt::pointButtonClick);
	connect(ui.circleButton, &QPushButton::clicked, this, &CommandInterpreterQt::circleButtonClick);
	connect(ui.centerButton, &QPushButton::clicked, this, &CommandInterpreterQt::centerButtonClick);
	connect(ui.planeButton, &QPushButton::clicked, this, &CommandInterpreterQt::planeButtonClick);
	connect(ui.projectionButton, &QPushButton::clicked, this, &CommandInterpreterQt::projectionButtonClick);
	connect(ui.deviationButton, &QPushButton::clicked, this, &CommandInterpreterQt::deviationButtonClick);
}

CommandInterpreterQt::~CommandInterpreterQt()
{
}

void CommandInterpreterQt::throwError(QString command, Errors error)
{
	hasError = true;
	ui.outputConsole->setTextColor(QColor(255, 0, 0));
	if (error == Errors::existingCommand)
		ui.outputConsole->append("A command with this number already exists: " + command);
	else if (error == Errors::nonExistentCommand)
		ui.outputConsole->append("There is not command with this number: " + command);
	else ui.outputConsole->append("Invalid command creation format: " + command);
	ui.outputConsole->setTextColor(QColor(0, 0, 0));
}

void CommandInterpreterQt::runButtonClick()
{
	hasError = false;
	commandsResults.clear();
	sequenceNumber = 0;
	QStringList inputCommands = ui.inputConsole->toPlainText().split("\n").toList();

	for (int i = 0; i < inputCommands.length(); i++) {
		if (inputCommands[i].length() != 0) {
			QString nameCommand = inputCommands[i];
			nameCommand = nameCommand.remove(nameCommand.indexOf("#") + 1, nameCommand.length()).toUpper();
			QString command = inputCommands[i];
			command = command.replace(" ", "").toUpper();

			if (nameCommand == "COMMENT#")
				getCommentResults(command, inputCommands, i);
			else if (nameCommand == "MOVE#")
				getMoveResults(command, inputCommands, i);
			else if (nameCommand == "POINT#")
				getPointResults(command, inputCommands, i);
			else if (nameCommand == "CIRCLE#")
				getCircleResults(command, inputCommands, i);
			else if (nameCommand == "C_POINT#")
				getCenterResults(command, inputCommands, i);
			else if (nameCommand == "PLANE#")
				getPlaneResults(command, inputCommands, i);
			else if (nameCommand == "P_POINT#")
				getProjectionResults(command, inputCommands, i);
			else if (nameCommand == "DEVIATION#")
				getDeviationResults(command, inputCommands, i);
			else throwError(command, Errors::invalidFormat);
		}
	}
	if (numPreviousLine != inputCommands.length() || inputCommands.last().length() != 0) {
		ui.inputConsole->append("");
		numPreviousLine = inputCommands.length() + 1;
	}
	ui.outputConsole->append("");
	commandsHistory.clear();
}

QString CommandInterpreterQt::getNumberCommand(QString command)
{
	QString numCommand = command.remove(0, command.indexOf('#') + 1);
	numCommand = numCommand.remove(numCommand.indexOf('('), numCommand.length());
	return numCommand;
}

bool CommandInterpreterQt::isNumber(QString& numCommand)
{
	for (int i = 0; i < numCommand.length(); i++)
		if (!numCommand[i].isNumber()) return false;
	return true;
}

void CommandInterpreterQt::determineColorAndOutputResult(int r, int g, int b, QString nameCommand, QString result)
{
	ui.outputConsole->setTextColor(QColor(r, g, b));
	ui.outputConsole->append(nameCommand + ": ");
	ui.outputConsole->setTextColor(QColor(0, 0, 0));
	ui.outputConsole->insertPlainText(result);
}

void CommandInterpreterQt::getCommentResults(QString command, QStringList inputCommands, int index)
{
	QString numCommand = getNumberCommand(command);
	if (isNumber(numCommand) && numCommand.length() > 0) {
		QString nameCommand = "COMMENT#" + numCommand;
		if (commandsHistory.contains(nameCommand)) throwError(inputCommands[index], Errors::existingCommand);
		else {
			QString textComment = inputCommands[index];
			textComment = textComment.remove(0, command.indexOf("(") + 1).replace(")", "");
			determineColorAndOutputResult(255, 0, 0, nameCommand, "\n//" + textComment);
			commandsHistory[nameCommand] = "(" + textComment + ")";
		}
	}
	else throwError(inputCommands[index], Errors::invalidFormat);
}

bool CommandInterpreterQt::hasOnlyNumbers(QString command, QString nameCommand)
{
	int numOpenBrackets = command.split('(').length() - 1;
	int numCloseBrackets = command.split(')').length() - 1;
	int numOpenSquareBrackets = command.split('[').length() - 1;
	int numCloseSquareBrackets = command.split(']').length() - 1;
	int sumBrackets = numOpenBrackets + numCloseBrackets + numOpenSquareBrackets + numCloseSquareBrackets;
	int numCommas = command.split(',').length() - 1;
	if (nameCommand.contains("POINT") || nameCommand.contains("CIRCLE"))
		command = command.remove(0, command.indexOf(')'));
	if ((numOpenBrackets == numCloseBrackets || numOpenSquareBrackets == numCloseSquareBrackets)
		&& (sumBrackets == numCommas || (nameCommand.contains("POINT")) && numCommas == 0)
		|| (numCommas == 1 && nameCommand.contains("CIRCLE")))
	{
		QString pathToNumbers = "";
		if (!nameCommand.contains("POINT") && !nameCommand.contains("CIRCLE"))
			pathToNumbers = command.remove(0, command.indexOf('('));
		else pathToNumbers = command;
		pathToNumbers = pathToNumbers.replace("(", "");
		pathToNumbers = pathToNumbers.replace(")", "");
		pathToNumbers = pathToNumbers.replace("[", "");
		pathToNumbers = pathToNumbers.replace("]", "");
		pathToNumbers = pathToNumbers.replace(" ", "");
		pathToNumbers = pathToNumbers.replace(".", "");
		pathToNumbers = pathToNumbers.replace("-", "");
		QStringList coordinates = pathToNumbers.split(",");

		for (int i = 0; i < coordinates.length(); i++)
			if (coordinates[i].length() == 0)
				return false;
		pathToNumbers = pathToNumbers.replace(",", "");

		if (isNumber(pathToNumbers) && pathToNumbers.length() > 0)
			return true;
	}
	return false;
}

void CommandInterpreterQt::getMoveResults(QString command, QStringList inputCommands, int index)
{
	QString numCommand = getNumberCommand(command);
	if (isNumber(numCommand) && numCommand.length() > 0) {
		QString nameCommand = "MOVE#" + numCommand;
		if (commandsHistory.contains(nameCommand)) throwError(inputCommands[index], Errors::existingCommand);
		else if (hasOnlyNumbers(command, "")) {
			QString dataCommand = command;
			dataCommand = dataCommand.remove(0, command.indexOf("("));
			determineColorAndOutputResult(0, 255, 0, nameCommand, mMachine->move(dataCommand));
			commandsHistory[nameCommand] = dataCommand;
		}
		else throwError(inputCommands[index], Errors::invalidFormat);
	}
	else throwError(inputCommands[index], Errors::invalidFormat);
}

bool CommandInterpreterQt::isVectorCorrect(QString command, QString nameCommand)
{
	QString vector = command;
	vector = vector.remove(0, command.indexOf("[") + 1);
	vector = vector.replace("]", "");
	QStringList coordVector = vector.split(',');
	if (coordVector.length() == 3 && coordVector[0].length() > 0 && coordVector[1].length() > 0
		&& coordVector[2].length() > 0 && hasOnlyNumbers(command, nameCommand))
		return true;
	return false;
}

void CommandInterpreterQt::getPointResults(QString command, QStringList inputCommands, int index)
{
	QString numCommand = getNumberCommand(command);
	if (isNumber(numCommand) && numCommand.length() > 0) {
		QString nameCommand = "POINT#" + numCommand;
		if (commandsHistory.contains(nameCommand)) throwError(inputCommands[index], Errors::existingCommand);
		else if (hasOnlyNumbers(command, "") && isVectorCorrect(command, nameCommand)) {
			QString dataCommand = command;
			dataCommand = dataCommand.remove(0, command.indexOf("("));
			tuple resultCommand = mMachine->point(dataCommand, 0.0125);
			determineColorAndOutputResult(0, 255, 0, nameCommand, "\n" + get<0>(resultCommand));
			commandsHistory[nameCommand] = dataCommand;
			commandsResults[sequenceNumber][nameCommand] = get<0>(resultCommand);
			sequenceNumber++;
		}
		else throwError(inputCommands[index], Errors::invalidFormat);
	}
	else throwError(inputCommands[index], Errors::invalidFormat);
}

void CommandInterpreterQt::getCircleResults(QString command, QStringList inputCommands, int index)
{
	QString numCommand = getNumberCommand(command);
	if (isNumber(numCommand) && numCommand.length() > 0) {
		QString nameCommand = "CIRCLE#" + numCommand;
		if (commandsHistory.contains(nameCommand)) throwError(inputCommands[index], Errors::existingCommand);
		else {
			QStringList points = command.split('(');
			points.removeFirst();
			bool isAllContainsCircle = true;
			for (int j = 0; j < points.length(); j++) {
				points[j] = points[j].replace(")", "").toUpper();
				if (!commandsHistory.contains(points[j])) {
					isAllContainsCircle = false;
					throwError(points[j], Errors::nonExistentCommand);
				}
			}
			if (isAllContainsCircle) {
				QString firstPoint = commandsHistory[points[0]];
				QString secondPoint = commandsHistory[points[1]];
				QString thirdPoint = commandsHistory[points[2]];
				commandsHistory[nameCommand] = firstPoint + secondPoint + thirdPoint;

				tuple resultCommand = mMachine->circle(commandsHistory[nameCommand], points, 0.0125, 0.0125);
				tuple dataCenterCicle = make_tuple(get<1>(resultCommand), get<2>(resultCommand), get<3>(resultCommand));

				circleResults[nameCommand] = dataCenterCicle;
				determineColorAndOutputResult(255, 170, 0, nameCommand, get<0>(resultCommand));
				commandsResults[sequenceNumber][nameCommand] = get<0>(resultCommand);
				sequenceNumber++;
			}
		}
	}
	else throwError(inputCommands[index], Errors::invalidFormat);
}

void CommandInterpreterQt::getCenterResults(QString command, QStringList inputCommands, int index)
{
	QString numCommand = getNumberCommand(command);
	if (isNumber(numCommand) && numCommand.length() > 0) {
		QString nameCommand = "C_POINT#" + numCommand;
		if (commandsHistory.contains(nameCommand)) throwError(inputCommands[index], Errors::existingCommand);
		else {
			QString nameCircle = command.split("(")[1].replace(")", "").toUpper();
			if (commandsHistory.contains(nameCircle)) {
				tuple dataCenter = mMachine->center(circleResults[nameCircle]);
				determineColorAndOutputResult(255, 170, 0, nameCommand, "\n" + get<0>(dataCenter));
				commandsHistory[nameCommand] = get<1>(dataCenter);
				commandsResults[sequenceNumber][nameCommand] = get<0>(dataCenter);
				sequenceNumber++;
			}
			else throwError(nameCircle, Errors::nonExistentCommand);
		}
	}
	else throwError(inputCommands[index], Errors::invalidFormat);
}

void CommandInterpreterQt::getPlaneResults(QString command, QStringList inputCommands, int index)
{
	QString numCommand = getNumberCommand(command);
	if (isNumber(numCommand) && numCommand.length() > 0) {
		QString nameCommand = "PLANE#" + numCommand;
		if (commandsHistory.contains(nameCommand)) throwError(inputCommands[index], Errors::existingCommand);
		else {
			QStringList points = command.split('(');
			points.removeFirst();
			bool isAllContainsPlane = true;
			for (int j = 0; j < points.length(); j++) {
				points[j] = points[j].replace(")", "").toUpper();
				if (!commandsHistory.contains(points[j])) {
					isAllContainsPlane = false;
					throwError(points[j], Errors::nonExistentCommand);
				}
			}
			if (isAllContainsPlane) {
				QString firstPoint = commandsHistory[points[0]];
				QString secondPoint = commandsHistory[points[1]];
				QString thirdPoint = commandsHistory[points[2]];
				commandsHistory[nameCommand] = firstPoint + secondPoint + thirdPoint;

				tuple resultCommand = mMachine->plane(commandsHistory[nameCommand], points);
				tuple norVectorAndPoint = make_tuple(get<1>(resultCommand), get<2>(resultCommand));
				planeResults[nameCommand] = norVectorAndPoint;
				determineColorAndOutputResult(255, 170, 0, nameCommand, get<0>(resultCommand));
				commandsResults[sequenceNumber][nameCommand] = get<0>(resultCommand);
				sequenceNumber++;
			}
		}
	}
	else throwError(inputCommands[index], Errors::invalidFormat);
}

void CommandInterpreterQt::getProjectionResults(QString command, QStringList inputCommands, int index)
{
	QString numCommand = getNumberCommand(command);
	if (isNumber(numCommand) && numCommand.length() > 0) {
		QString nameCommand = "P_POINT#" + numCommand;
		if (commandsHistory.contains(nameCommand)) throwError(inputCommands[index], Errors::existingCommand);
		else {
			QString namePlane = command.split("(")[1];
			namePlane = namePlane.remove(namePlane.indexOf(")"), namePlane.length()).toUpper();
			QString namePoint = command.split("[")[1].replace("]", "").toUpper();
			if (!commandsHistory.contains(namePoint)) throwError(namePoint, Errors::nonExistentCommand);
			else if (commandsHistory.contains(namePlane)) {
				tuple dataProjoction = mMachine->projectionPoint(commandsHistory[namePoint],
					get<0>(planeResults[namePlane]), get<1>(planeResults[namePlane]));
				determineColorAndOutputResult(255, 170, 0, nameCommand, "\n" + get<0>(dataProjoction));
				commandsHistory[nameCommand] = get<1>(dataProjoction);
				commandsResults[sequenceNumber][nameCommand] = get<0>(dataProjoction);
				sequenceNumber++;
			}
			else throwError(namePlane, Errors::nonExistentCommand);
		}
	}
	else throwError(inputCommands[index], Errors::invalidFormat);
}

bool CommandInterpreterQt::isDeviationCorrect(QString nameCommand, QString strDeviation)
{
	if (nameCommand.contains("POINT")) {
		double pointDeviation = 0.0;
		if (strDeviation.length() > 0) {
			try {
				pointDeviation = strDeviation.toDouble();
			}
			catch (...) {
				return false;
			}
			if (pointDeviation < 0) return false;
			return true;
		}
	}
	else {
		QStringList deviations = strDeviation.split(",");
		double centerDeviation = 0.0;
		double radiusDeviation = 0.0;
		if (deviations[0].length() > 0 && deviations[1].length() > 0) {
			try {
				centerDeviation = deviations[0].toDouble();
				radiusDeviation = deviations[1].toDouble();
			}
			catch (...) {
				return false;
			}
		}
		if (centerDeviation < 0 || radiusDeviation < 0) return false;
		return true;
	}
	return true;
}

void CommandInterpreterQt::getDeviationResults(QString command, QStringList inputCommands, int index)
{
	QString numCommand = getNumberCommand(command);
	if (isNumber(numCommand) && numCommand.length() > 0) {
		QString nameCommand = "DEVIATION#" + numCommand;
		if (commandsHistory.contains(nameCommand)) throwError(inputCommands[index], Errors::existingCommand);
		else {
			QString key = command.remove(0, command.indexOf('(') + 1);
			QString deviation = key;
			deviation = deviation.remove(0, key.indexOf("["));
			key = key.remove(key.indexOf('['), key.length());
			key = key.replace(")", "").toUpper();
			if (!commandsHistory.contains(key)) throwError(key, Errors::nonExistentCommand);
			else {
				QString newValue = commandsHistory[key];
				newValue = newValue.replace("(", "");
				if (key.contains("POINT#")) newValue = newValue.remove(newValue.indexOf(")"), newValue.length());
				newValue += deviation;
				if (isDeviationCorrect(key, deviation))
				{
					QString commandResult = mMachine->deviation(key, commandsHistory[key], deviation);
					determineColorAndOutputResult(0, 0, 255, nameCommand, commandResult);
					commandsHistory[nameCommand] = commandResult;
					commandsResults[sequenceNumber][nameCommand] = commandResult;
					sequenceNumber++;
				}
				else throwError(inputCommands[index], Errors::invalidFormat);
			}
		}
	}
	else throwError(inputCommands[index], Errors::invalidFormat);
}

void CommandInterpreterQt::saveFileButtonClick()
{
	QString filePath = QFileDialog::getSaveFileName(nullptr, "Save file", "", "(*.txt)");

	if (!filePath.isEmpty()) {
		QFile file(filePath);
		if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
			QString data = ui.inputConsole->toPlainText();
			QTextStream out(&file);
			out << data;
			file.close();
		}
	}
}

void CommandInterpreterQt::openFileButtonClick()
{
	QString filePath = QFileDialog::getOpenFileName(nullptr, "Open file", "", "(*.txt)");

	if (!filePath.isEmpty()) {
		QFile file(filePath);
		if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
			QTextStream in(&file);
			QString data = in.readAll();
			file.close();
			ui.inputConsole->setPlainText(data);
		}
	}
}

void CommandInterpreterQt::getReportButtonClick()
{
	if (!hasError) {
		QString filePath = QFileDialog::getSaveFileName(nullptr, "Save file", "", "(*.html)");

		if (!filePath.isEmpty()) {
			QFile file(filePath);
			QFileInfo fileInfo(file.fileName());
			QString fileName(fileInfo.fileName());
			if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
				QTextEdit data;
				QHash s = commandsResults[0];
				QString v = s.keys()[0];
				data.setText(report->createReport(commandsResults, fileName));
				QTextStream out(&file);
				out << data.toHtml();
				file.close();
			}
		}
	}
	else {
		QMessageBox::information(
			this,
			tr("Error message"),
			tr("An error occurred while executing the commands.Check the output."));
	}
}

void CommandInterpreterQt::clearInputButtonClick()
{
	ui.inputConsole->setText("");
	numPreviousLine = 0;
	circleResults.clear();
	planeResults.clear();
}

void CommandInterpreterQt::clearOutputButtonClick()
{
	ui.outputConsole->setText("");
	numPreviousLine = 0;
	circleResults.clear();
	planeResults.clear();
	commandsResults.clear();
	sequenceNumber = 0;
}

void CommandInterpreterQt::processButtonClick(QString nameCommand)
{
	if (ui.inputConsole->toPlainText().length() == 0)
		ui.inputConsole->insertPlainText(nameCommand);
	else if (ui.inputConsole->toPlainText().split("\n").last().length() == 0) {
		QString text = ui.inputConsole->toPlainText();
		QStringList lines = text.split("\n");
		lines.removeLast();
		ui.inputConsole->setPlainText(lines.join("\n"));
		ui.inputConsole->append(nameCommand);
	}
}

void CommandInterpreterQt::commentButtonClick()
{
	processButtonClick("COMMENT#()");
}

void CommandInterpreterQt::moveButtonClick()
{
	processButtonClick("MOVE#()");
}

void CommandInterpreterQt::pointButtonClick()
{
	processButtonClick("POINT#()[1, 0, 0]");
}

void CommandInterpreterQt::circleButtonClick()
{
	processButtonClick("CIRCLE#()()()");
}

void CommandInterpreterQt::centerButtonClick()
{
	processButtonClick("C_POINT#()");
}

void CommandInterpreterQt::planeButtonClick()
{
	processButtonClick("PLANE#()()()");
}

void CommandInterpreterQt::projectionButtonClick()
{
	processButtonClick("P_POINT#()[]");
}

void CommandInterpreterQt::deviationButtonClick()
{
	processButtonClick("DEVIATION#()[]");
}



