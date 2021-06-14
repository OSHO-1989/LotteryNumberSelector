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
	QString m_pstrLotteryPeriod; // ������
	QString m_strDetailsLink;	// ������������
	QString m_strVideoLink;		// ������Ƶ��������
	QString m_strDrawDate;		// ��������
	QString m_strWeek;			// ���ڼ�
	QString m_strRedRedBall;	// �������
	QString m_strBlueBall;		// �������
};
