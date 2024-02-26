#include "CircleCommand.h"

QString CircleCommand::generateCodeForCircle(CircleCommand* circleCommand) {
    Coordinates nomCenter = circleCommand->get_nomCenter();
    Coordinates actCenter = circleCommand->get_actCenter();
    Coordinates nomNormal = circleCommand->get_nomNormal();
    Coordinates actNormal = circleCommand->get_actNormal();
    double nomRadius = circleCommand->get_nomRadius();
    double actRadius = circleCommand->get_actRadius();

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

    return result.arg(circleCommand->name()).arg(QString::number(nomCenter.get_x(), 'f', 4))
        .arg(QString::number(nomCenter.get_y(), 'f', 4)).arg(QString::number(nomCenter.get_z(), 'f', 4))
        .arg(QString::number(actCenter.get_x(), 'f', 4)).arg(QString::number(actCenter.get_y(), 'f', 4))
        .arg(QString::number(actCenter.get_z(), 'f', 4)).arg(QString::number(nomNormal.get_x(), 'f', 4))
        .arg(QString::number(nomNormal.get_y(), 'f', 4)).arg(QString::number(nomNormal.get_z(), 'f', 4))
        .arg(QString::number(actNormal.get_x(), 'f', 4)).arg(QString::number(actNormal.get_y(), 'f', 4))
        .arg(QString::number(actNormal.get_z(), 'f', 4)).arg(QString::number(nomRadius, 'f', 4))
        .arg(QString::number(actRadius, 'f', 4));
}