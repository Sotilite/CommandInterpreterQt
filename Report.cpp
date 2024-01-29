#include "Report.h"

using namespace std;

Report::Report(QObject *parent)
	: QObject(parent)
{}

Report::~Report()
{}

QString Report::createReport(const QMap<int, QMap<QString, QString>> &commandsResults, QString &fileName)
{
    fileName = fileName.remove(fileName.indexOf("."), fileName.length());
	QString result = "<h1>Name of the report: " + fileName + "</h1>";

    for (int i = 0; i < commandsResults.count(); i++) {
        const auto &keyValue = commandsResults[i];
        QString key = keyValue.keys()[0];
        if (key.contains("POINT#") || key.contains("C_POINT#") || key.contains("P_POINT#")) 
            result += generateCodeForPoint(key, keyValue[key]);
        else if (key.contains("CIRCLE#"))
            result += generateCodeForCircle(key, keyValue[key]);
        else if (key.contains("PLANE#"))
            result += generateCodeForPlane(key, keyValue[key]);
        else if (key.contains("DEVIATION#"))
            result += generateCodeForDeviation(keyValue[key]);
    }

	return result;
}

QString Report::generateCodeForPoint(const QString &nameCommand, const QString &dataCommand)
{
    QString nomPoint = dataCommand;
    nomPoint = nomPoint.remove(0, nomPoint.indexOf("(") + 1);
    nomPoint = nomPoint.remove(nomPoint.indexOf(")"), nomPoint.length()).replace(" ", "");
    QStringList coordNomPoint = nomPoint.split(",");

    QString actPoint = dataCommand;
    actPoint = actPoint.remove(0, actPoint.lastIndexOf("(") + 1);
    actPoint = actPoint.remove(actPoint.indexOf(")"), actPoint.length()).replace(" ", "");
    QStringList coordActPoint = actPoint.split(",");

    QString normal = dataCommand;
    normal = normal.remove(0, normal.indexOf("[") + 1);
    normal = normal.remove(normal.indexOf("]"), normal.length()).replace(" ", "");
    QStringList coordNormal = normal.split(",");

    QString result = "<table border=\"1\">\
        <tr>\
        <th width=\"330\" style=\"font-size: 24px; text-align: center;\">%1</th>\
        <th width=\"150\" style=\"font-size: 24px; text-align: center;\">X</th>\
        <th width=\"150\" style=\"font-size: 24px; text-align: center;\">Y</th>\
        <th width=\"150\" style=\"font-size: 24px; text-align: center;\">Z</th>\
        </tr>\
        <tr>\
        <td style=\"font-size: 24px; text-align: center;\"><b>Nominal coordinates</b></td>\
        <td style=\"font-size: 24px; text-align: center;\">%2</td>\
        <td style=\"font-size: 24px; text-align: center;\">%3</td>\
        <td style=\"font-size: 24px; text-align: center;\">%4</td>\
        </tr>\
        <tr>\
        <td style=\"font-size: 24px; text-align: center;\"><b>Actaul coordinates</b></td >\
        <td style=\"font-size: 24px; text-align: center;\">%5</td>\
        <td style=\"font-size: 24px; text-align: center;\">%6</td>\
        <td style=\"font-size: 24px; text-align: center;\">%7</td>\
        </tr>\
        <tr>\
        <td style=\"font-size: 24px; text-align: center;\"><b>Normal</b></td >\
        <td style=\"font-size: 24px; text-align: center;\">%8</td>\
        <td style=\"font-size: 24px; text-align: center;\">%9</td>\
        <td style=\"font-size: 24px; text-align: center;\">%10</td>\
        </tr>\
        </table><br>";

    return result.arg(nameCommand).arg(coordNomPoint[0]).arg(coordNomPoint[1]).arg(coordNomPoint[2]).arg(coordActPoint[0])
        .arg(coordActPoint[1]).arg(coordActPoint[2]).arg(coordNormal[0]).arg(coordNormal[1]).arg(coordNormal[2]);
}

