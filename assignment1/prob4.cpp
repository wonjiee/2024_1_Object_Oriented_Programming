#include <iostream>

using namespace std;
int main()
{
	int a, b, c;
	cout << "세 정수를 입력해주세요. : ";
	cin >> a >> b >> c;
	int a_1 = a, b_1 = b, c_1 = c;

	while (!(a_1 <= b_1 && b_1 <= c_1)) {
		a_1 = b, b_1 = a;
		if (a_1 <= b_1 && b_1 <= c_1)
			break;
		b_1 = c, c_1 = a;
		a = a_1, b = b_1, c = c_1;
	}
	a = a_1, b = b_1, c = c_1;
	cout << a << b << c << endl;
	return 0;
}