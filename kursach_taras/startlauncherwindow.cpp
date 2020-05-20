#include "startlauncherwindow.h"
#include "ui_startlauncherwindow.h"
#include <qmessagebox.h>

StartLauncherWindow::StartLauncherWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartLauncherWindow)
{
    setWindowIcon(QIcon(":icon.png"));
    ui->setupUi(this);

    QPixmap pix("E:/progi/QT_prj/hiih/OSN.png");
    ui->LimurLabel->setPixmap(pix);

    connect(ui->selectFileButton, SIGNAL(clicked()), this, SLOT(slotOpenSelectWindow()));
    connect(ui->aboutButton, SIGNAL(clicked()), this, SLOT(slotOpenAboutMessage()));
    connect(ui->keysButton, SIGNAL(clicked()), this, SLOT(slotOpenKeysMessage()));
    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->openButton, SIGNAL(clicked()), this, SLOT(slotOpenFile()));
    connect(ui->editButton, SIGNAL(clicked()), this, SLOT(slotEditFile()));
    connect(ui->adButton, SIGNAL(clicked()), this, SLOT(advertising()));
    this->setFixedSize(this->size());
}

void StartLauncherWindow::advertising()
{
    QString aboutString = "inst : tarasjj\nvk.com/tarasjj\ntelega :TARASJJ\n";
    QMessageBox  aboutMessage;
    aboutMessage.setText(aboutString);
    aboutMessage.exec();
}

StartLauncherWindow::~StartLauncherWindow()
{
    delete ui;
}

void StartLauncherWindow::slotOpenSelectWindow()
{
    //this->hide();
    fileSelectWindow = new FileSelectWindow();
    fileSelectWindow->show();
    connect(fileSelectWindow, SIGNAL(signalThrowPath(QString)), this, SLOT(slotGetPath(QString)));
}

void StartLauncherWindow::slotOpenAboutMessage()
{
    QString aboutString = "VRML - Browser 'GATTO'\nVersion: 1.01\nTarasVadim\n\n 2020\n\nBSUIR";
    QMessageBox  aboutMessage;
    aboutMessage.setText(aboutString);
    aboutMessage.exec();
}

void StartLauncherWindow::slotOpenKeysMessage()
{
    QString keysString = "Key assignment:\n\n"
                         "1/3           Rotation in the XZ-plane\n"
                         "4/6           Rotation in ZY-plane\n"
                         "7/9           Rotation in the XY-plane\n"
                         "UP/DOWN       Movement relative to Z\n"
                         "LEFT/RIGHT    Movement relative to Y\n"
                         "+/-           Zoom in/Zoom out\n"
                         "Esc           Exit";
    QMessageBox keysMessage;
    keysMessage.setText(keysString);
    keysMessage.exec();
}

void StartLauncherWindow::slotGetPath(QString _filePath)
{
    ui->lineEdit->setText(_filePath);
    fileSelectWindow->hide();
    this->show();
    filePath = _filePath;
}

void StartLauncherWindow::slotEditFile()
{
    #ifdef WIN32
        QProcess::execute("notepad.exe " + filePath);
    #else
        QProcess::execute("libreoffice --writer " + filePath);
    #endif
}

void StartLauncherWindow::slotOpenFile()
{
    QDesktopServices::openUrl(QUrl::fromUserInput(filePath));
}
