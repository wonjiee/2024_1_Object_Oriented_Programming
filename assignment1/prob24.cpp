#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	int number = 0;
	vector<int>data(n);
	int n_1 = n;
	for (int i = 0; i < n; i++)
		cin >> data[i];
	for (int i = 0; i < n - 1; i++) {
		int number = 0;
		for (int j = 1; j < n - i; j++) {
			if (data[j] > data[number]) {
				number = j;
			}
		}
		int temp = data[n - i - 1];
		data[n - i - 1] = data[number];
		data[number] = temp;

	}
	for (int k = 0; k < n; k++)
		cout << data[k] << " ";
	return 0;
}
