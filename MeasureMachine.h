#pragma once

#include <QObject>
#include "Data.h"
#include "Coordinates.h"
#include <tuple>
#include <QString>
#include <qstringlist.h>
#include <cmath>
#include <tuple>
#include <qrandom.h>

using namespace std;

class MeasureMachine : public QObject
{
	Q_OBJECT

public:
	MeasureMachine(QObject* parent);
	~MeasureMachine();

private slots:
	Coordinates getCoordinatePoint(QString point, double deviation);
	Coordinates getNormalVector(Coordinates firstPoint, Coordinates secondPoint, Coordinates thirdPoint);
	QList<double> getCoefficientEquation(Coordinates point);
	double getValueDeterminant(int i, int j, int k, QList<double> coefFirstEquat, QList<double> coefSecondEquat, QList<double> coefThirdEquat);
	Coordinates getNewNormalVector(Coordinates normalVector, Coordinates firstPoint, Coordinates fourthPoint, double sidesSquareNorVec);
	Coordinates getCenterPoint(Coordinates firstPoint, Coordinates secondPoint, Coordinates thirdPoint);
	double getRadius(Coordinates firstPoint, Coordinates secondPoint, Coordinates thirdPoint, double deviation);

public slots:
	QString move(QString textCommand);
	Data::Point point(QString command, double pointDeviation);
	Data::Circle circle(QString& dataCommand, const QStringList& namesPoints, double centerDeviation, double radiusDeviation);
	Data::Center center(Data::Circle dataCircle);
	Data::Plane plane(QString& dataCommand, const QStringList& namesPoints);
	Data::Projection projectionPoint(QString& dataPoint, Coordinates normalVector, Coordinates pointPlane);
	QString deviation(const QString& nameCommand, QString dataCommand, QString deviation);
};


