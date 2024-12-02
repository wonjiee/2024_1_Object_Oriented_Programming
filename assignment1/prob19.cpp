#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;


int main() {
	int N;
	cin >> N;
	vector<int>data(N);
	for (int i = 0; i < N; i++)
		cin >> data[i];

	int k;
	cin >> k;
	int value;
	int value1;
	value1 = abs(k - data[0]);
	for (int j = 0; j < N; j++) {
		if (abs(k - data[j]) <= value1) {
			value1 = abs(k - data[j]);
			value = data[j];
		}
	}
	cout << value;

	return 0;



}
