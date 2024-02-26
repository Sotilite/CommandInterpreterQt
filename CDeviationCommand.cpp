#include "CDeviationCommand.h"

QString CDeviationCommand::generateCodeForCDeviation(CDeviationCommand* cDeviationCommand) {
    double nomCenterDev = cDeviationCommand->get_nomCenterDev();
    double actCenterDev = cDeviationCommand->get_actCenterDev();
    double nomRadiusDev = cDeviationCommand->get_nomRadiusDev();
    double actRadiusDev = cDeviationCommand->get_actRadiusDev();

    QString isCorrectForCenter = nomCenterDev >= actCenterDev ? "True" : "False";
    QString isCorrectForRadius = nomRadiusDev >= actRadiusDev ? "True" : "False";

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

    return result.arg(cDeviationCommand->name()).arg(QString::number(actCenterDev, 'f', 4))
        .arg(QString::number(nomCenterDev, 'f', 4)).arg(isCorrectForCenter).arg(QString::number(actRadiusDev, 'f', 4))
        .arg(QString::number(nomRadiusDev, 'f', 4)).arg(isCorrectForRadius);
}