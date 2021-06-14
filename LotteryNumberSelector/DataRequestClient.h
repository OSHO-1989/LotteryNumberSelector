//
// Created by Administrator on 2021/5/14.
//

#ifndef LOTTERYNUMBERSELECTIONTOOL_DATAREQUESTCLIENT_H
#define LOTTERYNUMBERSELECTIONTOOL_DATAREQUESTCLIENT_H

#include <QObject>
#include <QNetworkAccessManager>

class DataRequestClient : public QObject
{
	Q_OBJECT
public:
	static DataRequestClient* getInstance();
	~DataRequestClient() override;

	void initialize();

	// 获取数据
	void getHistoryData(const QString& url);

	// 解析返回的数据
	void replyFinished(QNetworkReply* reply);

	// 处理ssl错误
	void handleSSLErrors(QNetworkReply* reply, const QList<QSslError>& errors);

protected:
	explicit DataRequestClient(QObject* parent = nullptr);

signals:
	void sendHistoryData(const QString& historyData);

private:
	QNetworkAccessManager* m_pNetworkAccessManager;
};


#endif //LOTTERYNUMBERSELECTIONTOOL_DATAREQUESTCLIENT_H
