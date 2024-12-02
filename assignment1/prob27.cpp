#include <iostream>
#include <vector>

using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int>data(N);
	int count = 0;
	for (int i = 0; i < N; i++)
		cin >> data[i];
	for (int i = 0; i < N - 1; i++)
		for (int j = i + 1; j < N  ; j++)
			if (data[i] > data[j])
				count++;
	cout << count;
	return 0;
}
