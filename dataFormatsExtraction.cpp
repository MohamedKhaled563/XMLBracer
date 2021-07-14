#include "mainwindow.h"

// Files management
QString currentFile="";
QFile mytempfile("out.txt");
QFile myfile("myfile.txt");

// Data Structure
string text;
// Input file as lines
vector<string> linesTexts;
// Input file as tags
vector<string> tags;
// Input file as tags with bodies
vector<string> tagsWithBodies;
// Tag Names
vector<string> tagsNames;
// openning tag with attributes and closing tag without slash
vector<string> openningTagsAndAttributesAndClosedTagsWithoutSlashesOrBody;
// This vector holds lines that need to be solved
vector <int> solvingLines;

// Datastructire manipulation
void extractLinesFromInputString(){

    // Splitting data into lines
    linesTexts.clear();
    int start, end = -1;
    //iterate over all chracters until new line character then append it into "lineTexts" vector
    for (int i = 0; i < text.size(); i++) {
        if (text[i] == '\n') {
            start = text.find_first_not_of ({' '}, end + 1);
            end = i;
            string lineString = text.substr(start,end - start);
            linesTexts.push_back(lineString);
        }
    }
}
void extractTagsFromInputString() {
    vector<string> TWithB;
    // Initially there are no tags
    tags.resize(0);
    // itirate over all lines in xml file and extract tags from it and add it to "tags" vector
    for(unsigned long long i = 0; i < linesTexts.size(); i++){
        int numberOfTagsInLines = std::count(linesTexts[i].begin(), linesTexts[i].end(), '<');
        int tagStart = linesTexts[i].find('<');
        int tagEnd = linesTexts[i].find('>');
        // Itirate over each tag in line
        int j = numberOfTagsInLines;
        while (numberOfTagsInLines--){
            tags.push_back(linesTexts[i].substr(tagStart + 1,tagEnd - tagStart - 1));
            int newStart = linesTexts[i].find('<' , tagStart + 1);
            int newEnd = linesTexts[i].find('>' , tagEnd + 1);
            // Update indexes
            tagStart = newStart;
            tagEnd = newEnd;
        }
    }
}

void extractTagsWithBodiesFromInputString(){
    vector<string> TWithB;
    // Initially there are no tags
    tagsWithBodies.resize(0);
    // itirate over all lines in xml file and extract tags from it and add it to "tags" vector
    for(unsigned long long i = 0; i < linesTexts.size(); i++){
        int numberOfTagsInLines = std::count(linesTexts[i].begin(), linesTexts[i].end(), '<');
        int tagStart = linesTexts[i].find('<');
        int tagEnd = linesTexts[i].find('>');
        // Itirate over each tag in line
        int j = numberOfTagsInLines;
        while (numberOfTagsInLines--){
            TWithB.push_back(linesTexts[i].substr(tagStart + 1,tagEnd - tagStart - 1));
            if(linesTexts[i][tagEnd+1] != '<'){
                int temp = linesTexts[i].find('<',tagStart + 1);
                TWithB.push_back("~"+linesTexts[i].substr(tagEnd + 1,temp - tagEnd - 1));
            }
            int newStart = linesTexts[i].find('<' , tagStart + 1);
            int newEnd = linesTexts[i].find('>' , tagEnd + 1);
            // Update indexes
            tagStart = newStart;
            tagEnd = newEnd;
        }
    }
    for(unsigned long long i = 0; i < TWithB.size(); i++){
        if(!((TWithB[i][0] == '~') && (TWithB[i].length() == 1)) ){
            tagsWithBodies.push_back(TWithB[i]);
        }
    }
}

void extractTagsNamesFromInputString(){
    // Initially there are no tags
    tagsNames.resize(0);
    for(unsigned long long i = 0; i < tags.size(); i++){
        if(!tags[i].empty()){
            // It there is space, there is a paramiters list
            if(tags[i].find(' ') != string::npos){
                string tagName = tags[i].substr(0,tags[i].find(' '));
                tagsNames.push_back(tagName);
            }
            else{
                tagsNames.push_back(tags[i]);
            }
        }
    }
}

void extractOpenningTagsAndAttributesAndClosedTagsWithoutSlashesOrBodyFromInputString(){
    // Initially there are no tags
    openningTagsAndAttributesAndClosedTagsWithoutSlashesOrBody.resize(0);
    for (int i = 0; i < tagsWithBodies.size(); i++){
        if(tagsWithBodies[i][0] == '/'){
            openningTagsAndAttributesAndClosedTagsWithoutSlashesOrBody.push_back(tagsWithBodies[i].substr(1,tagsWithBodies[i].length()-1));
        }
        else {
            if(tagsWithBodies[i][0] != '~'){
                openningTagsAndAttributesAndClosedTagsWithoutSlashesOrBody.push_back(tagsWithBodies[i]);
            }
        }
    }
}
