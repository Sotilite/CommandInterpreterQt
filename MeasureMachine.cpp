#include "MeasureMachine.h"

using namespace std;

MeasureMachine::MeasureMachine(QObject* parent)
	: QObject(parent)
{}

MeasureMachine::~MeasureMachine()
{}

QString MeasureMachine::move(QString dataCommand)
{
	dataCommand = dataCommand.replace("(", "");
	dataCommand = dataCommand.replace(")", "");
	QStringList strCoordinates = dataCommand.split(",");
	double coordinates[3]{};
	QString result = "(%1, %2, %3)";

	for (int i = 0; i < strCoordinates.length(); i++) {
		double coordinate = strCoordinates[i].toDouble();
		coordinates[i] = coordinate;
	}
	return result.arg(QString::number(coordinates[0], 'f', 4))
		.arg(QString::number(coordinates[1], 'f', 4))
		.arg(QString::number(coordinates[2], 'f', 4));
}

double* MeasureMachine::getCoordinatePoint(QString point, double deviation = 0.0125)
{
	srand(time(0));
	QStringList rawCoordinates = point.split(',');
	double* treatedCoordinates = new double[3];
	int precision = 4;
	int bound = (int)(deviation * pow(10, precision));
	int number = 10000;
	for (int i = 0; i < rawCoordinates.length(); i++)
	{
		QString coordinate = rawCoordinates[i].replace(" ", "");
		double k = pow(10, -precision);
		int rand = QRandomGenerator::global()->bounded(100);
		double randomNumber = bound != 0 ? (rand % (2 * bound + 1) - bound) * k : 0;
		double value = coordinate.toDouble() + randomNumber;
		treatedCoordinates[i] = floor(value * number) / number;
	}
	return treatedCoordinates;
}

tuple<QString, QString> MeasureMachine::point(QString dataCommand, double pointDeviation)
{
	dataCommand = dataCommand.replace("(", "");
	dataCommand = dataCommand.replace(")", "");
	QString strNorVector = dataCommand;
	strNorVector = strNorVector.remove(0, strNorVector.indexOf('[') + 1);
	strNorVector = strNorVector.replace("]", "");
	QStringList coordNormalVector = strNorVector.split(',');
	dataCommand = dataCommand.remove(dataCommand.indexOf('['), dataCommand.length());
	QStringList strNomPoint = dataCommand.split(',');
	double nominalPoint[3]{};
	double normalVector[3]{};
	double sumOfSquares = 0.0;
	double* actualPoint = getCoordinatePoint(dataCommand, pointDeviation);

	for (int i = 0; i < 3; i++)
	{
		nominalPoint[i] = strNomPoint[i].toDouble();
		normalVector[i] = coordNormalVector[i].toDouble();
		sumOfSquares += (nominalPoint[i] - actualPoint[i]) * (nominalPoint[i] - actualPoint[i]);
	}

	double distance = sqrt(sumOfSquares);
	QString result = "Nominal: (%1, %2, %3)[%4, %5, %6]\nActual: (%7, %8, %9)";

	return make_tuple(result.arg(QString::number(nominalPoint[0], 'f', 4)).arg(QString::number(nominalPoint[1], 'f', 4))
		.arg(QString::number(nominalPoint[2], 'f', 4)).arg(QString::number(normalVector[0], 'f', 4))
		.arg(QString::number(normalVector[1], 'f', 4)).arg(QString::number(normalVector[2], 'f', 4))
		.arg(QString::number(actualPoint[0], 'f', 4)).arg(QString::number(actualPoint[1], 'f', 4))
		.arg(QString::number(actualPoint[2], 'f', 4)), QString::number(distance, 'f', 4));
}

double* MeasureMachine::getNormalVector(double* firstPoint, double* secondPoint, double* thirdPoint)
{
	double firstVector[3]{};
	double secondVector[3]{};
	double* normalVector = new double[3];

	for (int i = 0; i < 3; i++)
	{
		firstVector[i] = secondPoint[i] - firstPoint[i];
		secondVector[i] = thirdPoint[i] - firstPoint[i];
	}

	normalVector[0] = firstVector[1] * secondVector[2] - firstVector[2] * secondVector[1];
	normalVector[1] = -(firstVector[0] * secondVector[2] - firstVector[2] * secondVector[0]);
	normalVector[2] = firstVector[0] * secondVector[1] - firstVector[1] * secondVector[0];


	double lenNorVector = sqrt(normalVector[0] * normalVector[0] + normalVector[1] * normalVector[1] +
		normalVector[2] * normalVector[2]);

	for (int i = 0; i < 3; i++) normalVector[i] = normalVector[i] / lenNorVector;

	double n21 = normalVector[0];
	double n22 = normalVector[1];
	double n23 = normalVector[2];
	return normalVector;
}

