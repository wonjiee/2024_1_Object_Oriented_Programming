#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int user_compare(int a, int b) {
	int value1 = a, value2 = b;
	int count1 = 1, count2 = 1;

	while (true) {
		if (value1 > 9) {
			value1 = value1 / 10;
			count1++;
			continue;
		}
		if (value2 > 9) {
			value2 = value2 / 10;
			count2++;
			continue;
		}
		if (count1 == count2) {
			if (a < b)
				return -1;
			if (a > b)
				return 1;
			if (a == b)
				return 0;
		}
		if (value1 < value2)
			return -1;
		if (value1 > value2)
			return 1;
		if (value1 == value2) {
			if (count1 == 1 && count2 != 1)
				return -1;
			if (count1 != 1 && count2 == 1)
				return 1;
			if (count1 == 1 && count2 == 1)
				return 0;
			if (count1 != 1 && count2 != 1) {
				value1 = a - pow(10, count1 - 1);
				a = a - pow(10, count1 - 1);
				value2 = b - pow(10, count2 - 1);
				b = b - pow(10, count2 - 1);
				count1 = 1; count2 = 1;
				continue;
			}
		}
	}
}
int main() {
	int N;
	cin >> N;
	vector<int>data(N);
	for (int i = 0; i < N; i++)
		cin >> data[i];
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++) {
			int temp1 = data[i];
			int temp2 = data[j];
			if (user_compare(temp1, temp2) == 1) {
				data[i] = temp2;
				data[j] = temp1;
			}
		}
	for (int i = 0; i < N; i++)
		cout << data[i] << " ";
	return 0;

}