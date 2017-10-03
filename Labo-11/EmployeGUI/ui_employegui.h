/********************************************************************************
** Form generated from reading UI file 'employegui.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEGUI_H
#define UI_EMPLOYEGUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmployeGUIClass
{
public:
    QAction *actionQuitter;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *EmployeGUIClass)
    {
        if (EmployeGUIClass->objectName().isEmpty())
            EmployeGUIClass->setObjectName(QString::fromUtf8("EmployeGUIClass"));
        EmployeGUIClass->resize(800, 600);
        actionQuitter = new QAction(EmployeGUIClass);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        centralwidget = new QWidget(EmployeGUIClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        EmployeGUIClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(EmployeGUIClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 27));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        EmployeGUIClass->setMenuBar(menubar);
        statusbar = new QStatusBar(EmployeGUIClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        EmployeGUIClass->setStatusBar(statusbar);

        menubar->addAction(menuFichier->menuAction());
        menuFichier->addAction(actionQuitter);

        retranslateUi(EmployeGUIClass);
        QObject::connect(actionQuitter, SIGNAL(triggered()), EmployeGUIClass, SLOT(close()));

        QMetaObject::connectSlotsByName(EmployeGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *EmployeGUIClass)
    {
        EmployeGUIClass->setWindowTitle(QApplication::translate("EmployeGUIClass", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("EmployeGUIClass", "Quitter", 0, QApplication::UnicodeUTF8));
        menuFichier->setTitle(QApplication::translate("EmployeGUIClass", "Fichier", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EmployeGUIClass: public Ui_EmployeGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEGUI_H
