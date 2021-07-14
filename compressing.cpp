#include<headerfiles.h>
#include<QDesktopServices>
#include<QUrl>
#include <QThread>
void MainWindow::on_Compressing_clicked()
{
    //QString xmlResultString = ui->modifiedXml->toPlainText();
    //string out = xmlResultString.toUtf8().constData();

    //wirte data to be proceesed be exe in input file
    QFile writingFile("HuffInp.txt");
    writingFile.open(QIODevice::ReadWrite | QIODevice::Text);
    QString inputstring =QString::fromStdString(text);
    writingFile.write(inputstring.toUtf8());
    writingFile.close();


    //run exe file to process the data and get the result
    QFile runexe("xmlpractise.exe");
    runexe.open(QIODevice::ReadOnly | QIODevice::Text);
    QDesktopServices::openUrl(QUrl("xmlpractise.exe",QUrl::TolerantMode));
    runexe.close();
    unsigned long sl=1;
    QThread::sleep(sl);



    //reading output result
    QFile readingFile("HuffRes.txt");
    readingFile.open(QIODevice::ReadOnly | QFile::Text);
    QTextStream mm(& readingFile);
    QString result = mm.readAll();


    //reset all files
    readingFile.remove();
    readingFile.close();
    writingFile.open(QIODevice::ReadWrite | QIODevice::Text);
    writingFile.remove();
    writingFile.close();



    QTextCharFormat format;
    QTextCursor cursor( ui->modifiedXml->textCursor());
    format.setForeground(QBrush(QColor(Qt::black)));
    format.setBackground(QBrush(QColor(Qt::white)));
    cursor.setCharFormat(format);
    ui->modifiedXml->clear();
    cursor.insertText(result);
}
