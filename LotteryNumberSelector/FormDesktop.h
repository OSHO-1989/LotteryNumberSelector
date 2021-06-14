#pragma once

#include <QtWidgets/QMainWindow>
#include <QMap>
#include <QStringList>  
#include "ui_FormDesktop.h"

class FormDesktop : public QMainWindow
{
    Q_OBJECT

public:
    FormDesktop(QWidget *parent = Q_NULLPTR);

    // �������ݵ�UI
    void loadDataToUI();

private:
    Ui::FormDesktopClass ui;
    QMap<QStringList, QString> m_mapHistoryLotteryData; // ǰ10���Ʊ����
};
