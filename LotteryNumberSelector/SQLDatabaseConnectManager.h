#pragma once
#include <QStringList>
#include <QSqlDatabase>
#include "LotteryInfo.h"

class SQLDatabaseConnectManager
{
public:
	enum class SQLDriversIndex
	{
		SQL_DRIVERS_SQLITE,
		SQL_DRIVERS_MYSQL,
		SQL_DRIVERS_MYSQL3,
		SQL_DRIVERS_PGSQL,
		SQL_DRIVERS_PGSQL7,
		SQL_DRIVERS_ODBC,
		SQL_DRIVERS_ODBC3
	};

public:
	// ��ʼ�����ݿ⻷��
	bool initialize();

	// ����ʼ��
	void deinitialize();

	// д����ʷ���ݵ����ݿ�
	bool writeHistoryData(const QVector<LotteryInfo>& vecLotteryInfo);

	// ��ȡ��ʷ���ݵ��ڴ�
	bool readHistoryData(QVector<LotteryInfo>& vecLotteryInfo);

private:
	// ��ȡ������ʶ����
	QString getSQLDriversName(SQLDriversIndex sqldindex);

	// �������ݿ����
	bool createSqlDatabase(SQLDriversIndex sqldindex);

	// �������ݿ�
	bool connection();

private:
	QSqlDatabase m_sqlDatabase;
};

