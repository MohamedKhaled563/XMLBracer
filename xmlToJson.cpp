#include "headerfiles.h"

void makeJson(Node* root){
    root->tagName = "\"" + root->tagName + "\"";
    makeQutation(root);
    makeBrackets(root);
    print(root);
    json[json.length()-1] = '}';
    return;
}
void initDS(){
    extractLinesFromInputString();
    extractTagsFromInputString();
    extractTagsWithBodiesFromInputString();
    extractTagsNamesFromInputString();
    extractOpenningTagsAndAttributesAndClosedTagsWithoutSlashesOrBodyFromInputString();
}
void resetDs(){
    openningTagsAndAttributesAndClosedTagsWithoutSlashesOrBody.resize(0);
    tagsWithBodies.resize(0);
    tagsNames.resize(0);
    linesTexts.resize(0);
    tags.resize(0);
}
void MainWindow::on_XML_To_Json_clicked(){
    temporaryFile.resize(0);
    temporaryFile.open(QIODevice::ReadWrite |QIODevice::Text);
    QTextStream st(& temporaryFile);
    initDS();
    Node* current_root = NULL;
    current_root = buildTree(openningTagsAndAttributesAndClosedTagsWithoutSlashesOrBody,current_root);
    refactorTree(current_root);
    sendRoot(current_root);
    makeJson(current_root);
    st<<QString::fromStdString(json);
    temporaryFile.close();
    temporaryFile.open(QIODevice::ReadWrite |QIODevice::Text);
    QTextStream strq(&temporaryFile);
    ui->modifiedXml->setLineWrapMode(QPlainTextEdit::LineWrapMode::NoWrap);
    ui->modifiedXml->clear();
    QString out=strq.readAll();
    QChar prevchar;
    int level=0;
    for(auto x:out){
        if(x=='{'){
            ui->modifiedXml->insertPlainText(x);
            ui->modifiedXml->insertPlainText("\n");
            level=level+1;
        }
        else if(x=='}'){
            ui->modifiedXml->insertPlainText("\n");
            ui->modifiedXml->insertPlainText(x);
            level=level-1;}
        else if(x=='['){
            ui->modifiedXml->insertPlainText(x);
            ui->modifiedXml->insertPlainText("\n");
            level=level+1;}
        else if(x==']'){
            ui->modifiedXml->insertPlainText("\n");
            ui->modifiedXml->insertPlainText(x);
            level=level-1;}
        else if(x==','){
            ui->modifiedXml->insertPlainText(x);
            ui->modifiedXml->insertPlainText("\n");
        }
        else {ui->modifiedXml->insertPlainText(x);}
        prevchar=x;
    }
    temporaryFile.close();
    json = "{";
    resetDs();
    return;
}
