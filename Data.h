#pragma once

#include <QObject>
#include "Coordinates.h"

using namespace std;

class Data : public QObject
{
	Q_OBJECT

public:
	Data(QObject *parent);
	~Data();

	struct Point {
	private:
		QString result;
		QString distance;

	public:
		Point(QString result, QString distance) {
			this->result = result;
			this->distance = distance;
		}
		QString get_result() { return result; }
		QString get_distance() { return distance; }
	};

	struct Circle {
	private:
		QString result;
		double distance;
		Coordinates nominalCenter;
		Coordinates actualCenter;
		Coordinates normalVector;
		double nominalRadius;
		double actualRadius;

	public:
		Circle() : Circle(Coordinates(), Coordinates(), Coordinates()) {};

		Circle(Coordinates nominalCenter, Coordinates actualCenter, Coordinates normalVector)
			: nominalCenter(nominalCenter), actualCenter(actualCenter), normalVector(normalVector) {
			distance = nominalRadius = actualRadius = 0;
		}

		Circle(QString result, Coordinates nominalCenter, Coordinates actualCenter, double distance,
			Coordinates normalVector, double nominalRadius, double actualRadius) {
			this->result = result;
			this->nominalCenter = nominalCenter;
			this->actualCenter = actualCenter;
			this->distance = distance;
			this->normalVector = normalVector;
			this->nominalRadius = nominalRadius;
			this->actualRadius = actualRadius;
		}

		QString get_result() { return result; }
		Coordinates get_nomCenter() { return nominalCenter; }
		Coordinates get_actCenter() { return actualCenter; }
		double get_distance() { return distance; }
		Coordinates get_norVector() { return normalVector; }
		double get_nomRadius() { return nominalRadius; }
		double get_actRadius() { return actualRadius; }
	};

	struct Center {
	private:
		QString result;
		QString dataDictionary;

	public:
		Center(QString result, QString dataDictionary) {
			this->result = result;
			this->dataDictionary = dataDictionary;
		}

		QString get_result() { return result; }
		QString get_dataDict() { return dataDictionary; }
	};

	struct Plane {
	private:
		QString result;
		Coordinates normalVector{};
		Coordinates pointOfCircle{};

	public:
		Plane() : Plane(QString(), Coordinates(), Coordinates()) {}

		Plane(Coordinates normalVector, Coordinates pointOfCircle)
			: Plane(QString(), normalVector, pointOfCircle) {}

	    Plane(QString result, Coordinates normalVector, Coordinates pointOfCircle) {
			this->result = result;
			this->normalVector = normalVector;
			this->pointOfCircle = pointOfCircle;
		}

		QString get_result() { return result; }
		Coordinates get_norVector() { return normalVector; }
		Coordinates get_point() { return pointOfCircle; }
	};

	struct Projection {
	private:
		QString result;
		QString nominalPoint;

	public:
		Projection(QString result, QString nominalPoint) {
			this->result = result;
			this->nominalPoint = nominalPoint;
		}

		QString get_result() { return result; }
		QString get_nomPoint() { return nominalPoint; }
	};
};
