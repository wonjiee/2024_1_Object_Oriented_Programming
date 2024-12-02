#include <iostream>
using namespace std;

int main() {
	int data[7];
	int count = 1;
	for (int i = 0; i < 7; i++)
		cin >> data[i];
	for (int i = 0; i < 6; i++)
		for (int j = i + 1; j < 7; j++)
			if (data[i] > data[j]) {
				int temp = data[j];
				data[j] = data[i];
				data[i] = temp;
			}
	for (int j = 0; j < 7; j++) {
		count = 1;
		if (data[j]<= 9) {
			for (int i = j + 1; i < 7; i++)
				if (data[i] == data[j] + 1) {
					count++;
					break;
				}
			for (int i = j + 1; i < 7; i++)
				if (data[i] == data[j] + 2) {
					count++;
					break;
				}
			for (int i = j + 1; i < 7; i++)
				if (data[i] == data[j] + 3) {
					count++;
					break;
				}
			for (int i = j + 1; i < 7; i++)
				if (data[i] == data[j] + 4) {
					count++;
					break;
				}
			if (count == 5) {
				cout << "YES";
				return 0;
			}
		}
	}
	if (count != 5) {
		cout << "NO";
	}
	return 0;
}