QString Report::generateCodeForCircle(const QString &nameCommand, const QString &dataCommand)
{
    QString nomCenter = dataCommand;
    nomCenter = nomCenter.remove(0, nomCenter.indexOf("(") + 1);
    nomCenter = nomCenter.remove(nomCenter.indexOf(")"), nomCenter.length()).replace(" ", "");
    QStringList coordNomCenter = nomCenter.split(",");

    QString actCenter = dataCommand;
    actCenter = actCenter.remove(0, actCenter.lastIndexOf("(") + 1);
    actCenter = actCenter.remove(actCenter.indexOf(")"), actCenter.length()).replace(" ", "");
    QStringList coordActCenter = actCenter.split(",");

    QString nomNormal = dataCommand;
    nomNormal = nomNormal.remove(0, nomNormal.indexOf("[") + 1);
    nomNormal = nomNormal.remove(nomNormal.indexOf("]"), nomNormal.length()).replace(" ", "");
    QStringList coordNomNormal = nomNormal.split(",");

    QString actNormal = dataCommand;
    actNormal = actNormal.remove(0, actNormal.lastIndexOf("[") + 1);
    actNormal = actNormal.remove(actNormal.indexOf("]"), actNormal.length()).replace(" ", "");
    QStringList coordActNormal = actNormal.split(",");

    QString radiuses = dataCommand;
    radiuses = radiuses.remove(0, radiuses.lastIndexOf("R") + 7).replace(" ", "");
    QStringList valuesRadiuses = radiuses.split("/");

    QString result = "<table border=\"1\">\
        <tr>\
        <th width=\"330\" style=\"font-size: 24px; text-align: center;\">%1</th>\
        <th width=\"150\" style=\"font-size: 24px; text-align: center;\">X</th>\
        <th width=\"150\" style=\"font-size: 24px; text-align: center;\">Y</th>\
        <th width=\"150\" style=\"font-size: 24px; text-align: center;\">Z</th>\
        </tr>\
        <tr>\
        <td style=\"font-size: 24px; text-align: center;\"><b>Nominal center</b></td>\
        <td style=\"font-size: 24px; text-align: center;\">%2</td>\
        <td style=\"font-size: 24px; text-align: center;\">%3</td>\
        <td style=\"font-size: 24px; text-align: center;\">%4</td>\
        </tr>\
        <tr>\
        <td style=\"font-size: 24px; text-align: center;\"><b>Actaul center</b></td >\
        <td style=\"font-size: 24px; text-align: center;\">%5</td>\
        <td style=\"font-size: 24px; text-align: center;\">%6</td>\
        <td style=\"font-size: 24px; text-align: center;\">%7</td>\
        </tr>\
        <tr>\
        <td style=\"font-size: 24px; text-align: center;\"><b>Nominal normal</b></td >\
        <td style=\"font-size: 24px; text-align: center;\">%8</td>\
        <td style=\"font-size: 24px; text-align: center;\">%9</td>\
        <td style=\"font-size: 24px; text-align: center;\">%10</td>\
        </tr>\
        <tr>\
        <td style=\"font-size: 24px; text-align: center;\"><b>Actaul normal</b></td >\
        <td style=\"font-size: 24px; text-align: center;\">%11</td>\
        <td style=\"font-size: 24px; text-align: center;\">%12</td>\
        <td style=\"font-size: 24px; text-align: center;\">%13</td>\
        </tr>\
        <tr>\
        <td colspan=\"4\" style=\"font-size: 24px; text-align: center;\"><b>Radius</b></td >\
        </tr>\
        <tr>\
        <td style=\"font-size: 24px; text-align: center;\"><b>Nominal radius</b></td >\
        <td colspan=\"3\" style=\"font-size: 24px; text-align: center;\">%14</td>\
        </tr>\
        <tr>\
        <td style=\"font-size: 24px; text-align: center;\"><b>Actual radius</b></td >\
        <td colspan=\"3\" style=\"font-size: 24px; text-align: center;\">%15</td>\
        </tr>\
        </table><br>";

    return result.arg(nameCommand).arg(coordNomCenter[0]).arg(coordNomCenter[1]).arg(coordNomCenter[2]).arg(coordActCenter[0])
        .arg(coordActCenter[1]).arg(coordActCenter[2]).arg(coordNomNormal[0]).arg(coordNomNormal[1]).arg(coordNomNormal[2])
        .arg(coordActNormal[0]).arg(coordActNormal[1]).arg(coordActNormal[2]).arg(valuesRadiuses[0]).arg(valuesRadiuses[1]);
}

