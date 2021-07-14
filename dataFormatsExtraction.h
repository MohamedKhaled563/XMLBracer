#ifndef DATAFORMATSEXTRACTION_H
#define DATAFORMATSEXTRACTION_H
#include"mainwindow.h"

//Data Structure
extern string text;
// Input file as lines
extern vector<string> linesTexts;
// Input file as tags
extern vector<string> tags;
// Input file as tags with bodies
extern vector<string> tagsWithBodies;
// Tag Names
extern vector<string> tagsNames;
// openning tag with attributes and closing tag without slash
extern vector<string> openningTagsAndAttributesAndClosedTagsWithoutSlashesOrBody;
// This vector holds lines that need to be solved
extern vector <int> solvingLines;

extern QString currentFile;
extern QFile mytempfile;
extern QFile myfile;

// Data structure manipulation
void extractLinesFromInputString();
void extractTagsFromInputString();
void extractTagsWithBodiesFromInputString();
void extractTagsNamesFromInputString();
void extractOpenningTagsAndAttributesAndClosedTagsWithoutSlashesOrBodyFromInputString();
#endif // DATAFORMATSEXTRACTION_H



