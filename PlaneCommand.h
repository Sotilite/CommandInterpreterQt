#pragma once

#include "Command.h"
#include "Coordinates.h"
#include "PointCommand.h"
#include "MeasureMachine.h"
#include <QString>
#include <QList>
#include <QColor>

class PlaneCommand : public Command  {
public:
	explicit PlaneCommand(const QString& name, const QList<PointCommand*> pointsPlane) : Command(name), points(pointsPlane) {}

	virtual bool process() override {
		nomMidPoint = MeasureMachine::getMiddlePoint(points[0]->get_nomPoint(), points[1]->get_nomPoint(), points[2]->get_nomPoint());
		actMidPoint = MeasureMachine::getMiddlePoint(points[0]->get_actPoint(), points[1]->get_actPoint(), points[2]->get_actPoint());
		nomNormal = MeasureMachine::getNormalVector(points[0]->get_nomPoint(), points[1]->get_nomPoint(), points[2]->get_nomPoint());
		actNormal = MeasureMachine::getNormalVector(points[0]->get_actPoint(), points[1]->get_actPoint(), points[2]->get_actPoint());

		return true;
	}

	virtual QColor color() {
		return QColor(255, 170, 0);
	}

	virtual QString generateTextForOutput() override {
		return QString("%1 %2 %3\nNominal: (%4, %5, %6)[%7, %8, %9]\nActual: (%10, %11, %12)[%13, %14, %15]")
			.arg(points[0]->name()).arg(points[1]->name()).arg(points[2]->name())
			.arg(QString::number(nomMidPoint.get_x(), 'f', 4)).arg(QString::number(nomMidPoint.get_y(), 'f', 4))
			.arg(QString::number(nomMidPoint.get_z(), 'f', 4)).arg(QString::number(nomNormal.get_x(), 'f', 4))
			.arg(QString::number(nomNormal.get_y(), 'f', 4)).arg(QString::number(nomNormal.get_z(), 'f', 4))
			.arg(QString::number(actMidPoint.get_x(), 'f', 4)).arg(QString::number(actMidPoint.get_y(), 'f', 4))
			.arg(QString::number(actMidPoint.get_z(), 'f', 4)).arg(QString::number(actNormal.get_x(), 'f', 4))
			.arg(QString::number(actNormal.get_y(), 'f', 4)).arg(QString::number(actNormal.get_z(), 'f', 4));
	}

	virtual QString generateTextForReport() override {
		return generateCodeForPlane(this);
	}

	const Coordinates get_nomMidPoint() const {
		return nomMidPoint;
	}

	const Coordinates get_actMidPoint() const {
		return actMidPoint;
	}

	const Coordinates get_nomNormal() const {
		return nomNormal;
	}

	const Coordinates get_actNormal() const {
		return actNormal;
	}

private:
	QList<PointCommand*> points;
	Coordinates nomMidPoint;
	Coordinates actMidPoint;
	Coordinates nomNormal;
	Coordinates actNormal;

	static QString generateCodeForPlane(PlaneCommand* planeCommand);
};
