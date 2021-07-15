#include "headerfiles.h"

void MainWindow::on_Minifying_clicked()
{

    QTextCharFormat format;
    QTextCursor cursor( ui->modifiedXml->textCursor());

    format.setForeground(QBrush(QColor(Qt::black)));
    format.setBackground(QBrush(QColor(Qt::white)));
    cursor.setCharFormat(format);
    ui->modifiedXml->clear();
    extractLinesFromInputString();
    int size=linesTexts.size();
    string out="";
    for(int i=0;i<size;i++){
        out+=linesTexts[i];
    }
    QString qout = QString::fromStdString(out);
    ui->modifiedXml->clear();
    cursor.insertText(QString::fromStdString(out));
}
