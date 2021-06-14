#pragma once
#include <QObject>
#include "SQLDatabaseConnectManager.h"
#include "LotteryInfo.h"
#include <QVector>

class HistoryDataSyncManager : public QObject
{
	Q_OBJECT

public:
	// ��ȡʵ��
	static HistoryDataSyncManager* getInstance();

	// ��ʼ��
	void initialize();

	// �����ݿ��ȡ��Ʊ����
	bool readHistoryDataFromSQL(QVector<LotteryInfo>& vecLotteryInfo);

	// ��������ͬ������
	void startSyncHistoryDataFromNetwork();

signals:
	void syncLotterySuccess();

public slots:
	void receiveData(const QString& historyData);

protected:
	HistoryDataSyncManager();

private:
	SQLDatabaseConnectManager m_objSQLDatabaseConnectManager;  // ���ݿ����
};
