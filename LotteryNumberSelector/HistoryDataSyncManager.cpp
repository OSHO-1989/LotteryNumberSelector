#include "HistoryDataSyncManager.h"
#include "DataRequestClient.h"
#include "JSONParsingTool.h"

const QString LOTTERY_REQUEST_URL = "http://www.cwl.gov.cn/cwl_admin/kjxx/findDrawNotice?name=ssq&issueCount=&issueStart=&issueEnd=&dayStart=2003-02-06&dayEnd=2021-06-14&pageNo=";

HistoryDataSyncManager::HistoryDataSyncManager():QObject(nullptr)
{

}

HistoryDataSyncManager* HistoryDataSyncManager::getInstance()
{
	static HistoryDataSyncManager _instance;
	return &_instance;
}

void HistoryDataSyncManager::initialize()
{
	// 初始化数据库连接
	m_objSQLDatabaseConnectManager.initialize();
	DataRequestClient::getInstance()->initialize();

	connect(DataRequestClient::getInstance(), SIGNAL(sendHistoryData(const QString&)), this, SLOT(receiveData(const QString&)));
}

bool HistoryDataSyncManager::readHistoryDataFromSQL(QVector<LotteryInfo>& vecLotteryInfo)
{
	return m_objSQLDatabaseConnectManager.readHistoryData(vecLotteryInfo);
}

void HistoryDataSyncManager::startSyncHistoryDataFromNetwork()
{
	DataRequestClient::getInstance()->getHistoryData(LOTTERY_REQUEST_URL);
}

void HistoryDataSyncManager::receiveData(const QString& historyData)
{
	QVector<LotteryInfo> vecLotteryInfo;
	JSONParsingTool::parseLotteryInfo(historyData, vecLotteryInfo);
	if (m_objSQLDatabaseConnectManager.writeHistoryData(vecLotteryInfo))
	{
		emit syncLotterySuccess();
	}
}
