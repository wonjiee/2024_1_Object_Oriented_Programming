#include <iostream>

using namespace std;

int main() {
	int year, month, day;
	int year1, month1, day1;
	cin >> year >> month >> day;
	cin >> year1 >> month1 >> day1;
	if (year > year1)
		cout << 1;
	else if (year < year1)
		cout << -1;
	else {
		if (month > month1)
			cout << 1;
		else if (month < month1)
			cout << -1;
		else {
			if (day > day1)
				cout << 1;
			else if (day < day1)
				cout << -1;
			else cout << 0;
		}
	}
	return 0;
}