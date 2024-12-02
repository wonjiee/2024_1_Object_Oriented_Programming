#include <iostream>
using namespace std;

int main()
{
	int coef, expo_x, expo_y;
	cin >> coef >> expo_x >> expo_y;
	/* 이 부분에 출력하는 코드를 추가하라 */
	if (coef == 0)
		cout << 0 << endl;
	if (coef == 1) {
		if (expo_x == 0 && expo_y != 0)
			cout << "y^" << expo_y << endl;
		if (expo_x != 0 && expo_y == 0)
			cout << "x^" << expo_x << endl;
		if (expo_x != 0 && expo_y != 0)
			cout << "x^" << expo_x << "y^" << expo_y << endl;
	}
	if (coef == -1)
	{
		if (expo_x == 0 && expo_y != 0)
			cout << "-y^" << expo_y << endl;
		if (expo_x != 0 && expo_y == 0)
			cout << "-x^" << expo_x << endl;
		if (expo_x != 0 && expo_y != 0)
			cout << "-x^" << expo_x << "y^" << expo_y << endl;
	}

	if (coef != -1 && coef != 0 &&coef != 1) {
		if (expo_x == 0)
			if (expo_y == 0)
				cout << coef << endl;
			else if (expo_y == 1)
				cout << coef << "y" << endl;
			else if (expo_y != 1 && expo_y != 0)
				cout << coef << "y^" << expo_y << endl;
		if (expo_x == 1)
			if (expo_y == 0)
				cout << coef << "x" << endl;
			else if (expo_y == 1)
				cout << coef << "x" << "y" << endl;
			else if (expo_y != 1 && expo_y != 0)
				cout << coef << "x" << "y^" << expo_y << endl;
		if (expo_x != 1 && expo_x != 0)
			if (expo_y == 0)
				cout << coef << "x^" << expo_x << endl;
			else if (expo_y == 1)
				cout << coef << "x^" << expo_x << "y" << endl;
			else if (expo_y != 1 && expo_y != 0)
				cout << coef << "x^" << expo_x << "y^" << expo_y << endl;

	}
	return 0;
}