#ifndef FILEMANIPULATION_H
#define FILEMANIPULATION_H
#include"mainwindow.h"
extern QString currentFile;
extern QFile temporaryFile;
extern QFile inputFile;

void makef(QFile *iFile,QFile *oFile);
#endif // FILEMANIPULATION_H
