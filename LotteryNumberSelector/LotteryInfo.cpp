#include "LotteryInfo.h"

void LotteryInfo::setLotteryPeriod(const QString& lotteryPeriod)
{
	m_pstrLotteryPeriod = lotteryPeriod;
}

const QString& LotteryInfo::getLotteryPeriod() const
{
	return m_pstrLotteryPeriod;
}

void LotteryInfo::setDetailsLink(const QString& detailsLink)
{
	m_strDetailsLink = detailsLink;
}

const QString& LotteryInfo::getDetailsLink() const
{
	return m_strDetailsLink;
}

void LotteryInfo::setVideoLink(const QString& videoLink)
{
	m_strVideoLink = videoLink;
}

const QString& LotteryInfo::getVideoLink() const
{
	return m_strVideoLink;
}

void LotteryInfo::setDrawDate(const QString& drawDate)
{
	m_strDrawDate = drawDate;
}

const QString& LotteryInfo::getDrawDate() const
{
	return m_strDrawDate;
}

void LotteryInfo::setRedRedBall(const QString& redRedBall)
{
	m_strRedRedBall = redRedBall;
}

const QString& LotteryInfo::getRedRedBall() const
{
	return m_strRedRedBall;
}

void LotteryInfo::setBlueBall(const QString& blueBall)
{
	m_strBlueBall = blueBall;
}

const QString& LotteryInfo::getBlueBall() const
{
	return m_strBlueBall;
}

void LotteryInfo::setWeek(const QString& week)
{
	m_strWeek = week;
}

const QString& LotteryInfo::getWeek() const
{
	return m_strWeek;
}
