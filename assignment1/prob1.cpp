#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "2부터 30사이의 n값을 입력해주세요. : ";
	cin >> n;
	int fa = 1, fb = 1;
	int f = fa + fb;
	if (n <= 30) {
		for (int i = 1; i < n; i++)
		{
			f = fa + fb;
			fa = fb;
			fb = f;
		}
	}
	cout << f;
	return 0;
}