double* MeasureMachine::getCoefficientEquation(double* point)
{
	double* coefficientsEquat = new double[4];

	for (int i = 0; i < 3; i++)
		coefficientsEquat[i] = 2 * point[i];
	coefficientsEquat[3] = point[0] * point[0] + point[1] * point[1] + point[2] * point[2];

	return coefficientsEquat;
}

double MeasureMachine::getValueDeterminant(int i, int j, int k,
	double* coefFirstEquat, double* coefSecondEquat, double* coefThirdEquat)
{
	double determinant = coefFirstEquat[i] * coefSecondEquat[j] * coefThirdEquat[k] +
		coefFirstEquat[j] * coefSecondEquat[k] * coefThirdEquat[i] +
		coefFirstEquat[k] * coefSecondEquat[i] * coefThirdEquat[j] -
		(coefFirstEquat[k] * coefSecondEquat[j] * coefThirdEquat[i] +
			coefFirstEquat[i] * coefSecondEquat[k] * coefThirdEquat[j] +
			coefFirstEquat[j] * coefSecondEquat[i] * coefThirdEquat[k]);

	return determinant;
}

double* MeasureMachine::getNewNormalVector(double* normalVector, double* firstPoint,
	double* fourthPoint, double sidesSquareNorVec)
{
	double firstScalarProduct = 0.0;
	double secondScalarProduct = 0.0;

	for (int i = 0; i < 3; i++)
	{
		firstScalarProduct += normalVector[i] * fourthPoint[i];
		secondScalarProduct += normalVector[i] * firstPoint[i];
	}

	double k = (firstScalarProduct - secondScalarProduct) / sidesSquareNorVec;
	double* newNormalVector = new double[3];

	for (int i = 0; i < 3; i++)
		newNormalVector[i] = k * normalVector[i];

	return newNormalVector;
}

double* MeasureMachine::getCenterPoint(double* firstPoint, double* secondPoint, double* thirdPoint)
{
	//Находим нормальный вектор
	double* normalVector = getNormalVector(firstPoint, secondPoint, thirdPoint);
	double sidesSquareNorVec = normalVector[0] * normalVector[0] +
		normalVector[1] * normalVector[1] + normalVector[2] * normalVector[2];

	//Находим коэфициенты уравнений
	double* coefFirstEquat = getCoefficientEquation(firstPoint);
	double* coefSecondEquat = getCoefficientEquation(secondPoint);
	double* coefThirdEquat = getCoefficientEquation(thirdPoint);
	double generalDeterminant = getValueDeterminant(0, 1, 2, coefFirstEquat, coefSecondEquat, coefThirdEquat);
	double x = 0.0;
	if (generalDeterminant == 0)
	{
		int joinArray[12]{};
		for (int i = 0; i < 4; i++) {
			joinArray[3 * i] = coefFirstEquat[i];
			joinArray[1 + 3 * i] = coefSecondEquat[i];
			joinArray[2 + 3 * i] = coefThirdEquat[i];
		}
		int minNumber = joinArray[0];
		for (int i = 0; i < 12; i++) if (minNumber > joinArray[i]) minNumber = joinArray[i];

		x = -minNumber + 1;
		for (int i = 0; i < 3; i++)
		{
			coefFirstEquat[i] += x;
			coefSecondEquat[i] += x;
			coefThirdEquat[i] += x;
		}
		generalDeterminant = getValueDeterminant(0, 1, 2, coefFirstEquat, coefSecondEquat, coefThirdEquat);
	}

	//Решаем сиcтему уравнений методом Крамера
	double fourthPoint[3]{};
	double firstDeterminant = getValueDeterminant(3, 1, 2, coefFirstEquat, coefSecondEquat, coefThirdEquat);
	double secondDeterminant = getValueDeterminant(0, 3, 2, coefFirstEquat, coefSecondEquat, coefThirdEquat);
	double thirdDeterminant = getValueDeterminant(0, 1, 3, coefFirstEquat, coefSecondEquat, coefThirdEquat);

	fourthPoint[0] = firstDeterminant / generalDeterminant;
	fourthPoint[1] = secondDeterminant / generalDeterminant;
	fourthPoint[2] = thirdDeterminant / generalDeterminant;

	//Находим центр окружности
	double* newNormalVector = getNewNormalVector(normalVector, firstPoint, fourthPoint, sidesSquareNorVec);
	double* centerPoint = new double[3];
	for (int i = 0; i < 3; i++)
		centerPoint[i] = fourthPoint[i] - newNormalVector[i];

	return centerPoint;
}

