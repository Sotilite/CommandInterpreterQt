#pragma once

#include "Command.h"
#include "CircleCommand.h"
#include "MeasureMachine.h"
#include <QString>
#include <QColor>

class CDeviationCommand : public Command {
public:
	explicit CDeviationCommand(const QString& name, CircleCommand* circle, double centerDeviation, double radiusDeviation)
		: Command(name), circleCommand(circle), nomCenterDeviation(centerDeviation), nomRadiusDeviation(radiusDeviation),
		actCenterDeviation(0), actRadiusDeviation(0) {}

	virtual bool process() override {
		actCenterDeviation = MeasureMachine::getDistance(circleCommand->get_nomCenter(), circleCommand->get_actCenter());
		actRadiusDeviation = abs(circleCommand->get_nomRadius() - circleCommand->get_actRadius());

		return true;
	}

	virtual QColor color() override {
		return QColor(0, 0, 255);
	}

	virtual QString generateTextForOutput() override {
		return QString("%1\nPosition: %2 (%3)\nRadius: %4, %5 (%6 / %7)")
			.arg(circleCommand->name()).arg(QString::number(actCenterDeviation, 'f', 4)).arg(QString::number(nomCenterDeviation, 'f', 4))
			.arg(QString::number(circleCommand->get_nomRadius(), 'f', 4)).arg(QString::number(circleCommand->get_actRadius(), 'f', 4))
			.arg(QString::number(abs(actRadiusDeviation), 'f', 4)).arg(QString::number(nomRadiusDeviation, 'f', 4));
	}

	virtual QString generateTextForReport() override {
		return generateCodeForCDeviation(this);
	}

	const double get_nomCenterDev() const {
		return nomCenterDeviation;
	}

	const double get_actCenterDev() const {
		return nomCenterDeviation;
	}

	const double get_nomRadiusDev() const {
		return nomRadiusDeviation;
	}

	const double get_actRadiusDev() const {
		return actRadiusDeviation;
	}

private:
	CircleCommand* circleCommand;
	double nomCenterDeviation;
	double actCenterDeviation;
	double nomRadiusDeviation;
	double actRadiusDeviation;

	static QString generateCodeForCDeviation(CDeviationCommand* cDeviationCommand);
};
