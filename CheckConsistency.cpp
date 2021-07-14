#include "headerfiles.h"

bool classifytag(string word) {
    if((word[0]=='!')||(word[0]=='?')||(word[word.length()-1]=='/')) return 1;
    return 0;
}

//
//
//
//
//
// This function implementation need to be added
// This function will go through all tags in file and store lines that have mistakes in "mistakes" vector
void findMistakesLines() {
    
}
//
//
//
//
//

void MainWindow::on_Check_Consistency_clicked()
{
    // Clear result text
    ui->modifiedXml->clear();
    extractLinesFromInputString();
    findMistakesLines();

    // If no mistakes found, display correct message
    QMessageBox message;
    if(mistakes.size() == 0)
    {
        message.setText("No mistakes found in XML file.");
        message.exec();
    }
    // If there are errors, show them and display mistakes message
    else
    {
        string messageText = to_string(mistakes.size())+" mistakes found in XML file.";
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
                format.setBackground(QBrush(QColor(Qt::red)));
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
}