double MeasureMachine::getRadius(double* firstPoint, double* secondPoint, double* thirdPoint, double deviation)
{
	double firstSideTriangle = sqrt(pow(secondPoint[0] - firstPoint[0], 2) +
		pow(secondPoint[1] - firstPoint[1], 2) + pow(secondPoint[2] - firstPoint[2], 2));
	double secondSideTriangle = sqrt(pow(thirdPoint[0] - secondPoint[0], 2) +
		pow(thirdPoint[1] - secondPoint[1], 2) + pow(thirdPoint[2] - secondPoint[2], 2));
	double thirdSideTriangle = sqrt(pow(thirdPoint[0] - firstPoint[0], 2) +
		pow(thirdPoint[1] - firstPoint[1], 2) + pow(thirdPoint[2] - firstPoint[2], 2));
	double radius = firstSideTriangle * secondSideTriangle * thirdSideTriangle /
		sqrt((firstSideTriangle + secondSideTriangle + thirdSideTriangle) *
			(secondSideTriangle + thirdSideTriangle - firstSideTriangle) *
			(thirdSideTriangle + firstSideTriangle - secondSideTriangle) *
			(firstSideTriangle + secondSideTriangle - thirdSideTriangle));

	int precision = 4;
	int bound = (int)(deviation * pow(10, precision));
	int number = pow(10, 4);
	double k = pow(10, -precision);
	double randomNumber = bound != 0 ? (rand() % (2 * bound + 1) - bound) * k : 0;
	double randomRadius = radius + randomNumber;
	double roundedRadius = floor(randomRadius * number) / number;

	return roundedRadius;
}

tuple<QString, double*, double*, double*, double, double, double> 
MeasureMachine::circle(QString dataCommand, QStringList namesPoints, double centerDeviation, double radiusDeviation)
{
	QString pointsCircle = dataCommand;
	pointsCircle = pointsCircle.remove(0, pointsCircle.indexOf('('));
	QStringList arrayPoints = pointsCircle.split('(');
	for (int i = 0; i < 4; i++) {
		arrayPoints[i] = arrayPoints[i].replace(")", "");
		arrayPoints[i] = arrayPoints[i].remove(arrayPoints[i].indexOf("["), arrayPoints[i].length());
	}
	double* nomFirstPoint = getCoordinatePoint(arrayPoints[1], 0);
	double* nomSecondPoint = getCoordinatePoint(arrayPoints[2], 0);
	double* nomThirdPoint = getCoordinatePoint(arrayPoints[3], 0);
	double* actFirstPoint = getCoordinatePoint(arrayPoints[1], centerDeviation);
	double* actSecondPoint = getCoordinatePoint(arrayPoints[2], centerDeviation);
	double* actThirdPoint = getCoordinatePoint(arrayPoints[3], centerDeviation);
	double* nomCenterPoint = getCenterPoint(nomFirstPoint, nomSecondPoint, nomThirdPoint);
	double* actCenterPoint = getCenterPoint(actFirstPoint, actSecondPoint, actThirdPoint);
	double* nomNorVector = getNormalVector(nomFirstPoint, nomSecondPoint, nomThirdPoint);
	double* actNorVector = getNormalVector(actFirstPoint, actSecondPoint, actThirdPoint);
	double nomRadius = getRadius(nomFirstPoint, nomSecondPoint, nomThirdPoint, 0);
	double actRadius = getRadius(actFirstPoint, actSecondPoint, actThirdPoint, radiusDeviation);
	QString result = "%1 %2 %3\nNominal: (%4, %5, %6)[%7, %8, %9]\nActual: (%10, %11, %12)[%13, %14, %15]\nRadius: %16 / %17";
	double sumOfSquares = 0.0;
	for (int i = 0; i < 3; i++)
		sumOfSquares += (nomCenterPoint[i] - actCenterPoint[i]) * (nomCenterPoint[i] - actCenterPoint[i]);
	double distance = sqrt(sumOfSquares);

	return std::make_tuple(result.arg(namesPoints[0]).arg(namesPoints[1]).arg(namesPoints[2])
		.arg(QString::number(nomCenterPoint[0], 'f', 4)).arg(QString::number(nomCenterPoint[1], 'f', 4))
		.arg(QString::number(nomCenterPoint[2], 'f', 4)).arg(QString::number(nomNorVector[0], 'f', 4))
		.arg(QString::number(nomNorVector[1], 'f', 4)).arg(QString::number(nomNorVector[2], 'f', 4))
		.arg(QString::number(actCenterPoint[0], 'f', 4)).arg(QString::number(actCenterPoint[1], 'f', 4))
		.arg(QString::number(actCenterPoint[2], 'f', 4)).arg(QString::number(actNorVector[0], 'f', 4))
		.arg(QString::number(actNorVector[1], 'f', 4)).arg(QString::number(actNorVector[2], 'f', 4))
		.arg(nomRadius).arg(actRadius), nomCenterPoint, actCenterPoint, nomNorVector, distance, nomRadius, actRadius);
}

