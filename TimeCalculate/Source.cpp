#include <iostream>
#include <time.h>

using namespace std;

time_t GetStamp() {
	int year, month, day;
	cout << endl << "年を入力-->";
	cin >> year;
	if (year == 9999) {
		exit(0);
	}
		
	cout << "月を入力-->";
	cin >> month;
	cout << "日を入力-->";
	cin >> day;
	struct tm stm;
	try {
		memset(&stm, 0, sizeof(stm));
		stm.tm_year = year - 1900;
		stm.tm_mon = month - 1;
		stm.tm_mday = day;
		stm.tm_hour = 12;
		return mktime(&stm);
	}
	catch (exception e) {
		return -1;
	}
	
}

char* Date(time_t stamp) {
	time_t tt = stamp;
	char *now = new char[64];
	struct tm* ttime = (struct tm*)malloc(sizeof(struct tm));
	localtime_s(ttime, &stamp);
	strftime(now, 64, "%Y年 %m月 %d日", ttime);
	return now;
}

int main()
{
	cout << "5B-10-姜宇祥" << endl;
	while (true) {
		time_t stamp = GetStamp();
		if (stamp <= 86400) {
			cout << "入力の日は1970年1月2日以降お願いします" << endl;
			continue;
		}
		//cout << stamp << endl;
		cout << "入力の日:" << Date(stamp) << endl;
		cout << "前の日:" << Date(stamp - 24 * 60 * 60) << endl;
		cout << "次の日:" << Date(stamp + 24 * 60 * 60) << endl << endl;
	}

	int key;
	cin >> key;
	return 0;
}