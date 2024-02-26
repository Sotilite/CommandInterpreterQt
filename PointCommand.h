#pragma once

#include "Command.h"
#include "Coordinates.h"
#include "MeasureMachine.h"
#include <QString>
#include <QColor>

class PointCommand  : public Command {
public:
	explicit PointCommand(const QString& name, const Coordinates& point, const Coordinates& vector)
		: Command(name), nominalPoint(point), normal(vector) {}

	virtual bool process() override {
		actualPoint = MeasureMachine::getCoordinatePoint(nominalPoint);

		return true;
	}

	virtual QColor color() override {
		return QColor(0, 255, 0);
	}

	virtual QString generateTextForOutput() override {
		return QString("\nNominal: (%1, %2, %3)[%4, %5, %6]\nActual: (%7, %8, %9)")
			.arg(QString::number(nominalPoint.get_x(), 'f', 4)).arg(QString::number(nominalPoint.get_y(), 'f', 4))
			.arg(QString::number(nominalPoint.get_z(), 'f', 4)).arg(QString::number(normal.get_x(), 'f', 4))
			.arg(QString::number(normal.get_y(), 'f', 4)).arg(QString::number(normal.get_z(), 'f', 4))
			.arg(QString::number(actualPoint.get_x(), 'f', 4)).arg(QString::number(actualPoint.get_y(), 'f', 4))
			.arg(QString::number(actualPoint.get_z(), 'f', 4));
	}

	virtual QString generateTextForReport() override {
		return generateCodeForPoint(this);
	}

	const Coordinates& get_nomPoint() const {
		return nominalPoint;
	}

	const Coordinates& get_actPoint() const {
		return actualPoint;
	}

	const Coordinates& get_normal() const {
		return normal;
	}

private:
	Coordinates nominalPoint;
	Coordinates actualPoint;
	Coordinates normal;

	static QString generateCodeForPoint(PointCommand* pointCommand);
};
