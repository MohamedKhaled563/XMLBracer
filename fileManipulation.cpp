#include "headerfiles.h"

// Files management
QString currentFile="";
QFile temporaryFile("out.txt");
QFile inputFile("myfile.txt");

void makef(QFile *iFile,QFile *oFile){
    (*iFile).open(QIODevice::ReadWrite |QIODevice::Text);
    (*oFile).open(QIODevice::ReadWrite |QIODevice::Text);
    //change output stream to oFile
    QString line;
    QTextStream oStream(oFile);
    QChar temp;

    while (!inputFile.atEnd())
    { line = inputFile.readLine();

        for (auto i:line)
        {
           if(i=='\n'||i=='\t'){temp=i;continue;}
           if((i=='<')&&(temp=='\n')){oStream<<i;temp=i;continue;}
           if((i=='<')&&(temp=='>')){oStream<<'\n'<<i;temp=i;continue;}
           if(i=='>'){oStream<<i<<'\n';temp=i;continue;}
           oStream<<i;
        }
    }

    (*iFile).close();
    (*oFile).close();
}
