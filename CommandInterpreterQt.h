#pragma once

#include <QtWidgets/QMainWindow>
#include "CommandInterpreterQt.h"
#include "ui_CommandInterpreterQt.h"
#include "MeasureMachine.h"
#include "Report.h"
#include <iostream>
#include <QString>
#include <qmap.h>
#include <algorithm>
#include <tuple>
#include <qhash.h>

class CommandInterpreterQt : public QMainWindow
{
    Q_OBJECT

public:
    CommandInterpreterQt(QWidget *parent = nullptr);
    ~CommandInterpreterQt();
    
private:
    Ui::CommandInterpreterQtClass ui;
    
    MeasureMachine* mMachine{};
    Report* report{};

    enum Errors {
        existingCommand,
        nonExistentCommand,
        invalidFormat
    };
    QHash<QString, tuple<double*, double*>> planeResults;
    QHash<QString, tuple<double*, double*, double*>> circleResults;
    QHash<QString, QString> commandsHistory;
    QHash<int, QHash<QString, QString>> commandsResults;
    int numPreviousLine;
    int sequenceNumber;
    //int numberOfClicks;
    bool hasError;


    
private slots:
    void runButtonClick();
    //void debugButtonClick();
    void saveFileButtonClick();
    void openFileButtonClick();
    void getReportButtonClick();
    void clearInputButtonClick();
    void clearOutputButtonClick();
    void commentButtonClick();
    void moveButtonClick();
    void pointButtonClick();
    void circleButtonClick();
    void centerButtonClick();
    void planeButtonClick();
    void projectionButtonClick();
    void deviationButtonClick();
    void getCommentResults(QString command, QStringList inputCommands, int index);
    void getMoveResults(QString command, QStringList inputCommands, int index);
    void getPointResults(QString command, QStringList inputCommands, int index);
    void getCircleResults(QString command, QStringList inputCommands, int index);
    void getCenterResults(QString command, QStringList inputCommands, int index);
    void getPlaneResults(QString command, QStringList inputCommands, int index);
    void getProjectionResults(QString command, QStringList inputCommands, int index);
    void getDeviationResults(QString command, QStringList inputCommands, int index);
    void throwError(QString command, Errors error);
    QString getNumberCommand(QString command);
    bool isNumber(QString& numCommand);
    void determineColorAndOutputResult(int r, int g, int b, QString nameCommand, QString result);
    bool hasOnlyNumbers(QString command, QString nameCommand);
    bool isVectorCorrect(QString command, QString nameCommand);
    bool isDeviationCorrect(QString nameCommand, QString strDeviation);
    void processButtonClick(QString nameCommand);
};
