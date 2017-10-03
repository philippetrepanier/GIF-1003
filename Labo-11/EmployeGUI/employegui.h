#ifndef EMPLOYEGUI_H
#define EMPLOYEGUI_H

#include <QtGui/QMainWindow>
#include "ui_employegui.h"

class EmployeGUI : public QMainWindow
{
    Q_OBJECT

public:
    EmployeGUI(QWidget *parent = 0);
    ~EmployeGUI();

private:
    Ui::EmployeGUIClass ui;
};

#endif // EMPLOYEGUI_H
