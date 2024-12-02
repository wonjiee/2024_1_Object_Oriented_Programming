#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	int value;
	vector<int>data(N);
	int count = 0;
	cin >> data[count];
	for (int i = 1; i < N; i++) {
		cin >> value;
		if (value >= data[count]) {
			count++;
			data[count] = value;
			
		}
	}
	cout << N << ": ";
	for (int k = 0; k <= count; k++)
		cout << data[k] << " ";
	return 0;
		

}
