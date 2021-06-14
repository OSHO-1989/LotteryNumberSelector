#include <QSet>
#include "FormDesktop.h"
#include "HistoryDataSyncManager.h"

FormDesktop::FormDesktop(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	initUI();
	connectSignalsAndSlots();
}

void FormDesktop::loadDataToUI()
{
	QVector<LotteryInfo> vecLotteryInfo;
	HistoryDataSyncManager::getInstance()->readHistoryDataFromSQL(vecLotteryInfo);
	loadRedBallHistoryData(vecLotteryInfo);
	loadOmissionRedBallHistoryData();
	loadOmissionBlueBallHIstoryData();
}

void FormDesktop::loadRedBallHistoryData(const QVector<LotteryInfo>& vecLotteryInfo)
{
	m_mapHistoryLotteryData.clear();
	QVector<LotteryInfo> tempVecLotteryInfo(5);
	std::copy(vecLotteryInfo.begin(), vecLotteryInfo.begin() + 5, tempVecLotteryInfo.begin());
	for (auto& item : tempVecLotteryInfo)
	{
		QString bludBall = item.getBlueBall();
		QString redBall = item.getRedRedBall();
		QStringList redBallList = redBall.split(",");
		m_mapHistoryLotteryData[redBallList] = bludBall;
	}

	QSet<QString> redBlueBallSet;
	QSet<QString> blueBallList;
	for (auto iter = m_mapHistoryLotteryData.cbegin(); iter != m_mapHistoryLotteryData.cend(); ++iter)
	{
		QStringList redBallList = iter.key();
		QStringList::const_iterator constIterator;
		for (constIterator = redBallList.constBegin(); constIterator != redBallList.constEnd(); ++constIterator)
		{
			redBlueBallSet.insert(*constIterator);
		}
		blueBallList.insert(iter.value());
	}

	for (auto& item : redBlueBallSet)
	{
		QString blueBall = item;
		if (blueBall == "01")
		{
			ui.pushButton_r1->setChecked(true);
		}
		else if (blueBall == "02")
		{
			ui.pushButton_r2->setChecked(true);
		}
		else if (blueBall == "03")
		{
			ui.pushButton_r3->setChecked(true);
		}
		else if (blueBall == "04")
		{
			ui.pushButton_r4->setChecked(true);
		}
		else if (blueBall == "05")
		{
			ui.pushButton_r5->setChecked(true);
		}
		else if (blueBall == "06")
		{
			ui.pushButton_r6->setChecked(true);
		}
		else if (blueBall == "07")
		{
			ui.pushButton_r7->setChecked(true);
		}
		else if (blueBall == "08")
		{
			ui.pushButton_r8->setChecked(true);
		}
		else if (blueBall == "09")
		{
			ui.pushButton_r9->setChecked(true);
		}
		else if (blueBall == "10")
		{
			ui.pushButton_r10->setChecked(true);
		}
		else if (blueBall == "11")
		{
			ui.pushButton_r11->setChecked(true);
		}
		else if (blueBall == "12")
		{
			ui.pushButton_r12->setChecked(true);
		}
		else if (blueBall == "13")
		{
			ui.pushButton_r13->setChecked(true);
		}
		else if (blueBall == "14")
		{
			ui.pushButton_r14->setChecked(true);
		}
		else if (blueBall == "15")
		{
			ui.pushButton_r15->setChecked(true);
		}
		else if (blueBall == "16")
		{
			ui.pushButton_r16->setChecked(true);
		}
		else if (blueBall == "17")
		{
			ui.pushButton_r17->setChecked(true);
		}
		else if (blueBall == "18")
		{
			ui.pushButton_r18->setChecked(true);
		}
		else if (blueBall == "19")
		{
			ui.pushButton_r19->setChecked(true);
		}
		else if (blueBall == "20")
		{
			ui.pushButton_r20->setChecked(true);
		}
		else if (blueBall == "21")
		{
			ui.pushButton_r21->setChecked(true);
		}
		else if (blueBall == "22")
		{
			ui.pushButton_r22->setChecked(true);
		}
		else if (blueBall == "23")
		{
			ui.pushButton_r23->setChecked(true);
		}
		else if (blueBall == "24")
		{
			ui.pushButton_r24->setChecked(true);
		}
		else if (blueBall == "25")
		{
			ui.pushButton_r25->setChecked(true);
		}
		else if (blueBall == "26")
		{
			ui.pushButton_r26->setChecked(true);
		}
		else if (blueBall == "27")
		{
			ui.pushButton_r27->setChecked(true);
		}
		else if (blueBall == "28")
		{
			ui.pushButton_r28->setChecked(true);
		}
		else if (blueBall == "29")
		{
			ui.pushButton_r29->setChecked(true);
		}
		else if (blueBall == "30")
		{
			ui.pushButton_r30->setChecked(true);
		}
		else if (blueBall == "31")
		{
			ui.pushButton_r31->setChecked(true);
		}
		else if (blueBall == "32")
		{
			ui.pushButton_r32->setChecked(true);
		}
		else if (blueBall == "33")
		{
			ui.pushButton_r33->setChecked(true);
		}
	}

	loadBlueBallHistoryData(blueBallList);
}