QString Report::generateCodeForPlane(const QString &nameCommand, const QString &dataCommand)
{
    QString nomPoint = dataCommand;
    nomPoint = nomPoint.remove(0, nomPoint.indexOf("(") + 1);
    nomPoint = nomPoint.remove(nomPoint.indexOf(")"), nomPoint.length()).replace(" ", "");
    QStringList coordNomCenter = nomPoint.split(",");

    QString actPoint = dataCommand;
    actPoint = actPoint.remove(0, actPoint.lastIndexOf("(") + 1);
    actPoint = actPoint.remove(actPoint.indexOf(")"), actPoint.length()).replace(" ", "");
    QStringList coordActCenter = actPoint.split(",");

    QString nomNormal = dataCommand;
    nomNormal = nomNormal.remove(0, nomNormal.indexOf("[") + 1);
    nomNormal = nomNormal.remove(nomNormal.indexOf("]"), nomNormal.length()).replace(" ", "");
    QStringList coordNomNormal = nomNormal.split(",");

    QString actNormal = dataCommand;
    actNormal = actNormal.remove(0, actNormal.lastIndexOf("[") + 1);
    actNormal = actNormal.remove(actNormal.indexOf("]"), actNormal.length()).replace(" ", "");
    QStringList coordActNormal = actNormal.split(",");

    QString result = "<table border=\"1\">\
        <tr>\
        <th width=\"330\" style=\"font-size: 24px; text-align: center;\">%1</th>\
        <th width=\"150\" style=\"font-size: 24px; text-align: center;\">X</th>\
        <th width=\"150\" style=\"font-size: 24px; text-align: center;\">Y</th>\
        <th width=\"150\" style=\"font-size: 24px; text-align: center;\">Z</th>\
        </tr>\
        <tr>\
        <td style=\"font-size: 24px; text-align: center;\"><b>Nominal point on the plane</b></td>\
        <td style=\"font-size: 24px; text-align: center;\">%2</td>\
        <td style=\"font-size: 24px; text-align: center;\">%3</td>\
        <td style=\"font-size: 24px; text-align: center;\">%4</td>\
        </tr>\
        <tr>\
        <td style=\"font-size: 24px; text-align: center;\"><b>Actaul point on the plane</b></td >\
        <td style=\"font-size: 24px; text-align: center;\">%5</td>\
        <td style=\"font-size: 24px; text-align: center;\">%6</td>\
        <td style=\"font-size: 24px; text-align: center;\">%7</td>\
        </tr>\
        <tr>\
        <td style=\"font-size: 24px; text-align: center;\"><b>Nominal normal</b></td >\
        <td style=\"font-size: 24px; text-align: center;\">%8</td>\
        <td style=\"font-size: 24px; text-align: center;\">%9</td>\
        <td style=\"font-size: 24px; text-align: center;\">%10</td>\
        </tr>\
        <tr>\
        <td style=\"font-size: 24px; text-align: center;\"><b>Actaul normal</b></td >\
        <td style=\"font-size: 24px; text-align: center;\">%11</td>\
        <td style=\"font-size: 24px; text-align: center;\">%12</td>\
        <td style=\"font-size: 24px; text-align: center;\">%13</td>\
        </tr>\
        </table><br>";

    return result.arg(nameCommand).arg(coordNomCenter[0]).arg(coordNomCenter[1]).arg(coordNomCenter[2]).arg(coordActCenter[0])
        .arg(coordActCenter[1]).arg(coordActCenter[2]).arg(coordNomNormal[0]).arg(coordNomNormal[1]).arg(coordNomNormal[2])
        .arg(coordActNormal[0]).arg(coordActNormal[1]).arg(coordActNormal[2]);
}

