#pragma once

#include "Command.h"
#include "Coordinates.h"
#include "PointCommand.h"
#include "MeasureMachine.h"
#include <QString>
#include <QList>
#include <QColor>

class CircleCommand  : public Command {
public:
	explicit CircleCommand(const QString& name, const QList<PointCommand*> pointsCircle)
		: Command(name), points(pointsCircle), nominalRadius(0), actualRadius(0) {}

	virtual bool process() override {
		nomCenterPoint = MeasureMachine::getCenterPoint(points[0]->get_nomPoint(), points[1]->get_nomPoint(), points[2]->get_nomPoint());
		actCenterPoint = MeasureMachine::getCenterPoint(points[0]->get_actPoint(), points[1]->get_actPoint(), points[2]->get_actPoint());
		nomNormal = MeasureMachine::getNormalVector(points[0]->get_nomPoint(), points[1]->get_nomPoint(), points[2]->get_nomPoint());
		actNormal = MeasureMachine::getNormalVector(points[0]->get_actPoint(), points[1]->get_actPoint(), points[2]->get_actPoint());
		nominalRadius = MeasureMachine::getRadius(points[0]->get_nomPoint(), points[1]->get_nomPoint(), points[2]->get_nomPoint());
		actualRadius = MeasureMachine::getRadius(points[0]->get_actPoint(), points[1]->get_actPoint(), points[2]->get_actPoint());

		return true;
	}

	virtual QColor color() override {
		return QColor(255, 170, 0);
	}

	virtual QString generateTextForOutput() override {
		return QString("%1 %2 %3\nNominal: (%4, %5, %6)[%7, %8, %9]\nActual: (%10, %11, %12)[%13, %14, %15]\nRadius: %16 / %17")
			.arg(points[0]->name()).arg(points[1]->name()).arg(points[2]->name())
			.arg(QString::number(nomCenterPoint.get_x(), 'f', 4)).arg(QString::number(nomCenterPoint.get_y(), 'f', 4))
			.arg(QString::number(nomCenterPoint.get_z(), 'f', 4)).arg(QString::number(nomNormal.get_x(), 'f', 4))
			.arg(QString::number(nomNormal.get_y(), 'f', 4)).arg(QString::number(nomNormal.get_z(), 'f', 4))
			.arg(QString::number(actCenterPoint.get_x(), 'f', 4)).arg(QString::number(actCenterPoint.get_y(), 'f', 4))
			.arg(QString::number(actCenterPoint.get_z(), 'f', 4)).arg(QString::number(actNormal.get_x(), 'f', 4))
			.arg(QString::number(actNormal.get_y(), 'f', 4)).arg(QString::number(actNormal.get_z(), 'f', 4))
			.arg(nominalRadius).arg(actualRadius);
	}

	virtual QString generateTextForReport() override {
		return generateCodeForCircle(this);
	}

	const double get_nomRadius() const {
		return nominalRadius;
	}

	const double get_actRadius() const {
		return actualRadius;
	}

	const Coordinates get_nomCenter() const {
		return nomCenterPoint;
	}

	const Coordinates get_actCenter() const {
		return actCenterPoint;
	}

	const Coordinates get_nomNormal() const {
		return nomNormal;
	}

	const Coordinates get_actNormal() const {
		return actNormal;
	}

private:
	QList<PointCommand*> points;
	Coordinates nomCenterPoint;
	Coordinates actCenterPoint;
	Coordinates nomNormal;
	Coordinates actNormal;
	double nominalRadius;
	double actualRadius;

	static QString generateCodeForCircle(CircleCommand* circleCommand);
};