void FormDesktop::loadBlueBallHistoryData(const QSet<QString>& blueBallList)
{
	for (auto& item : blueBallList)
	{
		QString blueBall = item;
		if (blueBall == "01")
		{
			ui.pushButton_b1->setChecked(true);
		}
		else if (blueBall == "02")
		{
			ui.pushButton_b2->setChecked(true);
		}
		else if (blueBall == "03")
		{
			ui.pushButton_b3->setChecked(true);
		}
		else if (blueBall == "04")
		{
			ui.pushButton_b4->setChecked(true);
		}
		else if (blueBall == "05")
		{
			ui.pushButton_b5->setChecked(true);
		}
		else if (blueBall == "06")
		{
			ui.pushButton_b6->setChecked(true);
		}
		else if (blueBall == "07")
		{
			ui.pushButton_b7->setChecked(true);
		}
		else if (blueBall == "08")
		{
			ui.pushButton_b8->setChecked(true);
		}
		else if (blueBall == "09")
		{
			ui.pushButton_b9->setChecked(true);
		}
		else if (blueBall == "10")
		{
			ui.pushButton_b10->setChecked(true);
		}
		else if (blueBall == "11")
		{
			ui.pushButton_b11->setChecked(true);
		}
		else if (blueBall == "12")
		{
			ui.pushButton_b12->setChecked(true);
		}
		else if (blueBall == "13")
		{
			ui.pushButton_b13->setChecked(true);
		}
		else if (blueBall == "14")
		{
			ui.pushButton_b14->setChecked(true);
		}
		else if (blueBall == "15")
		{
			ui.pushButton_b15->setChecked(true);
		}
		else if (blueBall == "16")
		{
			ui.pushButton_b16->setChecked(true);
		}
	}
}

void FormDesktop::loadOmissionRedBallHistoryData()
{

}

void FormDesktop::loadOmissionBlueBallHIstoryData()
{

}

void FormDesktop::initUI()
{
	ui.pushButton_r1->setDisabled(true);
	ui.pushButton_r2->setDisabled(true);
	ui.pushButton_r3->setDisabled(true);
	ui.pushButton_r4->setDisabled(true);
	ui.pushButton_r5->setDisabled(true);
	ui.pushButton_r6->setDisabled(true);
	ui.pushButton_r7->setDisabled(true);
	ui.pushButton_r8->setDisabled(true);
	ui.pushButton_r9->setDisabled(true);
	ui.pushButton_r10->setDisabled(true);
	ui.pushButton_r11->setDisabled(true);
	ui.pushButton_r12->setDisabled(true);
	ui.pushButton_r13->setDisabled(true);
	ui.pushButton_r14->setDisabled(true);
	ui.pushButton_r15->setDisabled(true);
	ui.pushButton_r16->setDisabled(true);
	ui.pushButton_r17->setDisabled(true);
	ui.pushButton_r18->setDisabled(true);
	ui.pushButton_r19->setDisabled(true);
	ui.pushButton_r20->setDisabled(true);
	ui.pushButton_r21->setDisabled(true);
	ui.pushButton_r22->setDisabled(true);
	ui.pushButton_r23->setDisabled(true);
	ui.pushButton_r24->setDisabled(true);
	ui.pushButton_r25->setDisabled(true);
	ui.pushButton_r26->setDisabled(true);
	ui.pushButton_r27->setDisabled(true);
	ui.pushButton_r28->setDisabled(true);
	ui.pushButton_r29->setDisabled(true);
	ui.pushButton_r30->setDisabled(true);
	ui.pushButton_r31->setDisabled(true);
	ui.pushButton_r32->setDisabled(true);
	ui.pushButton_r33->setDisabled(true);

	ui.pushButton_b1->setDisabled(true);
	ui.pushButton_b2->setDisabled(true);
	ui.pushButton_b3->setDisabled(true);
	ui.pushButton_b4->setDisabled(true);
	ui.pushButton_b5->setDisabled(true);
	ui.pushButton_b6->setDisabled(true);
	ui.pushButton_b7->setDisabled(true);
	ui.pushButton_b8->setDisabled(true);
	ui.pushButton_b9->setDisabled(true);
	ui.pushButton_b10->setDisabled(true);
	ui.pushButton_b11->setDisabled(true);
	ui.pushButton_b12->setDisabled(true);
	ui.pushButton_b13->setDisabled(true);
	ui.pushButton_b14->setDisabled(true);
	ui.pushButton_b15->setDisabled(true);
	ui.pushButton_b16->setDisabled(true);
}

void FormDesktop::connectSignalsAndSlots()
{
	connect(HistoryDataSyncManager::getInstance(), SIGNAL(syncLotterySuccess()), this, SLOT(loadDataToUI()));
}
