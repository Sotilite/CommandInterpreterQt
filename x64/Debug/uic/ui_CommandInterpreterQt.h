/********************************************************************************
** Form generated from reading UI file 'CommandInterpreterQt.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMANDINTERPRETERQT_H
#define UI_COMMANDINTERPRETERQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommandInterpreterQtClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_3;
    QPushButton *pointButton;
    QPushButton *moveButton;
    QTextEdit *inputConsole;
    QPushButton *planeButton;
    QPushButton *clearInputButton;
    QPushButton *debugButton;
    QPushButton *circleButton;
    QPushButton *projectionButton;
    QPushButton *commentButton;
    QPushButton *getReportButton;
    QPushButton *runButton;
    QPushButton *centerButton;
    QPushButton *saveFileButton;
    QLabel *label;
    QPushButton *deviationButton;
    QPushButton *openFileButton;
    QFrame *line;
    QFrame *line_2;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QPushButton *clearOutputButton;
    QFrame *line_3;
    QTextEdit *outputConsole;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CommandInterpreterQtClass)
    {
        if (CommandInterpreterQtClass->objectName().isEmpty())
            CommandInterpreterQtClass->setObjectName("CommandInterpreterQtClass");
        CommandInterpreterQtClass->resize(946, 681);
        centralWidget = new QWidget(CommandInterpreterQtClass);
        centralWidget->setObjectName("centralWidget");
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName("gridLayout_3");
        pointButton = new QPushButton(centralWidget);
        pointButton->setObjectName("pointButton");

        gridLayout_3->addWidget(pointButton, 5, 0, 1, 1);

        moveButton = new QPushButton(centralWidget);
        moveButton->setObjectName("moveButton");

        gridLayout_3->addWidget(moveButton, 4, 0, 1, 1);

        inputConsole = new QTextEdit(centralWidget);
        inputConsole->setObjectName("inputConsole");
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI Historic")});
        font.setPointSize(14);
        inputConsole->setFont(font);
        inputConsole->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        inputConsole->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        inputConsole->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        inputConsole->setReadOnly(false);

        gridLayout_3->addWidget(inputConsole, 3, 1, 12, 4);

        planeButton = new QPushButton(centralWidget);
        planeButton->setObjectName("planeButton");

        gridLayout_3->addWidget(planeButton, 8, 0, 1, 1);

        clearInputButton = new QPushButton(centralWidget);
        clearInputButton->setObjectName("clearInputButton");

        gridLayout_3->addWidget(clearInputButton, 2, 3, 1, 1);

        debugButton = new QPushButton(centralWidget);
        debugButton->setObjectName("debugButton");

        gridLayout_3->addWidget(debugButton, 0, 1, 1, 1);

        circleButton = new QPushButton(centralWidget);
        circleButton->setObjectName("circleButton");

        gridLayout_3->addWidget(circleButton, 6, 0, 1, 1);

        projectionButton = new QPushButton(centralWidget);
        projectionButton->setObjectName("projectionButton");

        gridLayout_3->addWidget(projectionButton, 9, 0, 1, 1);

        commentButton = new QPushButton(centralWidget);
        commentButton->setObjectName("commentButton");

        gridLayout_3->addWidget(commentButton, 3, 0, 1, 1);

        getReportButton = new QPushButton(centralWidget);
        getReportButton->setObjectName("getReportButton");

        gridLayout_3->addWidget(getReportButton, 0, 4, 1, 1);

        runButton = new QPushButton(centralWidget);
        runButton->setObjectName("runButton");
        QFont font1;
        font1.setPointSize(9);
        runButton->setFont(font1);
        runButton->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(runButton, 0, 0, 1, 1);

        centerButton = new QPushButton(centralWidget);
        centerButton->setObjectName("centerButton");

        gridLayout_3->addWidget(centerButton, 7, 0, 1, 1);

        saveFileButton = new QPushButton(centralWidget);
        saveFileButton->setObjectName("saveFileButton");

        gridLayout_3->addWidget(saveFileButton, 0, 2, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName("label");
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        label->setFont(font2);
        label->setFrameShape(QFrame::Box);
        label->setLineWidth(0);
        label->setTextFormat(Qt::AutoText);

        gridLayout_3->addWidget(label, 2, 1, 1, 2);

        deviationButton = new QPushButton(centralWidget);
        deviationButton->setObjectName("deviationButton");

        gridLayout_3->addWidget(deviationButton, 10, 0, 1, 1);

        openFileButton = new QPushButton(centralWidget);
        openFileButton->setObjectName("openFileButton");

        gridLayout_3->addWidget(openFileButton, 0, 3, 1, 1);

        line = new QFrame(centralWidget);
        line->setObjectName("line");
        line->setMinimumSize(QSize(0, 5));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line, 1, 0, 1, 5);


        horizontalLayout->addLayout(gridLayout_3);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName("gridLayout_2");
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName("label_2");
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(label_2, 4, 1, 1, 2);

        clearOutputButton = new QPushButton(centralWidget);
        clearOutputButton->setObjectName("clearOutputButton");

        gridLayout_2->addWidget(clearOutputButton, 4, 3, 1, 1);

        line_3 = new QFrame(centralWidget);
        line_3->setObjectName("line_3");
        line_3->setMinimumSize(QSize(0, 5));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_3, 3, 0, 1, 5);

        outputConsole = new QTextEdit(centralWidget);
        outputConsole->setObjectName("outputConsole");
        QFont font3;
        font3.setPointSize(14);
        outputConsole->setFont(font3);
        outputConsole->setMouseTracking(false);
        outputConsole->setFocusPolicy(Qt::StrongFocus);
        outputConsole->setReadOnly(true);

        gridLayout_2->addWidget(outputConsole, 5, 0, 1, 5);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout_2->addWidget(pushButton_2, 1, 4, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);

        CommandInterpreterQtClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CommandInterpreterQtClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 946, 22));
        CommandInterpreterQtClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CommandInterpreterQtClass);
        mainToolBar->setObjectName("mainToolBar");
        CommandInterpreterQtClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CommandInterpreterQtClass);
        statusBar->setObjectName("statusBar");
        CommandInterpreterQtClass->setStatusBar(statusBar);

        retranslateUi(CommandInterpreterQtClass);
        QObject::connect(pushButton_2, &QPushButton::clicked, CommandInterpreterQtClass, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(CommandInterpreterQtClass);
    } // setupUi

    void retranslateUi(QMainWindow *CommandInterpreterQtClass)
    {
        CommandInterpreterQtClass->setWindowTitle(QCoreApplication::translate("CommandInterpreterQtClass", "CommandInterpreterQt", nullptr));
        pointButton->setText(QCoreApplication::translate("CommandInterpreterQtClass", "Point", nullptr));
        moveButton->setText(QCoreApplication::translate("CommandInterpreterQtClass", "Move", nullptr));
        inputConsole->setHtml(QCoreApplication::translate("CommandInterpreterQtClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI Historic'; font-size:14pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Segoe UI'; font-size:9pt;\"><br /></p></body></html>", nullptr));
        planeButton->setText(QCoreApplication::translate("CommandInterpreterQtClass", "Plane", nullptr));
        clearInputButton->setText(QCoreApplication::translate("CommandInterpreterQtClass", "Clear", nullptr));
        debugButton->setText(QCoreApplication::translate("CommandInterpreterQtClass", "Debug", nullptr));
        circleButton->setText(QCoreApplication::translate("CommandInterpreterQtClass", "Circle", nullptr));
        projectionButton->setText(QCoreApplication::translate("CommandInterpreterQtClass", "Projection", nullptr));
        commentButton->setText(QCoreApplication::translate("CommandInterpreterQtClass", "Comment", nullptr));
        getReportButton->setText(QCoreApplication::translate("CommandInterpreterQtClass", "Get report", nullptr));
        runButton->setText(QCoreApplication::translate("CommandInterpreterQtClass", "Run", nullptr));
        centerButton->setText(QCoreApplication::translate("CommandInterpreterQtClass", "Center", nullptr));
        saveFileButton->setText(QCoreApplication::translate("CommandInterpreterQtClass", "Save file", nullptr));
        label->setText(QCoreApplication::translate("CommandInterpreterQtClass", "<html><head/><body><p align=\"center\">INPUT</p></body></html>", nullptr));
        deviationButton->setText(QCoreApplication::translate("CommandInterpreterQtClass", "Deviation", nullptr));
        openFileButton->setText(QCoreApplication::translate("CommandInterpreterQtClass", "Open file", nullptr));
        label_2->setText(QCoreApplication::translate("CommandInterpreterQtClass", "<html><head/><body><p align=\"center\">OUTPUT</p></body></html>", nullptr));
        clearOutputButton->setText(QCoreApplication::translate("CommandInterpreterQtClass", "Clear", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CommandInterpreterQtClass", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CommandInterpreterQtClass: public Ui_CommandInterpreterQtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMANDINTERPRETERQT_H
