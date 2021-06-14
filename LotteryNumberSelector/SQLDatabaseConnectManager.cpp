#include "SQLDatabaseConnectManager.h"
#include <QSql>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlField>

bool SQLDatabaseConnectManager::initialize()
{
	if (!createSqlDatabase(SQLDriversIndex::SQL_DRIVERS_ODBC3))
	{
		return false;
	}

	m_sqlDatabase.setHostName("127.0.0.1"); //设置连接主机名
	QString dsn = "DRIVER={SQL SERVER};SERVER=127.0.0.1;DATABASE=LotteryDataTable;UID=sa;PWD=128821";
	m_sqlDatabase.setDatabaseName(dsn);   //设置连接的数据库名
	if (!connection())
	{
		return false;
	}

	return true;
}

void SQLDatabaseConnectManager::deinitialize()
{
	QSqlDatabase::removeDatabase("QODBC");
}

QString SQLDatabaseConnectManager::getSQLDriversName(SQLDriversIndex sqldindex)
{
	QStringList drivers = QSqlDatabase::drivers();
	switch (sqldindex)
	{
	case SQLDriversIndex::SQL_DRIVERS_SQLITE:
		return drivers.contains("QSQLITE") ? "QSQLITE" : "";
	case SQLDriversIndex::SQL_DRIVERS_MYSQL:
		return drivers.contains("QMYSQL") ? "QMYSQL" : "";
	case SQLDriversIndex::SQL_DRIVERS_MYSQL3:
		return drivers.contains("QMYSQL3") ? "QMYSQL3" : "";
	case SQLDriversIndex::SQL_DRIVERS_PGSQL:
		return drivers.contains("QPSQL") ? "QPSQL" : "";
	case SQLDriversIndex::SQL_DRIVERS_PGSQL7:
		return drivers.contains("QPSQL7") ? "QPSQL7" : "";
	case SQLDriversIndex::SQL_DRIVERS_ODBC:
		return drivers.contains("QODBC") ? "QODBC" : "";
	case SQLDriversIndex::SQL_DRIVERS_ODBC3:
		return drivers.contains("QODBC3") ? "QODBC3" : "";
	default:
		return "";
	}
}

bool SQLDatabaseConnectManager::createSqlDatabase(SQLDriversIndex sqldindex)
{
	QString databaseName = getSQLDriversName(sqldindex);
	if (databaseName.isEmpty())
	{
		return false;
	}
	m_sqlDatabase = QSqlDatabase::addDatabase(databaseName);

	return true;
}

bool SQLDatabaseConnectManager::connection()
{
	if (!m_sqlDatabase.open())
	{
		QSqlError sqlError = m_sqlDatabase.lastError();
		qDebug() << sqlError.text();
		return false;
	}

	return true;
}

bool SQLDatabaseConnectManager::writeHistoryData(const QVector<LotteryInfo>& vecLotteryInfo)
{
	for each (auto item in vecLotteryInfo)
	{
		QSqlQuery query;
		query.prepare("INSERT INTO dbo.table_name (code, detailsLink, videoLink, date, week, red, blue) "
			"VALUES (?, ?, ?, ?, ?, ?, ?)");
		query.bindValue(0, item.getLotteryPeriod());
		query.bindValue(1, item.getDetailsLink());
		query.bindValue(2, item.getVideoLink());
		query.bindValue(3, item.getDrawDate());
		query.bindValue(4, item.getWeek());
		query.bindValue(5, item.getRedRedBall());
		query.bindValue(6, item.getBlueBall());
		query.exec();
	}

	return true;
}

bool SQLDatabaseConnectManager::readHistoryData(QVector<LotteryInfo>& vecLotteryInfo)
{
	QSqlQuery query;
	if (query.exec("select * from dbo.table_name order by code desc"))
	{
		while (query.next())
		{
			QSqlRecord rec = query.record();
			LotteryInfo objLotteryInfo;
			for (int i = 0; i < rec.count(); ++i)//将每行的每一列结果得出来
			{
				qDebug() << rec.field(i).name() << ": " << query.value(i).toString();//表第i个字段的内容
				if (rec.field(i).name() == "code")
				{
					objLotteryInfo.setLotteryPeriod(query.value(i).toString());
				}
				else if (rec.field(i).name() == "detailsLink")
				{
					objLotteryInfo.setDetailsLink(query.value(i).toString());
				}
				else if (rec.field(i).name() == "videoLink")
				{
					objLotteryInfo.setVideoLink(query.value(i).toString());
				}
				else if (rec.field(i).name() == "date")
				{
					objLotteryInfo.setDrawDate(query.value(i).toString());
				}
				else if (rec.field(i).name() == "week")
				{
					objLotteryInfo.setWeek(query.value(i).toString());
				}
				else if (rec.field(i).name() == "red")
				{
					objLotteryInfo.setRedRedBall(query.value(i).toString());
				}
				else if (rec.field(i).name() == "blue")
				{
					objLotteryInfo.setBlueBall(query.value(i).toString());
				}
			}

			vecLotteryInfo.push_back(objLotteryInfo);
		}
	}

	return true;
}
