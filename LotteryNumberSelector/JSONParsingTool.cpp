#include "JSONParsingTool.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

bool JSONParsingTool::parseLotteryInfo(const QString& lotteryContext, QVector<LotteryInfo>& lotteryInfoList)
{
	QJsonParseError parseError;
	QJsonDocument document = QJsonDocument::fromJson(lotteryContext.toStdString().data(), &parseError);
	if (parseError.error != QJsonParseError::NoError)
	{
		qDebug() << parseError.errorString();
		return false;
	}

	QJsonObject rootObject = document.object();
	if (rootObject.contains("state") && rootObject["state"].isDouble())
	{
		if (rootObject["state"].toInt() != 0)
		{
			return false;
		}
	}

	if (rootObject.contains("result") && rootObject["result"].isArray())
	{
		QJsonArray resultArray = rootObject["result"].toArray();
		for (int resultIndex = 0; resultIndex < resultArray.size(); ++resultIndex)
		{
			LotteryInfo lotteryInfo;
			QJsonObject lotteryObject = resultArray[resultIndex].toObject();
			if (lotteryObject.contains("code") && lotteryObject["code"].isString())
			{
				lotteryInfo.setLotteryPeriod(lotteryObject["code"].toString());
			}
			if (lotteryObject.contains("detailsLink") && lotteryObject["detailsLink"].isString())
			{
				lotteryInfo.setDetailsLink(lotteryObject["detailsLink"].toString());
			}
			if (lotteryObject.contains("videoLink") && lotteryObject["videoLink"].isString())
			{
				lotteryInfo.setVideoLink(lotteryObject["videoLink"].toString());
			}
			if (lotteryObject.contains("date") && lotteryObject["date"].isString())
			{
				lotteryInfo.setDrawDate(lotteryObject["date"].toString());
			}
			if (lotteryObject.contains("red") && lotteryObject["red"].isString())
			{
				lotteryInfo.setRedRedBall(lotteryObject["red"].toString());
			}
			if (lotteryObject.contains("blue") && lotteryObject["blue"].isString())
			{
				lotteryInfo.setBlueBall(lotteryObject["blue"].toString());
			}
			if (lotteryObject.contains("week") && lotteryObject["week"].isString())
			{
				lotteryInfo.setWeek(lotteryObject["week"].toString());
			}

			lotteryInfoList.push_back(lotteryInfo);
		}
	}

	return true;
}