tuple<QString, QString> MeasureMachine::center(tuple<double*, double*, double*> dataCenter) {
	double* nominalPoint = get<0>(dataCenter);
	double* actualPoint = get<1>(dataCenter);
	double* normalVector = get<2>(dataCenter);
	QString result = "Nominal: %1\nActual: (%2, %3, %4)";
	QString dataDictionary = "(%1, %2, %3)[%4, %5, %6]";
	dataDictionary = dataDictionary.arg(QString::number(nominalPoint[0], 'f', 4)).arg(QString::number(nominalPoint[1], 'f', 4))
		.arg(QString::number(nominalPoint[2], 'f', 4)).arg(QString::number(normalVector[0], 'f', 4))
		.arg(QString::number(normalVector[1], 'f', 4)).arg(QString::number(normalVector[2], 'f', 4));

	return tuple<QString, QString>(result.arg(dataDictionary).arg(QString::number(actualPoint[0], 'f', 4))
		.arg(QString::number(actualPoint[1], 'f', 4)).arg(QString::number(actualPoint[2], 'f', 4)), dataDictionary);
}

tuple<QString, double*, double*> MeasureMachine::plane(QString dataCommand, QStringList namesPoints)
{
	QString pointsPlane = dataCommand;
	pointsPlane = pointsPlane.remove(0, pointsPlane.indexOf('('));
	QStringList arrayPoints = pointsPlane.split('(');
	for (int i = 0; i < 4; i++) {
		arrayPoints[i] = arrayPoints[i].replace(")", "");
		arrayPoints[i] = arrayPoints[i].remove(arrayPoints[i].indexOf("["), arrayPoints[i].length());
	}
	double* nomFirstPoint = getCoordinatePoint(arrayPoints[1], 0);
	double* nomSecondPoint = getCoordinatePoint(arrayPoints[2], 0);
	double* nomThirdPoint = getCoordinatePoint(arrayPoints[3], 0);
	double* actFirstPoint = getCoordinatePoint(arrayPoints[1]);
	double* actSecondPoint = getCoordinatePoint(arrayPoints[2]);
	double* actThirdPoint = getCoordinatePoint(arrayPoints[3]);
	double nomMidPoint[3]{};
	double actMidPoint[3]{};
	double* nomNorVector = getNormalVector(nomFirstPoint, nomSecondPoint, nomThirdPoint);
	double* actNorVector = getNormalVector(actFirstPoint, actSecondPoint, actThirdPoint);
	for (int i = 0; i < 3; i++) {
		nomMidPoint[i] = (nomFirstPoint[i] + nomSecondPoint[i] + nomThirdPoint[i]) / 3;
		actMidPoint[i] = (actFirstPoint[i] + actSecondPoint[i] + actThirdPoint[i]) / 3;
	}

	QString result = "%1 %2 %3\nNominal: (%4, %5, %6)[%7, %8, %9]\nActual: (%10, %11, %12)[%13, %14, %15]";

	return make_tuple(result.arg(namesPoints[0]).arg(namesPoints[1]).arg(namesPoints[2])
		.arg(QString::number(nomMidPoint[0], 'f', 4)).arg(QString::number(nomMidPoint[1], 'f', 4))
		.arg(QString::number(nomMidPoint[2], 'f', 4)).arg(QString::number(nomNorVector[0], 'f', 4))
		.arg(QString::number(nomNorVector[1], 'f', 4)).arg(QString::number(nomNorVector[2], 'f', 4))
		.arg(QString::number(actMidPoint[0], 'f', 4)).arg(QString::number(actMidPoint[1], 'f', 4))
		.arg(QString::number(actMidPoint[2], 'f', 4)).arg(QString::number(actNorVector[0], 'f', 4))
		.arg(QString::number(actNorVector[1], 'f', 4)).arg(QString::number(actNorVector[2], 'f', 4)),
		nomNorVector, nomFirstPoint);
}

