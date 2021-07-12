#include "headerfiles.h"

void MainWindow::on_Minifying_clicked()
{
    extractLinesFromInputString();
    int size=linesTexts.size();
    string out="";
    for(int i=0;i<size;i++){
        out+=linesTexts[i];
    }
    QString qout = QString::fromStdString(out);
    ui->modifiedXml->setPlainText(qout);
}
