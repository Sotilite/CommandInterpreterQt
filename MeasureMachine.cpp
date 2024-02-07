#include "MeasureMachine.h"

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
	Coordinates coords;
	QString result = "(%1, %2, %3)";

	for (int i = 0; i < strCoordinates.length(); i++) {
		double coordinate = strCoordinates[i].toDouble();
		coords.setValue(i, coordinate);
	}

	return result.arg(QString::number(coords.get_x(), 'f', 4))
		.arg(QString::number(coords.get_y(), 'f', 4))
		.arg(QString::number(coords.get_z(), 'f', 4));
}

Coordinates MeasureMachine::getCoordinatePoint(QString point, double deviation = 0.0125)
{
	srand(time(0));
	QStringList rawCoordinates = point.split(',');
	Coordinates treatedCoords;
	int precision = 4;
	int bound = (int)(deviation * pow(10, precision));
	for (int i = 0; i < rawCoordinates.length(); i++)
	{
		QString coordinate = rawCoordinates[i].replace(" ", "");
		double k = pow(10, -precision);
		int rand = QRandomGenerator::global()->bounded(100);
		double randomNumber = bound != 0 ? (rand % (2 * bound + 1) - bound) * k : 0;
		double value = coordinate.toDouble() + randomNumber;
		treatedCoords.setValue(i, value);
	}

	return treatedCoords;
}

Data::Point MeasureMachine::point(QString dataCommand, double pointDeviation)
{
	dataCommand = dataCommand.replace("(", "");
	dataCommand = dataCommand.replace(")", "");
	QString strNorVector = dataCommand;
	strNorVector = strNorVector.remove(0, strNorVector.indexOf('[') + 1);
	strNorVector = strNorVector.replace("]", "");
	QStringList coordNormalVector = strNorVector.split(',');
	dataCommand = dataCommand.remove(dataCommand.indexOf('['), dataCommand.length());
	QStringList strNomPoint = dataCommand.split(',');
	Coordinates nominalPoint;
	Coordinates normalVector;
	auto actualPoint = getCoordinatePoint(dataCommand, pointDeviation);

	for (int i = 0; i < 3; i++) {
		nominalPoint.setValue(i, strNomPoint[i].toDouble());
		normalVector.setValue(i, coordNormalVector[i].toDouble());
	}

	double distance = sqrt((nominalPoint.get_x() - actualPoint.get_x()) * (nominalPoint.get_x() - actualPoint.get_x()) +
		(nominalPoint.get_y() - actualPoint.get_y()) * (nominalPoint.get_y() - actualPoint.get_y()) +
		(nominalPoint.get_z() - actualPoint.get_z()) * (nominalPoint.get_z() - actualPoint.get_z()));

	QString result = "Nominal: (%1, %2, %3)[%4, %5, %6]\nActual: (%7, %8, %9)";
	result = result.arg(QString::number(nominalPoint.get_x(), 'f', 4)).arg(QString::number(nominalPoint.get_y(), 'f', 4))
		.arg(QString::number(nominalPoint.get_z(), 'f', 4)).arg(QString::number(normalVector.get_x(), 'f', 4))
		.arg(QString::number(normalVector.get_y(), 'f', 4)).arg(QString::number(normalVector.get_z(), 'f', 4))
		.arg(QString::number(actualPoint.get_x(), 'f', 4)).arg(QString::number(actualPoint.get_y(), 'f', 4))
		.arg(QString::number(actualPoint.get_z(), 'f', 4));

	return Data::Point{ result, QString::number(distance, 'f', 4) };
}

