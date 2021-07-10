#include "mainwindow.h"
#include "ui_mainwindow.h"
void MainWindow::on_Open_File_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    QFile file(fileName);
    currentFile = fileName;
    if(!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file : " + file.errorString());
    }
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}
