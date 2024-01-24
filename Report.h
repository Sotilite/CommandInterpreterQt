#pragma once

#include <QObject>
#include <qstring.h>
#include <qmap.h>
#include <qhash.h>

using namespace std;

class Report : public QObject
{
	Q_OBJECT

public:
	Report(QObject *parent);
	~Report();

private slots:
	QString generateCodeForPoint(QString nameCommand, QString dataCommand);
	QString generateCodeForCircle(QString nameCommand, QString dataCommand);
	QString generateCodeForPlane(QString nameCommand, QString dataCommand);
	QString generateCodeForDeviation(QString dataCommand);

public slots:
	QString createReport(QHash<int, QHash<QString, QString>> commandsResults, QString fileName);
};


