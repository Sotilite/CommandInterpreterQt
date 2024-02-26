#pragma once

#include "Coordinates.h"
#include <QString>
#include <QStringList>
#include <cmath>
#include <qrandom.h>

using namespace std;

class MeasureMachine {
public:
	static Coordinates getCoordinatePoint(Coordinates point);
	static Coordinates getNormalVector(Coordinates firstPoint, Coordinates secondPoint, Coordinates thirdPoint);
	static QList<double> getCoefficientEquation(Coordinates point);
	static double getValueDeterminant(int i, int j, int k, QList<double> coefFirstEquat, QList<double> coefSecondEquat, QList<double> coefThirdEquat);
	static Coordinates getNewNormalVector(Coordinates normalVector, Coordinates firstPoint, Coordinates fourthPoint, double sidesSquareNorVec);
	static Coordinates getCenterPoint(Coordinates firstPoint, Coordinates secondPoint, Coordinates thirdPoint);
	static double getRadius(Coordinates firstPoint, Coordinates secondPoint, Coordinates thirdPoint);
	static Coordinates getMiddlePoint(Coordinates firstPoint, Coordinates secondPoint, Coordinates thirdPoint);
	static Coordinates getProjectionPoint(Coordinates point, Coordinates normalVector, Coordinates pointPlane);
	static double getDistance(Coordinates firstPoint, Coordinates secondPoint);
};


