#include <QSet>
#include "FormDesktop.h"
#include "HistoryDataSyncManager.h"

FormDesktop::FormDesktop(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);


    connect(HistoryDataSyncManager::getInstance(), SIGNAL(syncLotterySuccess()), this, SLOT(loadDataToUI()));
}

void FormDesktop::loadDataToUI()
{
	QVector<LotteryInfo> vecLotteryInfo;
	HistoryDataSyncManager::getInstance()->readHistoryDataFromSQL(vecLotteryInfo);
	QVector<LotteryInfo> tempVecLotteryInfo;
	std::copy(vecLotteryInfo.begin(), vecLotteryInfo.begin() + 5, tempVecLotteryInfo.begin());
	for (auto &item: tempVecLotteryInfo)
	{
		QString bludBall = item.getBlueBall();
		QString redBall = item.getRedRedBall();
		QStringList redBallList = redBall.split(",");
		m_mapHistoryLotteryData.insert(redBallList, bludBall);
	}

	QSet<QString> redBlueBallSet;
	QSet<QString> bludeBallList;
	for (auto iter = m_mapHistoryLotteryData.cbegin(); iter != m_mapHistoryLotteryData.cend(); ++iter)
	{
		QStringList redBallList = iter.key();
		QStringList::const_iterator constIterator;
		for (constIterator = redBallList.constBegin(); constIterator != redBallList.constEnd(); ++constIterator)
		{
			redBlueBallSet.insert(*constIterator);
		}
		bludeBallList.insert(iter.value());
	}
	

}
