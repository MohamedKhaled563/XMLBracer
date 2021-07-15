#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H
#include"mainwindow.h"
//Functions
int tagTypeCheck(QString word);
Node* createNode(string data);
Node* addChild(Node* root,string data);
void addChild(Node* root,Node* child);
void showChildren(Node* root);
Node* getParent(Node* root);
void BFS(Node * root);
Node* getMainParent(Node* root);
Node* getLastChild(Node* root);
Node* buildTree(vector<string> pureTagsLinesWithoutSlash,Node* current_root);
void generateRepeatedChildNode(Node* root);
void refactorTree(Node* root);

void correctMistakes();
void findMistakesLines();
void makeQutation(Node* root);
void CreatBracket(Node* root);
void printNode(Node* root);
void print(Node* root);
void makeJson(Node* root);
void regulateTags(Node* root);
void sendRoot(Node* root);
void GetMistakesLines();

extern string json;
#endif // HELPERFUNCTIONS_H
