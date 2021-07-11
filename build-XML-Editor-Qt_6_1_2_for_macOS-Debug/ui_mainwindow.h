/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *Check_Consistency;
    QPushButton *Solve_Errors;
    QPushButton *Prettifying;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_5;
    QTextEdit *textEdit;
    QPushButton *Open_File;
    QTextEdit *textEdit_2;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *XML_To_Json;
    QPushButton *Minifying;
    QPushButton *Compressing;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *Save;
    QPushButton *Reset;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(814, 682);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 490, 761, 31));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        Check_Consistency = new QPushButton(horizontalLayoutWidget);
        Check_Consistency->setObjectName(QString::fromUtf8("Check_Consistency"));

        horizontalLayout_7->addWidget(Check_Consistency);

        Solve_Errors = new QPushButton(horizontalLayoutWidget);
        Solve_Errors->setObjectName(QString::fromUtf8("Solve_Errors"));

        horizontalLayout_7->addWidget(Solve_Errors);

        Prettifying = new QPushButton(horizontalLayoutWidget);
        Prettifying->setObjectName(QString::fromUtf8("Prettifying"));

        horizontalLayout_7->addWidget(Prettifying);

        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 0, 801, 461));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(verticalLayoutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout_5->addWidget(textEdit);

        Open_File = new QPushButton(verticalLayoutWidget);
        Open_File->setObjectName(QString::fromUtf8("Open_File"));

        verticalLayout_5->addWidget(Open_File);

        textEdit_2 = new QTextEdit(verticalLayoutWidget);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));

        verticalLayout_5->addWidget(textEdit_2);

        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(20, 540, 761, 31));
        horizontalLayout_8 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        XML_To_Json = new QPushButton(horizontalLayoutWidget_2);
        XML_To_Json->setObjectName(QString::fromUtf8("XML_To_Json"));

        horizontalLayout_8->addWidget(XML_To_Json);

        Minifying = new QPushButton(horizontalLayoutWidget_2);
        Minifying->setObjectName(QString::fromUtf8("Minifying"));

        horizontalLayout_8->addWidget(Minifying);

        Compressing = new QPushButton(horizontalLayoutWidget_2);
        Compressing->setObjectName(QString::fromUtf8("Compressing"));

        horizontalLayout_8->addWidget(Compressing);

        horizontalLayoutWidget_3 = new QWidget(centralwidget);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(20, 610, 761, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Save = new QPushButton(horizontalLayoutWidget_3);
        Save->setObjectName(QString::fromUtf8("Save"));

        horizontalLayout->addWidget(Save);

        Reset = new QPushButton(horizontalLayoutWidget_3);
        Reset->setObjectName(QString::fromUtf8("Reset"));

        horizontalLayout->addWidget(Reset);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 814, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Check_Consistency->setText(QCoreApplication::translate("MainWindow", "Check Consistency", nullptr));
        Solve_Errors->setText(QCoreApplication::translate("MainWindow", "Solve Errors", nullptr));
        Prettifying->setText(QCoreApplication::translate("MainWindow", "Prettifying", nullptr));
        Open_File->setText(QCoreApplication::translate("MainWindow", "Open File", nullptr));
        XML_To_Json->setText(QCoreApplication::translate("MainWindow", "XML To Json", nullptr));
        Minifying->setText(QCoreApplication::translate("MainWindow", "Minifying", nullptr));
        Compressing->setText(QCoreApplication::translate("MainWindow", "Compressing", nullptr));
        Save->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        Reset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
