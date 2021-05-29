#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_FormDesktop.h"

class FormDesktop : public QMainWindow
{
    Q_OBJECT

public:
    FormDesktop(QWidget *parent = Q_NULLPTR);

private:
    Ui::FormDesktopClass ui;
};
