#include <iostream>
#include <vector>
using namespace std;
int main() {
	int N;
	cin >> N;
	int K;
	int value;
	int count = 0;
	int count1 = 0;
	vector<int>data(N);
	for (int i = 0; i < N; i++)
		cin >> data[i];
	cin >> K;
	for (int i = 0; i < N - 1; i++) {
		count = 0;
		value = 0;
		if (data[i] <= K) {
			value = data[i];
			count++;
		}
		else continue;
		for (int j = i + 1; j < N;j++) {
			if (data[j] + value <= K) {
				value = value + data[j];
				count++;
			}
			else break;
		}
		if (count >= count1)
			count1 = count;

	}
	cout << count1;
	return 0;


}