#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	double value = 0;
	int i;
	cout << "n값을 입력하세요. : ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 0)
			value += (double)1 / pow(2, i);
		else value -= (double)1 / pow(2, i);
	}
	value++;
	cout <<"값은 : " << value;
	return 0;

}