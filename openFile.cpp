// Here we take input from the user and build our main data structures
#include "headerfiles.h"

void MainWindow::on_Open_File_clicked()
{
   //clearing output text to reset
    ui->originalXml->clear();
    QString fileName = QFileDialog::getOpenFileName(this);
    QFile file(fileName);
    currentFile = fileName;
    if(!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file : " + file.errorString());
    }
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString QText = in.readAll();
    inputFile.remove();
    temporaryFile.resize(0);
    file.copy("myfile.txt");
    text = QText.toUtf8().constData();
    //if(text[text.size() - 1] != '\n')text += '\n';
    ui->originalXml->setPlainText(QText);
    ui->originalXml->setPlainText(QText);
    ui->originalXml->setLineWrapMode(QPlainTextEdit::NoWrap);
    file.close();
}
