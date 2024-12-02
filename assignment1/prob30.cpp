#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	int value = 0;
	int value1;
	int value2;
	int value3;
	int value4;
	vector<int>data(2 * N);
	int data_1[4];
	for (int i = 0; i < 2 * N; i++)
		cin >> data[i];
	for (int i = 0; i <= N - 2; i++) {
		for (int j = i+1; j <= N - 1; j++) {
			if (data[2 * j] >= data[2 * i] && data[2 * j] <= data[2 * i + 1] && data[2 * j + 1] >= data[2 * i + 1]) {
				value1 = data[2 * i + 1] - data[2 * j];
				if (value1 >= value) {
					value = value1;
					data_1[0] = data[2 * i];
					data_1[1] = data[2 * i + 1];
					data_1[2] = data[2 * j];
					data_1[3] = data[2 * j + 1];
				}
			}
			if (data[2 * j] <= data[2 * i] && data[2 * j + 1] >= data[2 * i] && data[2 * i+1] >= data[2 * j + 1]) {
				value2 = data[2 * j + 1] - data[2 * i];
				if (value2 >= value) {
					value = value2;
					data_1[0] = data[2 * i];
					data_1[1] = data[2 * i + 1];
					data_1[2] = data[2 * j];
					data_1[3] = data[2 * j + 1];
				}
			}
			if (data[2 * i] <= data[2 * j] && data[2 * j + 1] <= data[2 * i + 1]) {
				value3 = data[2 * j + 1] - data[2 * j];
				if (value3 >= value) {
					value = value3;
					data_1[0] = data[2 * i];
					data_1[1] = data[2 * i + 1];
					data_1[2] = data[2 * j];
					data_1[3] = data[2 * j + 1];
				}
			}
			if (data[2 * j] <= data[2 * i] && data[2 * j + 1] >= data[2 * i + 1]) {
				value4 = data[2 * i + 1] - data[2 * i];
				if (value4 >= value) {
					value=value4;
					data_1[0] = data[2 * i];
					data_1[1] = data[2 * i + 1];
					data_1[2] = data[2 * j];
					data_1[3] = data[2 * j + 1];
				}
			}
		}
	}
	cout << "[" << data_1[0] << ", " << data_1[1] << "]" << endl << "[" << data_1[2] << ", " << data_1[3] << "]";
	return 0;
}