tuple<QString, QString> MeasureMachine::projectionPoint(QString data, double* normalVector, double* pointPlane)
{
	QString strPoint = data;
	strPoint = strPoint.remove(strPoint.indexOf(')'), strPoint.length()).replace("(", "");
	double* point = getCoordinatePoint(strPoint);
	float t = (normalVector[0] * (pointPlane[0] - point[0]) + normalVector[1] * (pointPlane[1] - point[1]) +
		normalVector[2] * (pointPlane[2] - point[2])) / (normalVector[0] * normalVector[0] + normalVector[1] * normalVector[1]
			+ normalVector[2] * normalVector[2]);
	double* nomProjPoint = new double[3];
	QString strNomProjPoint = "%1, %2, %3";
	for (int i = 0; i < 3; i++)
		nomProjPoint[i] = point[i] + normalVector[i] * t;
	strNomProjPoint = strNomProjPoint.arg(QString::number(nomProjPoint[0], 'f', 4))
		.arg(QString::number(nomProjPoint[1], 'f', 4)).arg(QString::number(nomProjPoint[2], 'f', 4));
	double* actualProjPoint = getCoordinatePoint(strNomProjPoint);
	QString result = "Nominal: (%1)\nActual: (%2, %3, %4)";
	return make_tuple(result.arg(strNomProjPoint).arg(QString::number(actualProjPoint[0], 'f', 4))
		.arg(QString::number(actualProjPoint[1], 'f', 4)).arg(QString::number(actualProjPoint[2], 'f', 4)),
		"(" + strNomProjPoint + ")");
}

QString MeasureMachine::deviation(QString nameCommand, QString data, QString deviation)
{
	deviation = deviation.replace("[", "").replace("]", "");
	if (nameCommand.contains("POINT"))
	{
		double pointDeviation = deviation.toDouble();
		tuple dataPoint = point(data, pointDeviation);
		QString result = "%1\nPosition: %2 (%3)";
		return result.arg(nameCommand).arg(get<1>(dataPoint)).arg(QString::number(pointDeviation, 'f', 4));
	}
	else
	{
		QStringList strDeviations = deviation.split(",");
		double centerDeviation = strDeviations[0].toDouble();
		double radiusDeviaiton = strDeviations[1].toDouble();
		QStringList namesPoints = { "", "", "" };
		tuple dataCircle = circle(data, namesPoints, centerDeviation, radiusDeviaiton);
		QString result = "%1\nPosition: %2 (%3)\nRadius: %4, %5 (%6 / %7)";

		return result.arg(nameCommand).arg(QString::number(get<4>(dataCircle), 'f', 4))
			.arg(centerDeviation).arg(QString::number(get<5>(dataCircle), 'f', 4)).arg(QString::number(get<6>(dataCircle), 'f', 4))
			.arg(QString::number(abs(get<5>(dataCircle) - get<6>(dataCircle)), 'f', 4)).arg(radiusDeviaiton);
	}
}