Coordinates MeasureMachine::getNormalVector(Coordinates firstPoint, Coordinates secondPoint, Coordinates thirdPoint)
{
	Coordinates firstVector{
		secondPoint.get_x() - firstPoint.get_x(),
		secondPoint.get_y() - firstPoint.get_y(),
		secondPoint.get_z() - firstPoint.get_z() 
	};
	Coordinates secondVector{ 
		thirdPoint.get_x() - firstPoint.get_x(),
		thirdPoint.get_y() - firstPoint.get_y(),
		thirdPoint.get_z() - firstPoint.get_z() 
	};
	Coordinates normalVector{ 
		firstVector.get_y() * secondVector.get_z() - firstVector.get_z() * secondVector.get_y(),
		-(firstVector.get_x() * secondVector.get_z() - firstVector.get_z() * secondVector.get_x()),
		firstVector.get_x() * secondVector.get_y() - firstVector.get_y() * secondVector.get_x() 
	};
	double lenNorVector = sqrt(pow(normalVector.get_x(), 2) + pow(normalVector.get_y(), 2) + pow(normalVector.get_z(), 2));

	return Coordinates{ 
		normalVector.get_x() / lenNorVector, 
		normalVector.get_y() / lenNorVector, 
		normalVector.get_z() / lenNorVector 
	};
}

QList<double> MeasureMachine::getCoefficientEquation(Coordinates point)
{
	return QList<double>{
		2 * point.get_x(),
		2 * point.get_y(),
		2 * point.get_z(),
		pow(point.get_x(), 2) + pow(point.get_y(), 2) + pow(point.get_z(), 2)
	};
}

double MeasureMachine::getValueDeterminant(int i, int j, int k,
	QList<double> coefFirstEquat, QList<double> coefSecondEquat, QList<double> coefThirdEquat)
{
	double determinant = coefFirstEquat[i] * coefSecondEquat[j] * coefThirdEquat[k] +
		coefFirstEquat[j] * coefSecondEquat[k] * coefThirdEquat[i] +
		coefFirstEquat[k] * coefSecondEquat[i] * coefThirdEquat[j] -
		(coefFirstEquat[k] * coefSecondEquat[j] * coefThirdEquat[i] +
		coefFirstEquat[i] * coefSecondEquat[k] * coefThirdEquat[j] +
		coefFirstEquat[j] * coefSecondEquat[i] * coefThirdEquat[k]);

	return determinant;
}

Coordinates MeasureMachine::getNewNormalVector(Coordinates normalVector, Coordinates firstPoint, 
	Coordinates fourthPoint, double sidesSquareNorVec)
{
	double firstScalarProduct = normalVector.get_x() * fourthPoint.get_x() +
		normalVector.get_y() * fourthPoint.get_y() +
		normalVector.get_z() * fourthPoint.get_z();
	double secondScalarProduct = normalVector.get_x() * firstPoint.get_x() +
		normalVector.get_y() * firstPoint.get_y() +
		normalVector.get_z() * firstPoint.get_z();
	double k = (firstScalarProduct - secondScalarProduct) / sidesSquareNorVec;

	return Coordinates{ k * normalVector.get_x(), k * normalVector.get_y(), k * normalVector.get_z() };
}

Coordinates MeasureMachine::getCenterPoint(Coordinates firstPoint, Coordinates secondPoint, Coordinates thirdPoint)
{
	//Находим нормальный вектор
	auto normalVector = getNormalVector(firstPoint, secondPoint, thirdPoint);
	double sidesSquareNorVec = pow(normalVector.get_x(), 2) + pow(normalVector.get_y(), 2) + pow(normalVector.get_z(), 2);

	//Находим коэфициенты уравнений
	QList<double> coefFirstEquat = getCoefficientEquation(firstPoint);
	QList<double> coefSecondEquat = getCoefficientEquation(secondPoint);
	QList<double> coefThirdEquat = getCoefficientEquation(thirdPoint);
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
	double firstDeterminant = getValueDeterminant(3, 1, 2, coefFirstEquat, coefSecondEquat, coefThirdEquat);
	double secondDeterminant = getValueDeterminant(0, 3, 2, coefFirstEquat, coefSecondEquat, coefThirdEquat);
	double thirdDeterminant = getValueDeterminant(0, 1, 3, coefFirstEquat, coefSecondEquat, coefThirdEquat);

	Coordinates fourthPoint{ 
		firstDeterminant / generalDeterminant, 
		secondDeterminant / generalDeterminant, 
		thirdDeterminant / generalDeterminant
	};

	//Находим центр окружности
	Coordinates newNormalVector = getNewNormalVector(normalVector, firstPoint, fourthPoint, sidesSquareNorVec);

	return Coordinates{ 
		fourthPoint.get_x() - newNormalVector.get_x(),
		fourthPoint.get_y() - newNormalVector.get_y(),
		fourthPoint.get_z() - newNormalVector.get_z()
	};
}

