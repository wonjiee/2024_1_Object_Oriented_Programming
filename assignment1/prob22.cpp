#include <iostream>
using namespace std;

int main() {
	int data[100];
	int value = 0; /*보유하고 있는 주식의 가치*/
	int count = 0;
	int money = 0; /*얻은 이익*/
	int N = 0;
	for (int i = 0; i >= 0; i++) {
		cin >> data[i];
		if (data[i] == -1)
			break;
		count++;
	}
	for (int j = 0; j < count; j++)
		if (data[j] <= data[j + 1]&&j<count) {
			value = data[j];
			N = j;
			break;
		}

	for (int k = N + 1; k < count; k++) {
		if (value != 0&& value <= data[k]) {
			money += data[k] - value;
			value = 0;
		}
		if (value == 0)
			if (data[k] <= data[k + 1] && k < count) {
				value = data[k];
			}
	}
	cout << money;
	return 0;

}