#include "CommandInterpreterQt.h"

CommandInterpreterQt::CommandInterpreterQt(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	numPreviousLine = 0;
	numberOfClicks = 0;
	hasError = false;

	connect(ui.runButton, &QPushButton::clicked, this, &CommandInterpreterQt::runButtonClick);
	connect(ui.debugButton, &QPushButton::clicked, this, &CommandInterpreterQt::debugButtonClick);
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

CommandInterpreterQt::~CommandInterpreterQt() {}

void CommandInterpreterQt::throwError(const QString& command, Errors error)
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

void CommandInterpreterQt::callCommmand(const QStringList& inputCommands, int index)
{
	QString nameCommand = inputCommands[index];
	nameCommand = nameCommand.remove(nameCommand.indexOf("#") + 1, nameCommand.length()).toUpper();
	QString command = inputCommands[index];
	command = command.replace(" ", "").toUpper();

	if (nameCommand == "COMMENT#")
		getCommentResults(command, inputCommands, index);
	else if (nameCommand == "MOVE#")
		getMoveResults(command, inputCommands, index);
	else if (nameCommand == "POINT#")
		getPointResults(command, inputCommands, index);
	else if (nameCommand == "CIRCLE#")
		getCircleResults(command, inputCommands, index);
	else if (nameCommand == "C_POINT#")
		getCenterResults(command, inputCommands, index);
	else if (nameCommand == "PLANE#")
		getPlaneResults(command, inputCommands, index);
	else if (nameCommand == "P_POINT#")
		getProjectionResults(command, inputCommands, index);
	else if (nameCommand == "DEVIATION#")
		getDeviationResults(command, inputCommands, index);
	else throwError(command, Errors::invalidFormat);
}

void CommandInterpreterQt::runButtonClick() {
	QStringList inputCommands = ui.inputConsole->toPlainText().split("\n");
	inputCommands.removeAll(QString());
	if (numberOfClicks == 0) {
		hasError = false;
		listForReport.clear();
	}
	else if (numberOfClicks >= inputCommands.length() - 1) {
		numberOfClicks = 0;
		commandsHistory.clear();
		ui.outputConsole->append("");
	}

	if (inputCommands.length() > 0) {
		for (int i = numberOfClicks; i < inputCommands.length(); i++)
			callCommmand(inputCommands, i);

		if (numPreviousLine != inputCommands.length()) {
			ui.inputConsole->append("");
			numPreviousLine = inputCommands.length();
		}
		ui.outputConsole->append("");
		commandsHistory.clear();
		numberOfClicks = 0;
	}
}

void CommandInterpreterQt::debugButtonClick() {
	QStringList inputCommands = ui.inputConsole->toPlainText().split("\n");
	inputCommands.removeAll(QString());

	if (numberOfClicks == 0) {
		hasError = false;
		listForReport.clear();
	}

	if (numberOfClicks < inputCommands.length() && inputCommands.length() > 0) {
		callCommmand(inputCommands, numberOfClicks);
		numberOfClicks++;
	}
	else {
		commandsHistory.clear();
		if (numPreviousLine != inputCommands.length() || inputCommands.last().length() != 0) {
			ui.inputConsole->append("");
			numPreviousLine = inputCommands.length() + 1;
		}
		ui.outputConsole->append("");
		numberOfClicks = 0;
	}
}

QString CommandInterpreterQt::getNumberCommand(QString command) {
	QString numCommand = command.remove(0, command.indexOf('#') + 1);
	numCommand = numCommand.remove(numCommand.indexOf('('), numCommand.length());
	return numCommand;
}

bool CommandInterpreterQt::isNumber(const QString& numCommand) {
	for (int i = 0; i < numCommand.length(); i++)
		if (!numCommand[i].isNumber()) return false;
	return true;
}

void CommandInterpreterQt::determineColorAndOutputResult(shared_ptr<Command> command) {
	ui.outputConsole->setTextColor(command->color());
	ui.outputConsole->append(command->name() + ": ");
	ui.outputConsole->setTextColor(QColor(0, 0, 0));
	ui.outputConsole->insertPlainText(command->generateTextForOutput());
}

void CommandInterpreterQt::getCommentResults(QString& command, const QStringList& inputCommands, int index) {
	QString numCommand = getNumberCommand(command);
	if (isNumber(numCommand) && numCommand.length() > 0) {
		QString nameCommand = "COMMENT#" + numCommand;
		if (commandsHistory.contains(nameCommand)) throwError(inputCommands[index], Errors::existingCommand);
		else {
			QString textComment = inputCommands[index];
			textComment = textComment.remove(0, textComment.indexOf("(") + 1).replace(")", "");
			auto commentCommand = shared_ptr<Command>(new CommentCommand(nameCommand, textComment));
			determineColorAndOutputResult(commentCommand);
			commandsHistory[nameCommand] = commentCommand;
		}
	}
	else throwError(inputCommands[index], Errors::invalidFormat);
}

bool CommandInterpreterQt::hasOnlyNumbers(QString command, const QString& nameCommand) {
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

void CommandInterpreterQt::getMoveResults(QString& command, const QStringList& inputCommands, int index) {
	QString numCommand = getNumberCommand(command);
	if (isNumber(numCommand) && numCommand.length() > 0) {
		QString nameCommand = "MOVE#" + numCommand;
		if (commandsHistory.contains(nameCommand)) throwError(inputCommands[index], Errors::existingCommand);
		else if (hasOnlyNumbers(command, "")) {
			QString dataCommand = command;
			dataCommand = dataCommand.remove(0, command.indexOf("("));
			dataCommand = dataCommand.replace("(", "").replace(")", "");

			QStringList strCoordinates = dataCommand.split(",");
			Coordinates coords;

			for (int i = 0; i < strCoordinates.length(); i++) {
				double coordinate = strCoordinates[i].toDouble();
				coords.setValue(i, coordinate);
			}

			auto moveCommand = shared_ptr<Command>(new MoveCommand(nameCommand, coords));
			determineColorAndOutputResult(moveCommand);
			commandsHistory[nameCommand] = moveCommand;
		}
		else throwError(inputCommands[index], Errors::invalidFormat);
	}
	else throwError(inputCommands[index], Errors::invalidFormat);
}

bool CommandInterpreterQt::isVectorCorrect(QString& command, const QString& nameCommand) {
	QString vector = command;
	vector = vector.remove(0, command.indexOf("[") + 1);
	vector = vector.replace("]", "");
	QStringList coordVector = vector.split(',');
	if (coordVector.length() == 3 && coordVector[0].length() > 0 && coordVector[1].length() > 0
		&& coordVector[2].length() > 0 && hasOnlyNumbers(command, nameCommand))
		return true;
	return false;
}

void CommandInterpreterQt::getPointResults(QString& command, const QStringList& inputCommands, int index) {
	QString numCommand = getNumberCommand(command);
	if (isNumber(numCommand) && numCommand.length() > 0) {
		QString nameCommand = "POINT#" + numCommand;
		if (commandsHistory.contains(nameCommand)) throwError(inputCommands[index], Errors::existingCommand);
		else if (hasOnlyNumbers(command, "") && isVectorCorrect(command, nameCommand)) {
			QString dataCommand = command;
			dataCommand = dataCommand.remove(0, command.indexOf("("));
			dataCommand = dataCommand.replace("(", "").replace(")", "");
			QString strNorVector = dataCommand;
			strNorVector = strNorVector.remove(0, strNorVector.indexOf('[') + 1).replace("]", "");
			QStringList coordNormalVector = strNorVector.split(',');
			dataCommand = dataCommand.remove(dataCommand.indexOf('['), dataCommand.length());
			QStringList strNomPoint = dataCommand.split(',');
			Coordinates nominalPoint;
			Coordinates normalVector;

			for (int i = 0; i < 3; i++) {
				nominalPoint.setValue(i, strNomPoint[i].toDouble());
				normalVector.setValue(i, coordNormalVector[i].toDouble());
			}

			auto pointCommand = shared_ptr<Command>(new PointCommand(nameCommand, nominalPoint, normalVector));
			pointCommand->process();
			determineColorAndOutputResult(pointCommand);
			commandsHistory[nameCommand] = pointCommand;
			listForReport.append(pointCommand);
		}
		else throwError(inputCommands[index], Errors::invalidFormat);
	}
	else throwError(inputCommands[index], Errors::invalidFormat);
}

void CommandInterpreterQt::getCircleResults(QString& command, const QStringList& inputCommands, int index) {
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
				QList<PointCommand*> pointsCircle = {
					dynamic_cast<PointCommand*>(commandsHistory[points[0]].get()),
					dynamic_cast<PointCommand*>(commandsHistory[points[1]].get()),
					dynamic_cast<PointCommand*>(commandsHistory[points[2]].get())
				};
				auto circleCommand = shared_ptr<Command>(new CircleCommand(nameCommand, pointsCircle));
				circleCommand->process();
				determineColorAndOutputResult(circleCommand);
				commandsHistory[nameCommand] = circleCommand;
				listForReport.append(circleCommand);
			}
		}
	}
	else throwError(inputCommands[index], Errors::invalidFormat);
}

