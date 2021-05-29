#include "FormDesktop.h"

FormDesktop::FormDesktop(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    //setStyleSheet("QPushButton{border:2px; border-radius:20px; padding:10px 4px; background-color: red; outline:0px;}");
}
