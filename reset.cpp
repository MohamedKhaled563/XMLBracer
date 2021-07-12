#include "headerfiles.h"

void MainWindow::on_Reset_clicked()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}