void CommandInterpreterQt::getCenterResults(QString& command, const QStringList& inputCommands, int index)
{
	QString numCommand = getNumberCommand(command);
	if (isNumber(numCommand) && numCommand.length() > 0) {
		QString nameCommand = "C_POINT#" + numCommand;
		if (commandsHistory.contains(nameCommand)) throwError(inputCommands[index], Errors::existingCommand);
		else {
			QString nameCircle = command.split("(")[1].replace(")", "").toUpper();
			if (commandsHistory.contains(nameCircle)) {
				auto circleCommand = dynamic_cast<CircleCommand*>(commandsHistory[nameCircle].get());
				auto centerCommand = shared_ptr<Command>(new CenterCommand(nameCommand, circleCommand->get_nomCenter(), circleCommand->get_nomNormal()));
				centerCommand->process();
				determineColorAndOutputResult(centerCommand);
				commandsHistory[nameCommand] = centerCommand;
				listForReport.append(centerCommand);
			}
			else throwError(nameCircle, Errors::nonExistentCommand);
		}
	}
	else throwError(inputCommands[index], Errors::invalidFormat);
}

void CommandInterpreterQt::getPlaneResults(QString& command, const QStringList& inputCommands, int index)
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
				QList<PointCommand*> pointsPlane = {
					dynamic_cast<PointCommand*>(commandsHistory[points[0]].get()),
					dynamic_cast<PointCommand*>(commandsHistory[points[1]].get()),
					dynamic_cast<PointCommand*>(commandsHistory[points[2]].get())
				};
				auto planeCommand = shared_ptr<Command>(new PlaneCommand(nameCommand, pointsPlane));
				planeCommand->process();
				determineColorAndOutputResult(planeCommand);
				commandsHistory[nameCommand] = planeCommand;
				listForReport.append(planeCommand);
			}
		}
	}
	else throwError(inputCommands[index], Errors::invalidFormat);
}

