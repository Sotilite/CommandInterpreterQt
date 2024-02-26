#pragma once

#include "PointCommand.h"
#include <QString>
#include <QColor>

class ProjectionCommand  : public PointCommand {
public:
	ProjectionCommand(const QString& name, const Coordinates& point, const Coordinates& vector) : PointCommand(name, point, vector) {}

	virtual QColor color() override {
		return QColor(255, 170, 0);
	}
};
