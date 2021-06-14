#include "FormDesktop.h"
#include <QtWidgets/QApplication>
#include <random>
#include <unordered_set>
#include "UIResourceHelper.h"
#include "HistoryDataSyncManager.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	std::unordered_set<int> rnds;
	std::default_random_engine eng;
	std::uniform_int_distribution<int> dist{ 1, 33 };
	constexpr int NUMS = 6;
	while (rnds.size() <= NUMS) 
	{
		rnds.insert(dist(eng));
	}

	HistoryDataSyncManager::getInstance()->initialize();
	HistoryDataSyncManager::getInstance()->startSyncHistoryDataFromNetwork();

    FormDesktop w;
    w.show();

	UIResourceHelper uiHelper;
	uiHelper.setStyleSheet(":/ApplicationStyle/Resources/Styles/ApplicationStyles.qss");

    return a.exec();
}
