#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	int count = 1;
	int count1 = 1;
	int value;
	cin >> N;
	vector<int>data(N);
	for (int i = 0; i < N; i++)
		cin >> data[i];
	for (int i = 0; i < N-1; i++) {
		count = 1;
		value = data[i];
		for (int j = i + 1; j < N;) {
			if (value <= data[j]) {
				value = data[j];
				count++;
				j++;
			}
			else break;
		}
		if (count >= count1)
			count1 = count;
	}
	cout << count1;
	return 0;

}
