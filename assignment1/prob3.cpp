#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n;
	double value1 = 1;
	double value2 = 0;
	double value3 = 0;
	int i, j;
	cout << "n값을 입력해주세요. : ";
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			value1 = value1 * j;
		}
		value2 = 1 / value1;
		value3 = value3 + value2;
		value2 = 0;
		value1 = 1;
	}
	cout << value3;
	return 0;
}