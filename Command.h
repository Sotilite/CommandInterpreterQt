#pragma once

#include <QString>
#include <QColor>

class Report;

class Command {
public:
	explicit Command(const QString& name) : nameCommand(name) {}

	virtual ~Command() = default;

	const QString& name() const {
		return nameCommand;
	}

	virtual bool process() = 0;

	virtual QColor color() {
		return QColor(Qt::GlobalColor::black);
	}

	virtual QString generateTextForOutput() = 0;

	virtual QString generateTextForReport() = 0;

private:
	QString nameCommand;
};