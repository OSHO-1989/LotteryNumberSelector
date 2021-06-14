#pragma once

#include <QtWidgets/QMainWindow>
#include <QMap>
#include <QStringList>  
#include "ui_FormDesktop.h"
#include "LotteryInfo.h"

class FormDesktop : public QMainWindow
{
    Q_OBJECT

public:
    FormDesktop(QWidget *parent = Q_NULLPTR);

    // 加载数据到UI
public slots:
    void loadDataToUI();
    void loadRedBallHistoryData(const QVector<LotteryInfo>& vecLotteryInfo);
    void loadBlueBallHistoryData(const QSet<QString>& blueBallList);
    void loadOmissionRedBallHistoryData();
    void loadOmissionBlueBallHIstoryData();
    
private:
    void initUI();
    void connectSignalsAndSlots();

private:
    Ui::FormDesktopClass ui;
    QMap<QStringList, QString> m_mapHistoryLotteryData; // 前10组彩票数据
};
