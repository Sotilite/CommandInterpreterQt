#include "CommandInterpreterQt.h"
#include <QtWidgets/QApplication>
#include <QLabel>
#include <qmainwindow.h>
#include <ui_CommandInterpreterQt.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CommandInterpreterQt w;
    w.show();
    return a.exec();
}


