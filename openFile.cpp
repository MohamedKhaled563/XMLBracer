// Here we take input from the user and build our main data structures

#include "mainwindow.h"
#include "ui_mainwindow.h"

//Data Structure
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

void extractLinesFromInputString() {
    // Splitting data into lines
    linesTexts.clear();
    int start, end = -1;
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
    tags.resize(0);
    for(unsigned long long i = 0; i < linesTexts.size(); i++){
        int numberOfTagsInLines = std::count(linesTexts[i].begin(), linesTexts[i].end(), '<');
        int tagStart = linesTexts[i].find('<');
        int tagEnd = linesTexts[i].find('>');

        for(int j = 0; j < numberOfTagsInLines ; j++){
            tags.push_back(linesTexts[i].substr(tagStart + 1,tagEnd - tagStart - 1));

            int newStart = linesTexts[i].find('<' , tagStart + 1);
            int newEnd = linesTexts[i].find('>' , tagEnd + 1);
            tagStart = newStart;
            tagEnd = newEnd;
        }
    }
}



void extractTagsWithBodiesFromInputString() {
    vector<string> TWithB;
    tagsWithBodies.resize(0);
    for(unsigned long long i = 0; i < linesTexts.size(); i++){
        int numberOfTagsInLines = std::count(linesTexts[i].begin(), linesTexts[i].end(), '<');
        int tagStart = linesTexts[i].find('<');
        int tagEnd = linesTexts[i].find('>');

        for(int j = 0; j < numberOfTagsInLines ; j++){
            TWithB.push_back(linesTexts[i].substr(tagStart + 1,tagEnd - tagStart - 1));

            if(linesTexts[i][tagEnd+1] != '<'){
                int temp = linesTexts[i].find('<',tagStart + 1);
                TWithB.push_back("~"+linesTexts[i].substr(tagEnd + 1,temp - tagEnd - 1));
            }

            int newStart = linesTexts[i].find('<' , tagStart + 1);
            int newEnd = linesTexts[i].find('>' , tagEnd + 1);
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
    tagsNames.resize(0);
    for(unsigned long long i = 0; i < tags.size(); i++){
        if(!tags[i].empty()){
            // It there is space, there is a paramiters list
            if(tags[i].find(' ') != string::npos){
                string tagName = tags[i].substr(0,tags[i].find(' '));
                tagsNames.push_back(tagName);
            }else{
                tagsNames.push_back(tags[i]);
            }
        }
    }
}

void extractOpenningTagsAndAttributesAndClosedTagsWithoutSlashesOrBodyFromInputString() {
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


void MainWindow::on_Open_File_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    QFile file(fileName);
    currentFile = fileName;
    if(!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file : " + file.errorString());
    }
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString QText = in.readAll();
    text = QText.toUtf8().constData();
    if(text[text.size() - 1] != '\n')
        text += '\n';
    ui->textEdit->setText(QText);
    file.close();

    // Building our data structures
    extractLinesFromInputString();
    extractTagsFromInputString();
    extractTagsWithBodiesFromInputString();
    extractTagsNamesFromInputString();
    extractOpenningTagsAndAttributesAndClosedTagsWithoutSlashesOrBodyFromInputString();
}





//Tree Implementation
struct Node{
    string tagName;
    string tagParameters;
    Node* parentNode;
    vector<Node *> childrenNodes;
};

Node* makeNewNode(std::string tagData){
    string tagName, tagParameters;
    // Find if the tag have parameters or not
    if(tagData.find('=') == -1)// No parameters
    {
        Node* newNode = new Node;
        newNode->tagName = tagData;
        return newNode;
    }else{
        // find start point of parameters
        int index = tagData.find(' ');
        tagName = tagData.substr(0,index);
        tagParameters = tagData.substr(index+1,tagData.length()-1);
        Node* newNode = new Node;
        newNode->tagName = tagName;
        newNode->tagParameters = tagParameters;
        return newNode;
    }
}

Node* addChildren(Node* rootNode,std::string tagData){
    Node* childNode = makeNewNode(tagData);
    rootNode->childrenNodes.push_back(childNode);
    childNode->parentNode=rootNode;
    return childNode;
}