QString Report::generateCodeForDeviation(const QString &dataCommand)
{
    QString nameCommand = dataCommand;
    nameCommand = nameCommand.remove(nameCommand.lastIndexOf("P"), nameCommand.length());
    if (nameCommand.contains("POINT#")) {
        QString strActDeviation = dataCommand;
        strActDeviation = strActDeviation.remove(0, strActDeviation.indexOf(":") + 1);
        strActDeviation = strActDeviation.remove(strActDeviation.indexOf("("), strActDeviation.length()).replace(" ", "");
        double actDeviation = strActDeviation.toDouble();
        QString strNomDeviation = dataCommand;
        strNomDeviation = strNomDeviation.remove(0, strNomDeviation.indexOf("(") + 1).replace(")", "").replace(" ", "");
        double nomDeviation = strNomDeviation.toDouble();
        QString isCorrectForPoint = nomDeviation >= actDeviation ? "True" : "False";

        QString result = "<table border=\"1\">\
        <tr>\
        <th width=\"261\" style=\"font-size: 24px; text-align: center;\">Actual deviation for %1</th>\
        <th width=\"262\" style=\"font-size: 24px; text-align: center;\">Nominal deviation</th>\
        <th width=\"261\" style=\"font-size: 24px; text-align: center;\">Is the deviation acceptable</th>\
        </tr>\
        <tr>\
        <td style=\"font-size: 24px; text-align: center;\">%2</td>\
        <td style=\"font-size: 24px; text-align: center;\">%3</td>\
        <td style=\"font-size: 24px; text-align: center;\">%4</td>\
        </tr>\
        </table><br>";

        return result.arg(nameCommand).arg(strActDeviation).arg(strNomDeviation).arg(isCorrectForPoint);
    }
    else {
        QString strActDevCenter = dataCommand;
        strActDevCenter = strActDevCenter.remove(0, strActDevCenter.indexOf(":") + 1);
        strActDevCenter = strActDevCenter.remove(strActDevCenter.indexOf("("), strActDevCenter.length()).replace(" ", "");
        double actDevCenter = strActDevCenter.toDouble();
        QString strNomDevCenter = dataCommand;
        strNomDevCenter = strNomDevCenter.remove(0, strNomDevCenter.indexOf("(") + 1);
        strNomDevCenter = strNomDevCenter.remove(strNomDevCenter.indexOf(")"), strNomDevCenter.length()).replace(" ", "");
        double nomDevCenter = strNomDevCenter.toDouble();
        QString isCorrectForCenter = nomDevCenter >= actDevCenter ? "True" : "False";

        QString strActDevRadius = dataCommand;
        strActDevRadius = strActDevRadius.remove(0, strActDevRadius.lastIndexOf("(") + 1);
        strActDevRadius = strActDevRadius.remove(strActDevRadius.indexOf("/"), strActDevRadius.length()).replace(" ", "");
        double actDevRadius = strActDevRadius.toDouble();
        QString strNomDevRadius = dataCommand;
        strNomDevRadius = strNomDevRadius.remove(0, strNomDevRadius.lastIndexOf("/") + 1).replace(")", "").replace(" ", "");
        double nomDevRadius = strNomDevRadius.toDouble();
        QString isCorrectForRadius = nomDevRadius >= actDevRadius ? "True" : "False";

        QString result = "<table border=\"1\">\
        <tr>\
        <th width=\"195\" style=\"font-size: 24px; text-align: center;\">Deviation for %1</th>\
        <th width=\"195\" style=\"font-size: 24px; text-align: center;\">Actual deviation for %1</th>\
        <th width=\"195\" style=\"font-size: 24px; text-align: center;\">Nominal deviation</th>\
        <th width=\"195\" style=\"font-size: 24px; text-align: center;\">Is the deviation acceptable</th>\
        </tr>\
        <tr>\
        <td style=\"font-size: 24px; text-align: center;\"><b>Center</b></td>\
        <td style=\"font-size: 24px; text-align: center;\">%2</td>\
        <td style=\"font-size: 24px; text-align: center;\">%3</td>\
        <td style=\"font-size: 24px; text-align: center;\">%4</td>\
        </tr>\
        <tr>\
        <td style=\"font-size: 24px; text-align: center;\"><b>Radius</b></td >\
        <td style=\"font-size: 24px; text-align: center;\">%5</td>\
        <td style=\"font-size: 24px; text-align: center;\">%6</td>\
        <td style=\"font-size: 24px; text-align: center;\">%7</td>\
        </table><br>";

        return result.arg(nameCommand).arg(strActDevCenter).arg(strNomDevCenter).arg(isCorrectForCenter)
            .arg(strActDevRadius).arg(strNomDevRadius).arg(isCorrectForRadius);
    }
}