double MeasureMachine::getRadius(Coordinates firstPoint, Coordinates secondPoint, Coordinates thirdPoint, double deviation)
{
	double firstSideTriangle = sqrt(pow(secondPoint.get_x() - firstPoint.get_x(), 2) +
		pow(secondPoint.get_y() - firstPoint.get_y(), 2) + pow(secondPoint.get_z() - firstPoint.get_z(), 2));
	double secondSideTriangle = sqrt(pow(thirdPoint.get_x() - secondPoint.get_x(), 2) +
		pow(thirdPoint.get_y() - secondPoint.get_y(), 2) + pow(thirdPoint.get_z() - secondPoint.get_z(), 2));
	double thirdSideTriangle = sqrt(pow(thirdPoint.get_x() - firstPoint.get_x(), 2) +
		pow(thirdPoint.get_y() - firstPoint.get_y(), 2) + pow(thirdPoint.get_z() - firstPoint.get_z(), 2));
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

Data::Circle MeasureMachine::circle(QString &dataCommand, const QStringList &namesPoints, double centerDeviation, double radiusDeviation)
{
	QString pointsCircle = dataCommand;
	pointsCircle = pointsCircle.remove(0, pointsCircle.indexOf('('));
	QStringList arrayPoints = pointsCircle.split('(');

	for (int i = 0; i < 4; i++) {
		arrayPoints[i] = arrayPoints[i].replace(")", "");
		arrayPoints[i] = arrayPoints[i].remove(arrayPoints[i].indexOf("["), arrayPoints[i].length());
	}

	auto nomFirstPoint = getCoordinatePoint(arrayPoints[1], 0);
	auto nomSecondPoint = getCoordinatePoint(arrayPoints[2], 0);
	auto nomThirdPoint = getCoordinatePoint(arrayPoints[3], 0);
	auto actFirstPoint = getCoordinatePoint(arrayPoints[1], centerDeviation);
	auto actSecondPoint = getCoordinatePoint(arrayPoints[2], centerDeviation);
	auto actThirdPoint = getCoordinatePoint(arrayPoints[3], centerDeviation);
	auto nomCenterPoint = getCenterPoint(nomFirstPoint, nomSecondPoint, nomThirdPoint);
	auto actCenterPoint = getCenterPoint(actFirstPoint, actSecondPoint, actThirdPoint);
	auto nomNorVector = getNormalVector(nomFirstPoint, nomSecondPoint, nomThirdPoint);
	auto actNorVector = getNormalVector(actFirstPoint, actSecondPoint, actThirdPoint);

	double nomRadius = getRadius(nomFirstPoint, nomSecondPoint, nomThirdPoint, 0);
	double actRadius = getRadius(actFirstPoint, actSecondPoint, actThirdPoint, radiusDeviation);
	double distance = sqrt((nomCenterPoint.get_x() - actCenterPoint.get_x()) * (nomCenterPoint.get_x() - actCenterPoint.get_x()) +
		(nomCenterPoint.get_y() - actCenterPoint.get_y()) * (nomCenterPoint.get_y() - actCenterPoint.get_y()) +
		(nomCenterPoint.get_z() - actCenterPoint.get_z()) * (nomCenterPoint.get_z() - actCenterPoint.get_z()));

	QString result = "%1 %2 %3\nNominal: (%4, %5, %6)[%7, %8, %9]\nActual: (%10, %11, %12)[%13, %14, %15]\nRadius: %16 / %17";
	result = result.arg(namesPoints[0]).arg(namesPoints[1]).arg(namesPoints[2])
		.arg(QString::number(nomCenterPoint.get_x(), 'f', 4)).arg(QString::number(nomCenterPoint.get_y(), 'f', 4))
		.arg(QString::number(nomCenterPoint.get_z(), 'f', 4)).arg(QString::number(nomNorVector.get_x(), 'f', 4))
		.arg(QString::number(nomNorVector.get_y(), 'f', 4)).arg(QString::number(nomNorVector.get_z(), 'f', 4))
		.arg(QString::number(actCenterPoint.get_x(), 'f', 4)).arg(QString::number(actCenterPoint.get_y(), 'f', 4))
		.arg(QString::number(actCenterPoint.get_z(), 'f', 4)).arg(QString::number(actNorVector.get_x(), 'f', 4))
		.arg(QString::number(actNorVector.get_y(), 'f', 4)).arg(QString::number(actNorVector.get_z(), 'f', 4))
		.arg(nomRadius).arg(actRadius);

	return Data::Circle{ result, nomCenterPoint, actCenterPoint, distance, nomNorVector, nomRadius, actRadius };
}

Data::Center MeasureMachine::center(Data::Circle dataCircle) 
{
	auto nominalPoint = dataCircle.get_nomCenter();
	auto actualPoint = dataCircle.get_actCenter();
	auto normalVector = dataCircle.get_norVector();

	QString dataDictionary = "(%1, %2, %3)[%4, %5, %6]";
	dataDictionary = dataDictionary.arg(QString::number(nominalPoint.get_x(), 'f', 4)).arg(QString::number(nominalPoint.get_y(), 'f', 4))
		.arg(QString::number(nominalPoint.get_z(), 'f', 4)).arg(QString::number(normalVector.get_x(), 'f', 4))
		.arg(QString::number(normalVector.get_y(), 'f', 4)).arg(QString::number(normalVector.get_z(), 'f', 4));

	QString result = "Nominal: %1\nActual: (%2, %3, %4)";
	result = result.arg(dataDictionary).arg(QString::number(actualPoint.get_x(), 'f', 4))
		.arg(QString::number(actualPoint.get_y(), 'f', 4)).arg(QString::number(actualPoint.get_z(), 'f', 4));

	return Data::Center{ result, dataDictionary };
}

Data::Plane MeasureMachine::plane(QString &dataCommand, const QStringList &namesPoints)
{
	QString pointsPlane = dataCommand;
	pointsPlane = pointsPlane.remove(0, pointsPlane.indexOf('('));
	QStringList arrayPoints = pointsPlane.split('(');

	for (int i = 0; i < 4; i++) {
		arrayPoints[i] = arrayPoints[i].replace(")", "");
		arrayPoints[i] = arrayPoints[i].remove(arrayPoints[i].indexOf("["), arrayPoints[i].length());
	}

	auto nomFirstPoint = getCoordinatePoint(arrayPoints[1], 0);
	auto nomSecondPoint = getCoordinatePoint(arrayPoints[2], 0);
	auto nomThirdPoint = getCoordinatePoint(arrayPoints[3], 0);
	auto actFirstPoint = getCoordinatePoint(arrayPoints[1]);
	auto actSecondPoint = getCoordinatePoint(arrayPoints[2]);
	auto actThirdPoint = getCoordinatePoint(arrayPoints[3]);
	auto nomNorVector = getNormalVector(nomFirstPoint, nomSecondPoint, nomThirdPoint);
	auto actNorVector = getNormalVector(actFirstPoint, actSecondPoint, actThirdPoint);

	Coordinates nomMidPoint{
		(nomFirstPoint.get_x() + nomSecondPoint.get_x() + nomThirdPoint.get_x()) / 3,
		(nomFirstPoint.get_y() + nomSecondPoint.get_y() + nomThirdPoint.get_y()) / 3,
		(nomFirstPoint.get_z() + nomSecondPoint.get_z() + nomThirdPoint.get_z()) / 3
	};
	Coordinates actMidPoint{
		(actFirstPoint.get_x() + actSecondPoint.get_x() + actThirdPoint.get_x()) / 3,
		(actFirstPoint.get_y() + actSecondPoint.get_y() + actThirdPoint.get_y()) / 3,
		(actFirstPoint.get_z() + actSecondPoint.get_z() + actThirdPoint.get_z()) / 3
	};

	QString result = "%1 %2 %3\nNominal: (%4, %5, %6)[%7, %8, %9]\nActual: (%10, %11, %12)[%13, %14, %15]";
	result = result.arg(namesPoints[0]).arg(namesPoints[1]).arg(namesPoints[2])
		.arg(QString::number(nomMidPoint.get_x(), 'f', 4)).arg(QString::number(nomMidPoint.get_y(), 'f', 4))
		.arg(QString::number(nomMidPoint.get_z(), 'f', 4)).arg(QString::number(nomNorVector.get_x(), 'f', 4))
		.arg(QString::number(nomNorVector.get_y(), 'f', 4)).arg(QString::number(nomNorVector.get_z(), 'f', 4))
		.arg(QString::number(actMidPoint.get_x(), 'f', 4)).arg(QString::number(actMidPoint.get_y(), 'f', 4))
		.arg(QString::number(actMidPoint.get_z(), 'f', 4)).arg(QString::number(actNorVector.get_x(), 'f', 4))
		.arg(QString::number(actNorVector.get_y(), 'f', 4)).arg(QString::number(actNorVector.get_z(), 'f', 4));

	return Data::Plane{ result, nomNorVector, nomFirstPoint };
}

Data::Projection MeasureMachine::projectionPoint(QString &dataPoint, Coordinates normalVector, Coordinates pointPlane)
{
	QString strPoint = dataPoint;
	strPoint = strPoint.remove(strPoint.indexOf(')'), strPoint.length()).replace("(", "");
	auto point = getCoordinatePoint(strPoint);

	float t = (normalVector.get_x() * (pointPlane.get_x() - point.get_x()) + 
		normalVector.get_y() * (pointPlane.get_y() - point.get_y()) +
		normalVector.get_z() * (pointPlane.get_z() - point.get_z())) / 
		(pow(normalVector.get_x(), 2) + pow(normalVector.get_y(), 2) + pow(normalVector.get_z(), 2));

	Coordinates nomProjPoint{
		point.get_x() + normalVector.get_x() * t,
		point.get_y() + normalVector.get_y() * t,
		point.get_z() + normalVector.get_z() * t
	};

	QString strNomProjPoint = "%1, %2, %3";
	strNomProjPoint = strNomProjPoint.arg(QString::number(nomProjPoint.get_x(), 'f', 4))
		.arg(QString::number(nomProjPoint.get_y(), 'f', 4)).arg(QString::number(nomProjPoint.get_z(), 'f', 4));

	auto actualProjPoint = getCoordinatePoint(strNomProjPoint);

	QString result = "Nominal: (%1)[%2, %3, %4]\nActual: (%5, %6, %7)";
	result = result.arg(strNomProjPoint).arg(QString::number(normalVector.get_x(), 'f', 4))
		.arg(QString::number(normalVector.get_y(), 'f', 4)).arg(QString::number(normalVector.get_z(), 'f', 4))
		.arg(QString::number(actualProjPoint.get_x(), 'f', 4)).arg(QString::number(actualProjPoint.get_y(), 'f', 4))
		.arg(QString::number(actualProjPoint.get_z(), 'f', 4));

	return Data::Projection{ result, "(" + strNomProjPoint + ")" };
}

QString MeasureMachine::deviation(const QString &nameCommand, QString dataCommand, QString deviation)
{
	deviation = deviation.replace("[", "").replace("]", "");
	if (nameCommand.contains("POINT"))
	{
		double pointDeviation = deviation.toDouble();
		auto data = point(dataCommand, pointDeviation);
		QString result = "%1\nPosition: %2 (%3)";
		return result.arg(nameCommand).arg(data.get_distance()).arg(QString::number(pointDeviation, 'f', 4));
	}
	else
	{
		QStringList strDeviations = deviation.split(",");
		double centerDeviation = strDeviations[0].toDouble();
		double radiusDeviaiton = strDeviations[1].toDouble();
		QStringList namesPoints = { "", "", "" };
		auto data = circle(dataCommand, namesPoints, centerDeviation, radiusDeviaiton);
		QString result = "%1\nPosition: %2 (%3)\nRadius: %4, %5 (%6 / %7)";

		return result.arg(nameCommand).arg(QString::number(data.get_distance(), 'f', 4))
			.arg(centerDeviation).arg(QString::number(data.get_nomRadius(), 'f', 4)).arg(QString::number(data.get_actRadius(), 'f', 4))
			.arg(QString::number(abs(data.get_nomRadius() - data.get_actRadius()), 'f', 4)).arg(radiusDeviaiton);
	}
}