void CommandInterpreterQt::getProjectionResults(QString& command, const QStringList& inputCommands, int index) {
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
				auto planeCommand = dynamic_cast<PlaneCommand*>(commandsHistory[namePlane].get());
				auto normalVector = planeCommand->get_nomNormal();
				auto pointPlane = planeCommand->get_nomMidPoint();
				auto pointCommand = dynamic_cast<PointCommand*>(commandsHistory[namePoint].get());
				auto nomProjPoint = MeasureMachine::getProjectionPoint(pointCommand->get_nomPoint(), normalVector, pointPlane);

				auto projectionCommand = shared_ptr<Command>(new ProjectionCommand(nameCommand, nomProjPoint, normalVector));
				projectionCommand->process();
				determineColorAndOutputResult(projectionCommand);
				commandsHistory[nameCommand] = projectionCommand;
				listForReport.append(projectionCommand);
			}
			else throwError(namePlane, Errors::nonExistentCommand);
		}
	}
	else throwError(inputCommands[index], Errors::invalidFormat);
}

bool CommandInterpreterQt::isDeviationCorrect(const QString& nameCommand, QString strDeviation) {
	strDeviation = strDeviation.removeFirst().removeLast();

	if (nameCommand.contains("POINT")) {
		if (strDeviation.split(".").length() - 1 == 1 && strDeviation.split(",").length() == 1) {
			strDeviation = strDeviation.replace(".", "");
			double pointDeviation = 0.0;
			if (strDeviation.length() > 0 && isNumber(strDeviation)) {
				pointDeviation = strDeviation.toDouble();
				if (pointDeviation > 0) return true;
			}
		}
		return false;
	}
	else {
		if (strDeviation.split(".").length() - 1 == 2 && strDeviation.split(",").length() == 2) {
			strDeviation = strDeviation.replace(".", "");
			QStringList deviations = strDeviation.split(",");
			double centerDeviation = 0.0;
			double radiusDeviation = 0.0;
			if (deviations[0].length() > 0 && deviations[1].length() > 0
				&& isNumber(deviations[0]) && isNumber(deviations[1])) {
				centerDeviation = deviations[0].toDouble();
				radiusDeviation = deviations[1].toDouble();
				if (centerDeviation >= 0 || radiusDeviation >= 0) return true;
			}
		}
		return false;
	}
}

