#include "PointCommand.h"

QString PointCommand::generateCodeForPoint(PointCommand* pointCommand) {
    Coordinates nomPoint = pointCommand->get_nomPoint();
    Coordinates actPoint = pointCommand->get_actPoint();
    Coordinates normalVector = pointCommand->get_normal();

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

    return result.arg(pointCommand->name()).arg(QString::number(nomPoint.get_x(), 'f', 4))
        .arg(QString::number(nomPoint.get_y(), 'f', 4)).arg(QString::number(nomPoint.get_z(), 'f', 4))
        .arg(QString::number(actPoint.get_x(), 'f', 4)).arg(QString::number(actPoint.get_y(), 'f', 4))
        .arg(QString::number(actPoint.get_z(), 'f', 4)).arg(QString::number(normalVector.get_x(), 'f', 4))
        .arg(QString::number(normalVector.get_y(), 'f', 4)).arg(QString::number(normalVector.get_z(), 'f', 4));
}
