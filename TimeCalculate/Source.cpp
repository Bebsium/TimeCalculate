#include <iostream>
#include <time.h>

using namespace std;

time_t GetStamp() {
	int year, month, day;
	cout << endl << "�N�����-->";
	cin >> year;
	if (year == 9999) {
		exit(0);
	}
		
	cout << "�������-->";
	cin >> month;
	cout << "�������-->";
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
	strftime(now, 64, "%Y�N %m�� %d��", ttime);
	return now;
}

int main()
{
	cout << "5B-10-�I�F��" << endl;
	while (true) {
		time_t stamp = GetStamp();
		if (stamp <= 86400) {
			cout << "���͂̓���1970�N1��2���ȍ~���肢���܂�" << endl;
			continue;
		}
		//cout << stamp << endl;
		cout << "���͂̓�:" << Date(stamp) << endl;
		cout << "�O�̓�:" << Date(stamp - 24 * 60 * 60) << endl;
		cout << "���̓�:" << Date(stamp + 24 * 60 * 60) << endl << endl;
	}

	int key;
	cin >> key;
	return 0;
}