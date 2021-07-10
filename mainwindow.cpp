#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
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






void LevelOrderTraversal(Node * root)
{
    if (root==NULL)
        return;

    // Standard level order traversal code
    // using queue
    queue<Node *> q;  // Create a queue
    q.push(root); // Enqueue root
    while (!q.empty())
    {
        int n = q.size();

        // If this node has children
        while (n > 0)
        {
            // Dequeue an item from queue and print it
            Node * p = q.front();
            q.pop();
           // cout << p->key << " ";

            // Enqueue all children of the dequeued item
            for (int i=0; i<p->childrenNodes.size(); i++)
               // q.push(p->child[i]);
            n--;
        }

        cout << endl; // Print new line between two levels
    }
}

void MainWindow::on_Check_Consistency_clicked()
{

}

void MainWindow::on_Solve_Errors_clicked()
{

}

void MainWindow::on_Prettifying_clicked()
{

}


void MainWindow::on_XML_To_Json_clicked()
{

}


void MainWindow::on_Minifying_clicked()
{

}


void MainWindow::on_Compressing_clicked()
{

}


void MainWindow::on_Save_clicked()
{

}


void MainWindow::on_Reset_clicked()
{

}

