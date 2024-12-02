#include <iostream>
#include <vector>

using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int>data(2*N);
	for (int i = 0; i < 2*N; i++)
		cin >> data[i];
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			if (data[2*i] > data[2*j]) {
				int temp = data[2*j];
				int temp1 = data[2 * j + 1];
				data[2*j] = data[2*i];
				data[2 * j + 1] = data[2 * i + 1];
				data[2*i] = temp;
				data[2 * i + 1] = temp1;
			}
	for (int i = 0; i < N-1; i++)
		for (int j = i + 1; j < N-1-i; j++)
			if (data[2*i]==data[2*j])
				if (data[2 * i + 1] > data[2 * j + 1]) {
					int temp = data[2 * j + 1];
					data[2 * j + 1] = data[2 * i + 1];
					data[2 * i + 1] = temp;
				}
	cout << endl;
	for (int i = 0; i < N; i++)
		cout << data[2*i] << " " << data[2*i + 1] << endl;
	return 0;
 }