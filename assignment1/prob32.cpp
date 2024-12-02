#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	int count0 = 0;
	int count1 = 0;
	int value = 0;
	cin >> N;
	vector<int>data(N);
	for (int i=0 ; i < N; i++) {
		cin >> data[i];
		if (data[i] != 0 && data[i] !=1) {
			cout << "잘못된 값.";
			return 0;
		}
	}
	for (int i = 0; i < N; i++) {
		count0 = 0;
		count1 = 0;
		if (data[i] == 1) {
			count1 = 1;
			for (int j = i + 1; j < N; j++) {
				if (data[j] == 1) {
					count1++;
					if (count0 == 1) {
						if (count1 + 1 >= value)
							value = count1 + 1;
					}
					else if (count1 >= value)
						value = count1;
				}
				if (data[j] == 0) {
					count0++;
					if (count0 == 1)
						if (count1 + 1 >= value)
							value = count1 + 1;
					if (count0 == 2)
						continue;
				}
			}
		}
		if (data[i] == 0) {
			count0 = 1;
			for (int j = i + 1; j < N; j++) {
				if (data[j] == 1) {
					count1++;
					if (count1 + 1 >= value)
						value = count1 + 1;
				}
				if (data[j] == 0) {
					value = count1 + 1;
					break;
				}
			}
		}
	}
	cout << value;
	return 0;
}