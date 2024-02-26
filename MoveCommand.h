#pragma once

#include "Command.h"
#include "Coordinates.h"
#include <QString>
#include <QColor>

class MoveCommand : public Command {
public:
	MoveCommand(const QString& name, Coordinates point) : Command(name), pointOfMovement(point) {}

	virtual bool process() override {
		return true;
	}

	virtual QColor color() override {
		return QColor(0, 255, 0);
	}

	virtual QString generateTextForOutput() override {
		return QString("(%1, %2, %3)").arg(QString::number(pointOfMovement.get_x(), 'f', 4))
			.arg(QString::number(pointOfMovement.get_y(), 'f', 4)).arg(QString::number(pointOfMovement.get_z(), 'f', 4));
	}

	virtual QString generateTextForReport() override {
		return QString();
	}

private:
	Coordinates pointOfMovement;
};
