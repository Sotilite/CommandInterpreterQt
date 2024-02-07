#pragma once

#include "ui_CommandInterpreterQt.h"
#include <QtWidgets/QMainWindow>
#include "CommandInterpreterQt.h"
#include "MeasureMachine.h"
#include "Report.h"
#include "Data.h"
#include "Coordinates.h"
#include <iostream>
#include <qstring.h>
#include <qmap.h>
#include <algorithm>
#include <tuple>
#include <qfileDialog.h>
#include <qmessagebox.h>

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
    QMap<QString, Data::Circle> circleResults;
    QMap<QString, Data::Plane> planeResults;
    QMap<QString, QString> commandsHistory;
    QMap<int, QMap<QString, QString>> commandsResults;
    int numPreviousLine;
    int sequenceNumber;
    int numberOfClicks;
    bool hasError;
    
private slots:
    void runButtonClick();
    void debugButtonClick();
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
    void callCommmand(const QStringList &inputCommands, int index);
    void getCommentResults(QString &command, const QStringList &inputCommands, int index);
    void getMoveResults(QString &command, const QStringList &inputCommands, int index);
    void getPointResults(QString &command, const QStringList &inputCommands, int index);
    void getCircleResults(QString &command, const QStringList &inputCommands, int index);
    void getCenterResults(QString &command, const QStringList &inputCommands, int index);
    void getPlaneResults(QString &command, const QStringList &inputCommands, int index);
    void getProjectionResults(QString &command, const QStringList &inputCommands, int index);
    void getDeviationResults(QString &command, const QStringList &inputCommands, int index);
    void throwError(const QString &command, Errors error);
    QString getNumberCommand(QString command);
    bool isNumber(const QString& numCommand);
    void determineColorAndOutputResult(int r, int g, int b, const QString &nameCommand, const QString & result);
    bool hasOnlyNumbers(QString command, const QString &nameCommand);
    bool isVectorCorrect(QString &command, const QString &nameCommand);
    bool isDeviationCorrect(const QString &nameCommand, QString strDeviation);
    void processButtonClick(const QString &nameCommand);
};
