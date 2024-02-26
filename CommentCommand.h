#pragma once

#include "Command.h"
#include <QString>
#include <QColor>

class CommentCommand : public Command {
public:
	CommentCommand(const QString& name, const QString& text) : Command(name), textComment(text) {}

	virtual bool process() override {
		return true;
	}

	virtual QColor color() override {
		return QColor(255, 0, 0);
	}

	virtual QString generateTextForOutput() override {
		return QString("\n//(%1)").arg(textComment);
	}

	virtual QString generateTextForReport() override {
		return QString();
	}

private:
	QString textComment;
};
