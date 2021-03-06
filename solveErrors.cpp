#include "headerfiles.h"

void MainWindow::on_Solve_Errors_clicked()
{
    // Clear modifiedXML plain text
    ui->modifiedXml->clear();
    QMessageBox message;
    string messageText = to_string(mistakes.size())+" mistakes corrected.\nThe Green lines should be deleted";
    QString QMessageText =QString::fromStdString(messageText);
    message.setText(QMessageText);
    message.exec();
    
    string currentLine;
    QTextCharFormat format;
    QTextCursor cursor( ui->modifiedXml->textCursor());
    int counter = 0;
    for (unsigned int i = 0; i < linesTexts.size() ; i++)
    {
        currentLine = linesTexts[i];
        if(i == mistakes[counter] - 1)
        {
            // Go to the next line have a mistake next time
            counter++;
            /*
            // Change the format of mistaked lines
            format.setForeground(QBrush(QColor(Qt::white)));
            format.setBackground(QBrush(QColor(Qt::green)));
            cursor.setCharFormat(format);
            cursor.insertText(QString::fromStdString(currentLine));
            */
        }
        else
        {
            format.setForeground(QBrush(QColor(Qt::black)));
            format.setBackground(QBrush(QColor(Qt::white)));
            cursor.setCharFormat(format);
            cursor.insertText(QString::fromStdString(currentLine));
        }
        if(cursor.PreviousCharacter != '\n'){cursor.insertText("\n");}
    }
}
