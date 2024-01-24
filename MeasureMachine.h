#pragma once

#include <QObject>
#include <tuple>
#include <QString>
#include <qstringlist.h>
#include <cmath>
#include <tuple>
#include <qrandom.h>

using namespace std;

class MeasureMachine  : public QObject
{
	Q_OBJECT

public:
	MeasureMachine(QObject *parent);
	~MeasureMachine();

private slots:
	double* getCoordinatePoint(QString point, double deviation);
	double* getNormalVector(double* firstPoint, double* secondPoint, double* thirdPoint);
	double* getCoefficientEquation(double* point);
	double getValueDeterminant(int i, int j, int k, double* coefFirstEquat, double* coefSecondEquat, double* coefThirdEquat);
	double* getNewNormalVector(double* normalVector, double* firstPoint, double* fourthPoint, double sidesSquareNorVec);
	double* getCenterPoint(double* firstPoint, double* secondPoint, double* thirdPoint);
	double getRadius(double* firstPoint, double* secondPoint, double* thirdPoint, double deviation);

public slots:
	QString move(QString textCommand);
	tuple<QString, QString> point(QString command, double pointDeviation);
	tuple<QString, double*, double*, double*, double, double, double> 
		circle(QString dataCommand, QStringList namesPoints, double centerDeviation, double radiusDeviation);
	tuple<QString, QString> center(tuple<double*, double*, double*> dataCenter);
	tuple<QString, double*, double*> plane(QString dataCommand, QStringList namesPoints);
	tuple<QString, QString> projectionPoint(QString data, double* normalVector, double* pointPlane);
	QString deviation(QString nameCommand, QString data, QString deviation);
};
