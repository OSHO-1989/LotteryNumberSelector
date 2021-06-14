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
	// 初始化数据库环境
	bool initialize();

	// 反初始化
	void deinitialize();

	// 写入历史数据到数据库
	bool writeHistoryData(const QVector<LotteryInfo>& vecLotteryInfo);

	// 读取历史数据到内存
	bool readHistoryData(QVector<LotteryInfo>& vecLotteryInfo);

private:
	// 获取驱动标识名称
	QString getSQLDriversName(SQLDriversIndex sqldindex);

	// 创建数据库对象
	bool createSqlDatabase(SQLDriversIndex sqldindex);

	// 连接数据库
	bool connection();

private:
	QSqlDatabase m_sqlDatabase;
};

