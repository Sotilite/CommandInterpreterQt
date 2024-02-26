#include "PDeviationCommand.h"

QString PDeviationCommand::generateCodeForPDeviation(PDeviationCommand* pDeviationCommand) {
    double nomPointDeviation = pDeviationCommand->get_nomDeviation();
    double actPointDeviation = pDeviationCommand->get_actDeviation();

    QString isCorrectForPoint = nomPointDeviation >= actPointDeviation ? "True" : "False";

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

    return result.arg(pDeviationCommand->name()).arg(QString::number(actPointDeviation, 'f', 4))
        .arg(QString::number(nomPointDeviation, 'f', 4)).arg(isCorrectForPoint);
}