#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>data(N);
	vector<int>data_1(N);
	for (int i = 0; i < N; i++)
		cin >> data[i];
	for (int i_1 = 0; i_1 < N ;i_1++)
		data_1[i_1] = data[i_1];

	int k;
	cin >> k;
	
	for (int j = 0; j < N; j++) {
		if (j < N - k)
			data[j + k] = data_1[j];
		if (j >= (N - k))
			data[j - (N - k)] = data_1[j];
	}
	for (int a = 0; a < N; a++)
		cout << data[a];
	return 0;



}