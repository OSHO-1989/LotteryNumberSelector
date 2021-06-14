#pragma once
#include <QObject>
#include "SQLDatabaseConnectManager.h"
#include "LotteryInfo.h"
#include <QVector>

class HistoryDataSyncManager : public QObject
{
	Q_OBJECT

public:
	// 获取实例
	static HistoryDataSyncManager* getInstance();

	// 初始化
	void initialize();

	// 从数据库获取彩票数据
	bool readHistoryDataFromSQL(QVector<LotteryInfo>& vecLotteryInfo);

	// 从网络上同步数据
	void startSyncHistoryDataFromNetwork();

signals:
	void syncLotterySuccess();

public slots:
	void receiveData(const QString& historyData);

protected:
	HistoryDataSyncManager();

private:
	SQLDatabaseConnectManager m_objSQLDatabaseConnectManager;  // 数据库管理
};
