#pragma once
#include <QString>
#include <QVector>
#include "LotteryInfo.h"

class JSONParsingTool
{
public:
	static bool parseLotteryInfo(const QString& lotteryContext, QVector<LotteryInfo>& lotteryInfoList);
};

