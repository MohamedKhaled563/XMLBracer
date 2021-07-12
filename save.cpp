#include "headerfiles.h"

void MainWindow::on_Save_clicked()
{
    QFile resultXML(QFileDialog::getSaveFileName(this,
                                                 tr("Save File"),
                                                 "",
                                                 tr("Text()*.txt;;XML()*.xml")));

    resultXML.open(QIODevice::ReadWrite|QIODevice::Text);
    QString xmlResultString = ui->modifiedXml->toPlainText();
    resultXML.write(xmlResultString.toUtf8());
    resultXML.close();
}
