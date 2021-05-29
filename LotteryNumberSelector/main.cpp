#include "FormDesktop.h"
#include <QtWidgets/QApplication>
#include <random>
#include <unordered_set>
#include "DataRequestClient.h"

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

    FormDesktop w;
    w.show();

	DataRequestClient::getInstance()->initialize();
	DataRequestClient::getInstance()->getHistoryData("http://www.cwl.gov.cn/cwl_admin/kjxx/findDrawNotice?name=ssq&issueCount=&issueStart=&issueEnd=&dayStart=2003-02-06&dayEnd=2021-05-14&pageNo=2");

    return a.exec();
}
