#ifndef STARTLAUNCHERWINDOW_H
#define STARTLAUNCHERWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QProcess>
#include <QUrl>
#include <QDesktopServices>
#include "ui_fileselectwindow.h"
#include "fileselectwindow.h"

class FileSelectWindow;

namespace Ui {
class StartLauncherWindow;
}

class StartLauncherWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartLauncherWindow(QWidget *parent = 0);
    ~StartLauncherWindow();

private slots:
    void slotOpenSelectWindow();
    void slotOpenAboutMessage();
    void slotOpenKeysMessage();
    void slotGetPath(QString _filePath);
    void slotOpenFile();
    void slotEditFile();
     void advertising();

private:
    Ui::StartLauncherWindow *ui;
    FileSelectWindow *fileSelectWindow;
    QString filePath;
};

#endif // STARTLAUNCHERWINDOW_H
