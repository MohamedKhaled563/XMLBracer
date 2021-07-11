#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

extern string text;
extern vector<string> linesTexts;
extern vector<string> tags;
extern vector<string> tagsWithBodies;
extern vector<string> tagsNames;
extern vector<string> openningTagsAndAttributesAndClosedTagsWithoutSlashesOrBody;

MainWindow::~MainWindow()
{
    delete ui;
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

void MainWindow::print (vector<string> v) {
    string str = "";
    for (int i = 0; i <  v.size(); i++) {
        str += v[i];
        str += '\n';
    }
    ui->textEdit_2->setText(QString::fromStdString(str));
}
void MainWindow::on_Save_clicked()
{
    print(openningTagsAndAttributesAndClosedTagsWithoutSlashesOrBody);
}


void MainWindow::on_Reset_clicked()
{

}

