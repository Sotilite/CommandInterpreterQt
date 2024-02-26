#include "PlaneCommand.h"

QString PlaneCommand::generateCodeForPlane(PlaneCommand* planeCommand) {
    Coordinates nomMidPoint = planeCommand->get_nomMidPoint();
    Coordinates actMidPoint = planeCommand->get_actMidPoint();
    Coordinates nomNormal = planeCommand->get_nomNormal();
    Coordinates actNormal = planeCommand->get_actNormal();

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

    return result.arg(planeCommand->name()).arg(QString::number(nomMidPoint.get_x(), 'f', 4))
        .arg(QString::number(nomMidPoint.get_y(), 'f', 4)).arg(QString::number(nomMidPoint.get_z(), 'f', 4))
        .arg(QString::number(actMidPoint.get_x(), 'f', 4)).arg(QString::number(actMidPoint.get_y(), 'f', 4))
        .arg(QString::number(actMidPoint.get_z(), 'f', 4)).arg(QString::number(nomNormal.get_x(), 'f', 4))
        .arg(QString::number(nomNormal.get_y(), 'f', 4)).arg(QString::number(nomNormal.get_z(), 'f', 4))
        .arg(QString::number(actNormal.get_x(), 'f', 4)).arg(QString::number(actNormal.get_y(), 'f', 4))
        .arg(QString::number(actNormal.get_z(), 'f', 4));
}