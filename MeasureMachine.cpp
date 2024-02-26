#include "MeasureMachine.h"

Coordinates MeasureMachine::getCoordinatePoint(Coordinates point)
{
	srand(time(0));
	Coordinates treatedCoords;
	double deviation = 0.0125;
	int precision = 4;
	int bound = (int)(deviation * pow(10, precision));
	for (int i = 0; i < 3; i++)
	{
		double k = pow(10, -precision);
		int rand = QRandomGenerator::global()->bounded(100);
		double randomNumber = (rand % (2 * bound + 1) - bound) * k;
		double value = point.getValue(i) + randomNumber;
		treatedCoords.setValue(i, value);
	}

	return treatedCoords;
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

double MeasureMachine::getRadius(Coordinates firstPoint, Coordinates secondPoint, Coordinates thirdPoint) {
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

	double deviation = 0.0125;
	int precision = 4;
	int bound = (int)(deviation * pow(10, precision));
	int number = pow(10, 4);
	double k = pow(10, -precision);
	double randomNumber = bound != 0 ? (rand() % (2 * bound + 1) - bound) * k : 0;
	double randomRadius = radius + randomNumber;
	double roundedRadius = floor(randomRadius * number) / number;

	return roundedRadius;
}

Coordinates MeasureMachine::getMiddlePoint(Coordinates firstPoint, Coordinates secondPoint, Coordinates thirdPoint) {
	return Coordinates{
		(firstPoint.get_x() + secondPoint.get_x() + thirdPoint.get_x()) / 3,
		(firstPoint.get_y() + secondPoint.get_y() + thirdPoint.get_y()) / 3,
		(firstPoint.get_z() + secondPoint.get_z() + thirdPoint.get_z()) / 3
	};
}

Coordinates MeasureMachine::getProjectionPoint(Coordinates point, Coordinates normalVector, Coordinates pointPlane) {
	float t = (normalVector.get_x() * (pointPlane.get_x() - point.get_x()) + 
		normalVector.get_y() * (pointPlane.get_y() - point.get_y()) +
		normalVector.get_z() * (pointPlane.get_z() - point.get_z())) / 
		(pow(normalVector.get_x(), 2) + pow(normalVector.get_y(), 2) + pow(normalVector.get_z(), 2));

	Coordinates nomProjPoint{
		point.get_x() + normalVector.get_x() * t,
		point.get_y() + normalVector.get_y() * t,
		point.get_z() + normalVector.get_z() * t
	};

	return nomProjPoint;
}

double MeasureMachine::getDistance(Coordinates firstPoint, Coordinates secondPoint) {
	return sqrt(abs((firstPoint.get_x() - secondPoint.get_x()) * (firstPoint.get_x() - secondPoint.get_x()) +
			(firstPoint.get_y() - secondPoint.get_y()) * (firstPoint.get_y() - secondPoint.get_y()) +
			(firstPoint.get_z() - secondPoint.get_z()) * (firstPoint.get_z() - secondPoint.get_z())));
}

