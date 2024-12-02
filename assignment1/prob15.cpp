#include <iostream>
#include <vector>
using namespace std;

int main() {
	int count1 = 0;
	int count2 = 0;
	int value = 1;
	int N;
	cout << "N을 입력하세요. : " << endl;
	cin >> N;
	vector<int> data(N);
	for (int i = 1; i <= N; i++) {
		count1 = 0;
		value = i;
		while (value >= 10)
		{
			data[count1] = value % 10;
			value = value / 10.0;
			count1++;
		}
		if (value < 10)
		{
			data[count1] = value;
			count1++;
		}
		for (int j = 0; j < count1; j++)
			if (data[j] == 0)
				count2++;
	}
	cout << count2;
	return 0;
}
