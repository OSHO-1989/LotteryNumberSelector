//
// Created by Administrator on 2021/5/14.
//
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QMessageBox>
#include "DataRequestClient.h"

DataRequestClient::DataRequestClient(QObject* parent) :
	QObject(parent),
	m_pNetworkAccessManager(nullptr)
{

}

DataRequestClient* DataRequestClient::getInstance()
{
	static DataRequestClient _instance;
	return &_instance;
}

DataRequestClient::~DataRequestClient()
{
	if (m_pNetworkAccessManager != nullptr)
	{
		delete m_pNetworkAccessManager;
		m_pNetworkAccessManager = nullptr;
	}
}

void DataRequestClient::initialize()
{
	if (nullptr == m_pNetworkAccessManager)
	{
		m_pNetworkAccessManager = new QNetworkAccessManager(this);
	}

	connect(m_pNetworkAccessManager, &QNetworkAccessManager::finished, this, &DataRequestClient::replyFinished);
	connect(m_pNetworkAccessManager, &QNetworkAccessManager::sslErrors, this, &DataRequestClient::handleSSLErrors);
}

void DataRequestClient::getHistoryData(const QString& url)
{
	QNetworkRequest request;
	request.setUrl(QUrl(url));
	request.setHeader(QNetworkRequest::UserAgentHeader, "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/90.0.4430.212 Safari/537.36");
	request.setRawHeader("Cookie", "Sites=_21; UniqueID=N5hhf7XNnEFmfMoY1620997453101; _ga=GA1.3.1762038741.1620829912; bdshare_firstime=1620831641847; _gid=GA1.3.2147178836.1620997454; 21_vq=42");
	request.setRawHeader("Connection", "keep-alive");
	request.setRawHeader("Accept", "application/json, text/javascript, */*;q=0.01");
	request.setRawHeader("X-Requested-With", "XMLHttpRequest");
	request.setRawHeader("Accept-Language", "zh-CN,zh;q=0.9");
	request.setRawHeader("X-Requested-With", "XMLHttpRequest");
	request.setRawHeader("Referer", "http://www.cwl.gov.cn/kjxx/ssq/kjgg/");

	m_pNetworkAccessManager->get(request);
}

void DataRequestClient::replyFinished(QNetworkReply* reply)
{ 
	QString requestResultText;
	QNetworkReply::NetworkError error = reply->error();
	if (reply->error() == QNetworkReply::NoError)
	{
		requestResultText = reply->readAll();
	}
	else
	{
		requestResultText = "API Call Failed";
	}

	emit sendHistoryData(requestResultText);
}

void DataRequestClient::handleSSLErrors(QNetworkReply* reply, const QList<QSslError>& errors)
{

}
