#pragma once

#include <QObject>
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

	struct Coordinates {
	private:
		double x;
		double y;
		double z;
		//double array;

	public:
		Coordinates(double x, double y, double z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}
		double get_x() { return x; }
		double get_y() { return y; }
		double get_z() { return z; }
	};

	struct DataPoint {
	private:
		QString result;
		QString distance;

	public:
		DataPoint(QString result, QString distance) {
			this->result = result;
			this->distance = distance;
		}
		QString get_result() { return result; }
		QString get_distance() { return distance; }
	};

	struct DataCircle {
	private:
		QString result;
		double distance;
		array<double, 3> nominalCenter;
		array<double, 3> actualCenter;
		array<double, 3> normalVector;
		double nominalRadius;
		double actualRadius;

	public:
		DataCircle() : DataCircle(array<double, 3>{}, array<double, 3>{}, array<double, 3>{}) {};

		DataCircle(array<double, 3> nominalCenter, array<double, 3> actualCenter, array<double, 3> normalVector) 
			: nominalCenter(nominalCenter), actualCenter(actualCenter), normalVector(normalVector) {
			distance = nominalRadius = actualRadius = 0;
		}

		DataCircle(QString result, array<double, 3> nominalCenter, array<double, 3> actualCenter, double distance,
			array<double, 3> normalVector, double nominalRadius, double actualRadius) {
			this->result = result;
			this->nominalCenter = nominalCenter;
			this->actualCenter = actualCenter;
			this->distance = distance;
			this->normalVector = normalVector;
			this->nominalRadius = nominalRadius;
			this->actualRadius = actualRadius;
		}

		QString get_result() { return result; }
		array<double, 3> get_nomCenter() { return nominalCenter; }
		array<double, 3> get_actCenter() { return actualCenter; }
		double get_distance() { return distance; }
		array<double, 3> get_norVector() { return normalVector; }
		double get_nomRadius() { return nominalRadius; }
		double get_actRadius() { return actualRadius; }
	};

	struct DataCenter {
	private:
		QString result;
		QString dataDictionary;

	public:
		DataCenter(QString result, QString dataDictionary) {
			this->result = result;
			this->dataDictionary = dataDictionary;
		}

		QString get_result() { return result; }
		QString get_dataDict() { return dataDictionary; }
	};

	struct DataPlane {
	private:
		QString result;
		array<double, 3> normalVector{};
		array<double, 3> pointOfCircle{};

	public:
		DataPlane() : DataPlane(QString(), array<double, 3>{}, array<double, 3>{}) {}

		DataPlane(array<double, 3> normalVector, array<double, 3> pointOfCircle) 
			: DataPlane(QString(), normalVector, pointOfCircle) {}

		DataPlane(QString result, array<double, 3> normalVector, array<double, 3> pointOfCircle) {
			this->result = result;
			this->normalVector = normalVector;
			this->pointOfCircle = pointOfCircle;
		}

		QString get_result() { return result; }
		array<double, 3> get_norVector() { return normalVector; }
		array<double, 3> get_point() { return pointOfCircle; }
	};

	struct DataProjection {
	private:
		QString result;
		QString nominalPoint;

	public:
		DataProjection(QString result, QString nominalPoint) {
			this->result = result;
			this->nominalPoint = nominalPoint;
		}

		QString get_result() { return result; }
		QString get_nomPoint() { return nominalPoint; }
	};

private slots:
	array<double, 3> getCoordinatePoint(QString point, double deviation);
	array<double, 3> getNormalVector(array<double, 3> firstPoint, array<double, 3> secondPoint, array<double, 3> thirdPoint);
	QList<double> getCoefficientEquation(array<double, 3> point);
	double getValueDeterminant(int i, int j, int k, QList<double> coefFirstEquat, QList<double> coefSecondEquat, QList<double> coefThirdEquat);
	array<double, 3> getNewNormalVector(array<double, 3> normalVector, array<double, 3> firstPoint, double* fourthPoint, double sidesSquareNorVec);
	array<double, 3> getCenterPoint(array<double, 3> firstPoint, array<double, 3> secondPoint, array<double, 3> thirdPoint);
	double getRadius(array<double, 3> firstPoint, array<double, 3> secondPoint, array<double, 3> thirdPoint, double deviation);

public slots:
	QString move(QString textCommand);
	DataPoint point(QString command, double pointDeviation);
	DataCircle circle(QString& dataCommand, const QStringList& namesPoints, double centerDeviation, double radiusDeviation);
	DataCenter center(DataCircle dataCircle);
	DataPlane plane(QString& dataCommand, const QStringList& namesPoints);
	DataProjection projectionPoint(QString& dataPoint, array<double, 3> normalVector, array<double, 3> pointPlane);
	QString deviation(const QString& nameCommand, QString dataCommand, QString deviation);
};


