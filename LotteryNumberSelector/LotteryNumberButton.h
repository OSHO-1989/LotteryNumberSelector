#pragma once

#include <QPushButton>

class LotteryNumberButton : public QPushButton
{
	Q_OBJECT

public:

	//Q_PROPERTY(QString numberType READ getNumberType WRITE setNumberType RESET unsetNumberType);


	LotteryNumberButton(QWidget *parent);
	~LotteryNumberButton();
};
