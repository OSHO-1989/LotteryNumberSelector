#pragma once
#include <QString>

class LotteryInfo
{
public:
	void setLotteryPeriod(const QString& lotteryPeriod);
	const QString& getLotteryPeriod() const;

	void setDetailsLink(const QString& detailsLink);
	const QString& getDetailsLink() const;

	void setVideoLink(const QString& videoLink);
	const QString& getVideoLink() const;

	void setDrawDate(const QString& drawDate);
	const QString& getDrawDate() const;

	void setRedRedBall(const QString& redRedBall);
	const QString& getRedRedBall() const;

	void setBlueBall(const QString& blueBall);
	const QString& getBlueBall() const;

	void setWeek(const QString& week);
	const QString& getWeek() const;

private:
	QString m_pstrLotteryPeriod; // 开奖期
	QString m_strDetailsLink;	// 开奖详情链接
	QString m_strVideoLink;		// 开奖视频详情链接
	QString m_strDrawDate;		// 开奖日期
	QString m_strWeek;			// 星期几
	QString m_strRedRedBall;	// 红球号码
	QString m_strBlueBall;		// 蓝球号码
};
