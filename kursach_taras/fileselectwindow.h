#ifndef FILESELECTWINDOW_H
#define FILESELECTWINDOW_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <qfilesystemmodel.h>
#include "ui_startlauncherwindow.h"
#include "startlauncherwindow.h"
#include "qfileinfo.h"
#include <QDirModel>

class StartLauncherWindow;

namespace Ui {
class FileSelectWindow;
}

class FileSelectWindow : public QDialog
{
    Q_OBJECT

public:
    explicit FileSelectWindow(QWidget *parent = 0);
    ~FileSelectWindow();

public slots:
    void slotOpenStartWindow();
    void slotOnDoubleClicked(QModelIndex index);

private:
    Ui::FileSelectWindow *ui;
    QDirModel *model;
    StartLauncherWindow *startLauncherWindow;

    QModelIndex index;
    QFileSystemModel *filemodel;

signals:
    void signalThrowPath(QString string);
};

#endif // FILESELECTWINDOW_H
