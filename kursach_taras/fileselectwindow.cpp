#include "fileselectwindow.h"
#include "ui_fileselectwindow.h"

FileSelectWindow::FileSelectWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FileSelectWindow)
{
    ui->setupUi(this);

    model = new QDirModel;
    model->setReadOnly(false);
    ui->treeView->setModel(model);
    ui->treeView->hideColumn(1);
    ui->treeView->hideColumn(2);
    ui->treeView->hideColumn(3);
    ui->treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(ui->treeView, SIGNAL(activated(QModelIndex)), this, SLOT(slotOnDoubleClicked(QModelIndex)));
    index = ui->treeView->currentIndex();

    connect(ui->backButton, SIGNAL(clicked()), this, SLOT(slotOpenStartWindow()));
}

FileSelectWindow::~FileSelectWindow()
{
    delete ui;
}

void FileSelectWindow::slotOpenStartWindow()
{
    this->hide();
    startLauncherWindow = new StartLauncherWindow();
    startLauncherWindow->show();
}

void FileSelectWindow::slotOnDoubleClicked(QModelIndex index)
{
    QFileInfo fileInfo(model->filePath(index));
    if(!fileInfo.isDir())
        signalThrowPath(fileInfo.absoluteFilePath());
}


