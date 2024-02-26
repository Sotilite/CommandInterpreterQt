#pragma once

#include "Command.h"
#include "PointCommand.h"
#include "MeasureMachine.h"
#include <QString>
#include <QColor>

class PDeviationCommand : public Command {
public:
	explicit PDeviationCommand(const QString& name, PointCommand* point, double deviation)
		: Command(name), pointCommand(point), nomDeviation(deviation), actDeviation(0) {}

	virtual bool process() override {
		actDeviation = MeasureMachine::getDistance(pointCommand->get_nomPoint(), pointCommand->get_actPoint());

		return true;
	}

	virtual QColor color() override {
		return QColor(0, 0, 255);
	}

	virtual QString generateTextForOutput() override {
		return QString("%1\nPosition: %2 (%3)").arg(pointCommand->name())
			.arg(QString::number(actDeviation, 'f', 4)).arg(QString::number(nomDeviation, 'f', 4));
	}

	virtual QString generateTextForReport() override {
		return generateCodeForPDeviation(this);
	}

	const double get_nomDeviation() const {
		return nomDeviation;
	}

	const double get_actDeviation() const {
		return actDeviation;
	}

private:
	PointCommand* pointCommand;
	double nomDeviation;
	double actDeviation;

	static QString generateCodeForPDeviation(PDeviationCommand* pDeviationCommand);
};
