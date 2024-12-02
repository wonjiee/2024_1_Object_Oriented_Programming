#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>data(n);
	cin >> data[0];
	int count = 1;
	int value;
	int max;
	int duplicate = 0;
	for (int i = 1; i < n; i++) {
		duplicate = 0;
		cin >> value;
		for (int j = 0; j < count; j++)
			if (value == data[j])
				duplicate++;
		if (duplicate == 0) {
			data[count] = value;
			count++;
		}
	}
	for (int i = 0; i < count ; i++) {
		max = 0;
		for (int j = 1; j < count - i; j++)
			if (data[max] < data[j])
				max = j;
		int temp = data[count-1 - i];
		data[count-1 - i] = data[max];
		data[max] = temp;
	}
	cout << count << ": ";
	for (int i = 0; i < count; i++)
		cout << data[i] << " ";
	return 0;
}