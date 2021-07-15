#include "headerfiles.h"

std::string json = "{";

int tagTypeCheck(QString word) {
    if(word.isEmpty()){return 0;}
    if((word[0]=='<')&&word[word.length()-1]=='>'){
        if(word[1]=='/'){return 2;}//2:closing tag
        if(word[word.length()-2]=='/'){return 4;}//4:singleclosed tag
        if(word[1]=='!'){return 5;}//5:comment tag
        if(word[1]=='?'){return 6;}//6:prolog tag
        return 1;//1:openning tag
    }
    return 3;//3:data tag
}
/**************Generating tree structure**************************/

Node* createNode(string tagData){
    string tagName, tagParameters;
    // Find if the tag have parameters or not
    if(tagData.find('=') == -1){
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

Node* addChild(Node* root,std::string data){
    Node* child = createNode(data);
    root->childrenNodes.push_back(child);
    child->ParentNode=root;
    return child;
}

void addChild(Node* root,Node* child){
    root->childrenNodes.push_back(child);
    return;
}
void BFS(Node * root){
    QTextStream stream(&temporaryFile);
    if (root==NULL)
        return;

    //traverse using queue
    QList<Node *> q;
    q.push_back(root);
    while (!q.empty())
    {
        int n = q.size();
        while (n > 0)
        {
            Node * p = q.front();
            q.pop_front();
            stream << QString::fromStdString(p->tagName) << " ";
            for (unsigned long long i=0; i<p->childrenNodes.size(); i++)
                q.push_back(p->childrenNodes[i]);
            n--;
        }

        stream << "\n";
    }
    return;
}
Node* getParent(Node* root){

    Node* temp = root;
    if(temp->ParentNode != NULL){
        root = temp->ParentNode;
    }
    return root;
}
void showChildren(Node* root){
    temporaryFile.open(QIODevice::ReadWrite |QIODevice::Text);
    QTextStream stream(&temporaryFile);
    int size = root->childrenNodes.size();
    for(int x=0;x<size;x++){
        stream << QString::fromStdString(root->childrenNodes[x]->tagName)<<"\t";
    }
    stream<<"\n";
    temporaryFile.close();
    return;
}

Node* getLastChild(Node* root){

    if(root->childrenNodes.size() == 0){
        return root;
    }
    else return getLastChild(root->childrenNodes[root->childrenNodes.size()-1]);

}
void generateRepeatedChildNode(Node* root){

    if(root->childrenNodes.size() < 1)return;
    std::vector<std::string>temp;
    std::vector<std::string>names;

    for(unsigned int x=0;x<root->childrenNodes.size();x++){
        if(root->childrenNodes[x]->tagName != "*"){
            temp.push_back(root->childrenNodes[x]->tagName);
        }
    }

    for(unsigned int x=0;x<temp.size();x++){
        if(count(temp.begin(),temp.end(),temp[x]) > 1  && count(names.begin(),names.end(),temp[x]) == 0){
            names.push_back(temp[x]);
        }
    }

    for(unsigned int x=0;x<names.size();x++){
        Node* simp = createNode(names[x]);
        for(unsigned int y=0;y<root->childrenNodes.size();y++){
            if(root->childrenNodes[y]->tagName == names[x]){
                root->childrenNodes[y]->tagName = '*';
                root->childrenNodes[y]->ParentNode = simp;
                addChild(simp,root->childrenNodes[y]);
                root->childrenNodes.erase(root->childrenNodes.begin()+y);
                y--;
            }

        }
        addChild(root,simp);
        simp->ParentNode = root;
    }
    return;
}
Node* getMainParent(Node* root){

    Node* temp = root;
    while(1){
        if(temp->ParentNode == NULL){
            break;
        }else{
            temp = temp->ParentNode;
        }
    }
    return temp;
}

Node* buildTree(std::vector<std::string> pureTagsLinesWithoutSlash,Node* current_root){
    std::stack<std::string> temp;

    for(unsigned int x=0;x<pureTagsLinesWithoutSlash.size();x++){

        if(x==0){
            current_root = createNode(pureTagsLinesWithoutSlash[x]);
            current_root->ParentNode = NULL;
            std::stringstream check1(pureTagsLinesWithoutSlash[x]);
            std::string s;
            getline(check1, s, ' ');
            temp.push(s);

            continue;
        }

        if(pureTagsLinesWithoutSlash[x][0] != '~'){
            std::stringstream check1(pureTagsLinesWithoutSlash[x]);
            std::string s;
            getline(check1, s, ' ');
            if(s == temp.top()){
                temp.pop();
                current_root = getParent(current_root);
            }else{
                current_root = addChild(current_root,pureTagsLinesWithoutSlash[x]);
                temp.push(s);
            }
        }else{
            current_root = addChild(current_root,pureTagsLinesWithoutSlash[x].substr(1,pureTagsLinesWithoutSlash[x].length()-1));
            current_root = getParent(current_root);
        }
    }
    return getMainParent(current_root);
}
void refactorTree(Node* root){
    if(root==NULL){return ;}
    generateRepeatedChildNode(root);
    for(unsigned int x=0;x<root->childrenNodes.size();x++){
        refactorTree(root->childrenNodes[x]);
    }
    return;
}

void print(Node* root){
    printNode(root);
    for(unsigned int x=0;x<root->childrenNodes.size();x++){
        print(root->childrenNodes[x]);
    }
}
void makeQutation(Node* root){

    for(unsigned int x=0;x<root->childrenNodes.size();x++){
        if(root->childrenNodes[x]->tagName != "*"){
            root->childrenNodes[x]->tagName = "\"" + root->childrenNodes[x]->tagName + "\"";
        }
        makeQutation(root->childrenNodes[x]);
    }
}
void CreatBracket(Node* root){

    for(unsigned int x=0;x<root->childrenNodes.size();x++){

        bool case2 = (root->childrenNodes.size() >= 1) &&
                (root->childrenNodes[0]->tagName != "*") &&
                (root->childrenNodes[x]->childrenNodes.size() != 0) &&
                (x == root->childrenNodes.size()-1);
        bool case3 = (root->childrenNodes.size() > 1) &&
                (root->childrenNodes[0]->tagName == "*") &&
                (x == root->childrenNodes.size()-1);
        if( case2 ){
            Node* temp = getLastChild(root);
            if(temp->tagName[temp->tagName.length()-1] == ']' ||
                    (temp->tagName[temp->tagName.length()-1] == '}') ){
                int s1 = count(temp->tagName.begin(),temp->tagName.end(),']');
                int s2 = count(temp->tagName.begin(),temp->tagName.end(),'}');
                if(s1<0){s1=0;}
                if(s2<0){s2=0;}
                int sum = s1+s2;
                temp->tagName.insert(temp->tagName.length()-sum,"}");
            }else{
                temp->tagName = temp->tagName + "}";
            }
        }else if( case3 ){
            Node* temp = getLastChild(root->childrenNodes[x]);
            if(temp->tagName[temp->tagName.length()-1] == ']' ||
                    (temp->tagName[temp->tagName.length()-1] == '}') ){
                int s1 = count(temp->tagName.begin(),temp->tagName.end(),']');
                int s2 = count(temp->tagName.begin(),temp->tagName.end(),'}');
                if(s1<0){s1=0;}
                if(s2<0){s2=0;}
                int sum = s1+s2;
                temp->tagName.insert(temp->tagName.length()-sum,"]");
            }else{
                temp->tagName = temp->tagName + "]";
            }
        }
        CreatBracket(root->childrenNodes[x]);
    }
}
void sendRoot(Node* root){

    regulateTags(root);
    for(unsigned int x=0;x<root->childrenNodes.size();x++){
        sendRoot(root->childrenNodes[x]);
    }

}

void printNode(Node* root){
    // output node
    if(root->tagName == "\*"){
        json+=root->tagParameters;
    }

    //output last node
    else if(root->childrenNodes.size() == 0){
        if(root->ParentNode->tagParameters.empty()&&
                (root->tagName[root->tagName.length()-1] != '}' ||
                 root->tagName[root->tagName.length()-1] != ']')){
            json+=root->tagName+",";
        }else if(root->ParentNode->tagParameters.empty()){
            json+=root->tagName;
        }else if(root->ParentNode->tagParameters.empty() &&
                 root->ParentNode->childrenNodes.size()==1 &&
                 (root->tagName[root->tagName.length()-1] != '}' ||
                  root->tagName[root->tagName.length()-1] != ']')){
            json+=root->tagName;
        }else if(!root->ParentNode->tagParameters.empty() &&
                 root->ParentNode->childrenNodes.size()==1 &&
                 (root->tagName[root->tagName.length()-1] != '}' ||
                  root->tagName[root->tagName.length()-1] != ']')){
            json+="\"text\":"+root->tagName+"},";
        }
    }

    //output merged node
    else if(root->childrenNodes.size() >0 && root->childrenNodes[0]->tagName=="\*"){
        json+=root->tagName+":[";
    }

    //output merged node
    else if(root->childrenNodes.size()>=1){
        if(root->tagParameters.empty()){
            json+=root->tagName+":";
        }else if(!root->tagParameters.empty() && root->childrenNodes.size()==1){
            json+=root->tagName+":"+root->tagParameters;
        }else if(!root->tagParameters.empty() && root->childrenNodes.size()>1){
            json+=root->tagName+":"+root->tagParameters;
        }
    }

}
void regulateTags(Node* root){
    if(!root->tagParameters.empty()){
        for(unsigned int x=0;x<root->tagParameters.length();x++){
            if(x == 0){
                root->tagParameters = "{\""+root->tagParameters;
            }
            if(root->tagParameters[x] == ' ' && root->tagParameters[x-1] == '"'){
                root->tagParameters[x]=',';
            }else if(root->tagParameters[x] == '='){
                root->tagParameters[x]=':';
            }
            if(root->tagParameters[x]==','){
                root->tagParameters.insert(x+1,"\"");
            }else if(root->tagParameters[x]==':'){
                root->tagParameters.insert(x,"\"");
                x++;
            }
        }
        root->tagParameters+=",";
    }
}
