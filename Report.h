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
	QString generateCodeForPoint(const QString &nameCommand, const QString &dataCommand);
	QString generateCodeForCircle(const QString &nameCommand, const QString &dataCommand);
	QString generateCodeForPlane( const QString &nameCommand, const QString &dataCommand);
	QString generateCodeForDeviation(const QString &dataCommand);

public slots:
	QString createReport(const QMap<int, QMap<QString, QString>> &commandsResults, QString &fileName);
};


