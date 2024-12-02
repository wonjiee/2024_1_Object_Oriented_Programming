#include <iostream>

using namespace std;

int main() {
	int data[10000];
	int count = 0;
	int count1 = 0;
	int i;
	int j;
	for (int i = 0; i >= 0; i++) {
		cin >> data[i];
		if (data[i] == -1)
			break;
		count++;
	}

	if (data[0] <= data[1])
			count1++;
	if (count > 2) {
		for (int j = 1; j <= count; j++) {
			if (data[j] <= data[j - 1] && data[j] <= data[j + 1])
				count1++;
			if (data[j] == -1)
				if (data[j - 1] <= data[j - 2]) {
					count1++;
					break;
				}
				else break;
		}
	}
	cout << count1;
	return 0;
}