void CommandInterpreterQt::getDeviationResults(QString& command, const QStringList& inputCommands, int index) {
	QString numCommand = getNumberCommand(command);
	if (isNumber(numCommand) && numCommand.length() > 0) {
		QString nameCommand = "DEVIATION#" + numCommand;
		if (commandsHistory.contains(nameCommand)) throwError(inputCommands[index], Errors::existingCommand);
		else {
			QString name = command.remove(0, command.indexOf('(') + 1);
			QString strDeviation = name;
			strDeviation = strDeviation.remove(0, strDeviation.indexOf("[") + 1).replace("]", "");
			name = name.remove(name.indexOf('['), name.length());
			name = name.replace(")", "").toUpper();
			if (!commandsHistory.contains(name)) throwError(name, Errors::nonExistentCommand);
			else if (isDeviationCorrect(name, strDeviation)) {
				if (command.contains("POINT#")) {
					auto pointCommand = dynamic_cast<PointCommand*>(commandsHistory[name].get());
					auto pDeviationCommand = shared_ptr<Command>(new PDeviationCommand(nameCommand, pointCommand, strDeviation.toDouble()));
					pDeviationCommand->process();
					determineColorAndOutputResult(pDeviationCommand);
					commandsHistory[nameCommand] = pDeviationCommand;
					listForReport.append(pDeviationCommand);
				}
				else {
					auto circleCommand = dynamic_cast<CircleCommand*>(commandsHistory[name].get());
					auto deviations = strDeviation.split(",");
					auto cDeviationCommand = shared_ptr<Command>(new CDeviationCommand(nameCommand, circleCommand, deviations[0].toDouble(), deviations[1].toDouble()));
					cDeviationCommand->process();
				    listForReport.append(cDeviationCommand);
					determineColorAndOutputResult(cDeviationCommand);
					commandsHistory[nameCommand] = cDeviationCommand;
				}
			}
			else throwError(inputCommands[index], Errors::invalidFormat);
		}
	}
	else throwError(inputCommands[index], Errors::invalidFormat);
}

void CommandInterpreterQt::saveFileButtonClick() {
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

void CommandInterpreterQt::openFileButtonClick() {
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

void CommandInterpreterQt::getReportButtonClick() {
	if (!hasError) {
		QString filePath = QFileDialog::getSaveFileName(nullptr, "Save file", "", "(*.html)");

		if (!filePath.isEmpty()) {
			QFile file(filePath);
			QFileInfo fileInfo(file.fileName());
			QString fileName(fileInfo.fileName());
			if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
				fileName = fileName.remove(fileName.indexOf("."), fileName.length());
				QString report = "<h1>Name of the report: " + fileName + "</h1>";

				for (auto& command : listForReport) {
					report += command->generateTextForReport();
				}

				QTextEdit data;
				data.setText(report);
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
			tr("An error occurred while executing the commands. Check the output."));
	}
}

void CommandInterpreterQt::clearInputButtonClick() {
	ui.inputConsole->setText("");
	numPreviousLine = 0;
	numberOfClicks = 0;
}

void CommandInterpreterQt::clearOutputButtonClick() {
	ui.outputConsole->setText("");
	numPreviousLine = 0;
	commandsHistory.clear();
	listForReport.clear();
	numberOfClicks = 0;
}

void CommandInterpreterQt::processButtonClick(const QString& nameCommand) {
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

void CommandInterpreterQt::commentButtonClick() {
	processButtonClick("COMMENT#()");
}

void CommandInterpreterQt::moveButtonClick() {
	processButtonClick("MOVE#()");
}

void CommandInterpreterQt::pointButtonClick() {
	processButtonClick("POINT#()[1, 0, 0]");
}

void CommandInterpreterQt::circleButtonClick() {
	processButtonClick("CIRCLE#()()()");
}

void CommandInterpreterQt::centerButtonClick() {
	processButtonClick("C_POINT#()");
}

void CommandInterpreterQt::planeButtonClick() {
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



