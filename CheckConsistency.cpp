#include "headerfiles.h"

bool classifytag(string word) {
    if((word[0]=='!')||(word[0]=='?')||(word[word.length()-1]=='/')) return 1;
    return 0;
}

void findMistakesLines() {
    extractTagsFromInputString();
    extractTagsNamesFromInputString();
    int size=tagsNames.size();
    //mistakes number 1 mean line number win using 1 index
    stack <pair<string,int>>st;
    for(int i=0;i<size;i++)
    {
        if(classifytag(tags[i]))continue;
        if(tagsNames[i][0]!='/'){
            st.push({tagsNames[i],i});
        }else if(tagsNames[i][0]=='/'){
            if(st.empty()){
                mistakes.push_back(tagsLines[i]);
            }
            else{
                if(tagsNames[i]==("/"+st.top().first))
                    st.pop();
                else{
                    string stTop=st.top().first;
                    int stTopindex=st.top().second;
                    st.pop();
                    string stTop2=st.top().first;
                    if(tagsNames[i]==("/"+stTop2))
                    {
                        solvingLines.push_back(stTopindex);
                        mistakes.push_back(tagsLines[stTopindex]);
                        st.pop();
                    }
                    else{
                        mistakes.push_back(tagsLines[i]);
                    }
                }
            }
        }
    }
    sort(mistakes.begin(), mistakes.end());
}

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




