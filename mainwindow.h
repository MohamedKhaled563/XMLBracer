#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <sstream>
#include <QtDebug>
#include <QProcess>
#include<QMessageBox>
#include<queue>
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Open_File_clicked();

    void on_Check_Consistency_clicked();

    void on_Prettifying_clicked();

    void on_Solve_Errors_clicked();

    void on_XML_To_Json_clicked();

    void on_Minifying_clicked();

    void on_Compressing_clicked();

    void on_Save_clicked();

    void on_Reset_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::MainWindow *ui;
    QString currentFile="";
};
#endif // MAINWINDOW_H
