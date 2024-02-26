#pragma once

#include "ui_CommandInterpreterQt.h"
#include <QtWidgets/QMainWindow>
#include "MeasureMachine.h"
#include "Command.h"
#include "CommentCommand.h"
#include "MoveCommand.h"
#include "PointCommand.h"
#include "CircleCommand.h"
#include "CenterCommand.h"
#include "PlaneCommand.h"
#include "ProjectionCommand.h"
#include "PDeviationCommand.h"
#include "CDeviationCommand.h"
#include "Coordinates.h"
#include <QString>
#include <QMap>
#include <QFileDialog>
#include <QMessagebox>

using namespace std;

class CommandInterpreterQt : public QMainWindow
{
    Q_OBJECT

public:
    CommandInterpreterQt(QWidget *parent = nullptr);
    ~CommandInterpreterQt();
    
private:
    Ui::CommandInterpreterQtClass ui;

    enum Errors {
        existingCommand,
        nonExistentCommand,
        invalidFormat
    };

    QMap<QString, shared_ptr<Command>> commandsHistory;
    QList<shared_ptr<Command>> listForReport;
    int numPreviousLine;
    int numberOfClicks;
    bool hasError;

    void callCommmand(const QStringList &inputCommands, int index);
    void getCommentResults(QString &command, const QStringList &inputCommands, int index);
    void getMoveResults(QString &command, const QStringList &inputCommands, int index);
    void getPointResults(QString &command, const QStringList &inputCommands, int index);
    void getCircleResults(QString &command, const QStringList &inputCommands, int index);
    void getCenterResults(QString &command, const QStringList &inputCommands, int index);
    void getPlaneResults(QString &command, const QStringList &inputCommands, int index);
    void getProjectionResults(QString &command, const QStringList &inputCommands, int index);
    void getDeviationResults(QString& command, const QStringList& inputCommands, int index);
    void throwError(const QString &command, Errors error);
    QString getNumberCommand(QString command);
    bool isNumber(const QString& numCommand);
    void determineColorAndOutputResult(shared_ptr<Command> command);
    bool hasOnlyNumbers(QString command, const QString &nameCommand);
    bool isVectorCorrect(QString &command, const QString &nameCommand);
    bool isDeviationCorrect(const QString &nameCommand, QString strDeviation);
    void processButtonClick(const QString &nameCommand);

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
};
