#include "headerfiles.h"

void MainWindow::on_Solve_Errors_clicked()
{
    // Clear modifiedXML plain text
    ui->modifiedXml->clear();
    
    string messageText = to_string(solvingLines.size())+" mistakes corrected.\n The red lines will be deleted";
    QString QMessageText =QString::fromStdString(messageText);
    message.setText(QMessageText);
    message.exec();
    
    string currentLine;
    QTextCharFormat format;
    QTextCursor cursor( ui->modifiedXml->textCursor());
    int counter = 0;
    for (unsigned int i = 1; i < linesTexts.size() + 1; i++)
    {
        currentLine = linesTexts[i-1];
        if(i == mistakes[counter])
        {
            // Go to the next line have a mistake next time
            counter++;
            // Change the format of mistaked lines
            format.setForeground(QBrush(QColor(Qt::white)));
            format.setBackground(QBrush(QColor(Qt::green)));
            cursor.setCharFormat(format);
            cursor.insertText(QString::fromStdString(currentLine));
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
