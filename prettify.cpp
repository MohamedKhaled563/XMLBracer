#include "headerfiles.h"

void MainWindow::on_Prettifying_clicked()
{
    QTextCursor cursor( ui->modifiedXml->textCursor() );
    QTextCharFormat format;
    format.setFontWeight( QFont::TypeWriter );
    ui->modifiedXml->clear();
    ui->modifiedXml->setLineWrapMode(QPlainTextEdit::NoWrap);
    QFile tagsfile("mytags.txt");
    tagsfile.resize(0);
    makef(&inputFile,&tagsfile);
    temporaryFile.resize(0);
    temporaryFile.open(QIODevice::ReadWrite |QIODevice::Text);
    QTextStream str(&temporaryFile);
    tagsfile.open(QIODevice::ReadOnly |QIODevice::Text);
    QString currentWord,previousWord;
    int level = 0;
    int currentTagType,previousTagType;
    int maxBlockCount=ui->originalXml->blockCount();
    if(maxBlockCount<5000){
        while (!tagsfile.atEnd()){
            format.setForeground( QBrush( QColor(Qt::blue) ) );
            currentWord = tagsfile.readLine().trimmed();
            if(currentWord.isEmpty()){continue;}
            //check tagtype for this tag
            currentTagType=tagTypeCheck(currentWord);
            //check tagtype for previoius tag
            previousTagType=tagTypeCheck(previousWord);
            //Opening Tag
            if(currentTagType==1){
                if(previousTagType==0){
                    cursor.setCharFormat( format );
                    cursor.insertText( currentWord );
                    level++;
                }
                else if(previousTagType==1){
                    cursor.insertText("\n");
                    for(int i=0;i<level;i++){cursor.insertText("  ");}
                    cursor.setCharFormat( format );
                    cursor.insertText( currentWord );
                    level++;
                }
                else{
                    cursor.insertText("\n");
                    for(int i=0;i<level;i++){cursor.insertText("  ");}
                    cursor.setCharFormat( format );
                    cursor.insertText( currentWord );
                    level++;
                }
            }
            //Closing Tag
            else if (currentTagType==2){
                if(previousTagType==1){
                    cursor.setCharFormat( format );
                    cursor.insertText( currentWord );
                    level--;
                }
                if(previousTagType==2){
                    level--;
                    cursor.insertText("\n");
                    for(int i=0;i<level;i++){cursor.insertText("  ");}
                    cursor.setCharFormat( format );
                    cursor.insertText( currentWord );
                }
                else{

                    cursor.setCharFormat( format );
                    cursor.insertText( currentWord );
                    level--;
                }
            }
            //Tag data or Value
            else if(currentTagType==3){

                format.setForeground( QBrush( QColor(Qt::black) ) );
                cursor.setCharFormat(format);
                cursor.insertText( currentWord );
            }
            //Lone tag
            else if(currentTagType==4){

                cursor.insertText("\n");
                for(int i=0;i<level;i++){cursor.insertText("  ");}
                format.setForeground( QBrush( QColor(Qt::darkMagenta) ) );
                cursor.setCharFormat( format );
                cursor.insertText( currentWord );
            }
            //comment or prolog
            else {
                cursor.insertText("\n");
                format.setForeground( QBrush( QColor(Qt::darkGreen) ) );
                cursor.setCharFormat( format );
                cursor.insertText( currentWord );
            }
            previousWord=currentWord;
        }
        cursor.~QTextCursor();
        format.setForeground( QBrush( QColor(Qt::black) ) );
        ui->modifiedXml->setCurrentCharFormat(format);
    }
    else{
        format.setForeground( QBrush( QColor(Qt::black) ) );
        while (!tagsfile.atEnd()){
            currentWord = tagsfile.readLine().trimmed();
            if(currentWord.isEmpty()){continue;}
            currentTagType=tagTypeCheck(currentWord);
            previousTagType=tagTypeCheck(previousWord);

            //opening
            if(currentTagType==1){
                if(previousTagType==0){
                    str<<currentWord;
                    level=level+1;
                }
                else if(previousTagType==1){
                    str<<"\n";
                    for(int i=0;i<level;i++){str<<"  ";}
                    str<<currentWord;
                    level=level+1;
                }
                else{
                    str<<"\n";
                    for(int i=0;i<level;i++){str<<"  ";}
                    str<<currentWord;
                    level=level+1;
                }
            }
            //closing
            else if (currentTagType==2){
                if(previousTagType==1){
                    str<<currentWord;
                    level=level-1;
                }
                if(previousTagType==2){
                    level=level-1;
                    str<<"\n";
                    for(int i=0;i<level;i++){str<<"  ";}
                    str<<currentWord;
                }
                else{
                    str<<currentWord;
                    level=level-1;
                }
            }
            //value
            else if(currentTagType==3){
                str<<currentWord;
            }
            //lone tag
            else if(currentTagType==4){
                str<<"\n";
                for(int i=0;i<level;i++){str<<"  ";}
                str<<currentWord;
            }
            //comment or prolog
            else {
                str<<"\n";
                str<<currentWord;
            }
            previousWord=currentWord;
        }
        temporaryFile.close();
        temporaryFile.open(QIODevice::ReadWrite |QIODevice::Text);
        QTextStream strq(&temporaryFile);
        ui->modifiedXml->clear();
        QString t=strq.readAll();
        ui->modifiedXml->setPlainText(t);
    }
    tagsfile.close();
    temporaryFile.close();

}
