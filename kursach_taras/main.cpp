#include <QApplication>
#include "startlauncherwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartLauncherWindow *startLauncherWindow = new StartLauncherWindow();

    startLauncherWindow->show();

    return a.exec();
}
