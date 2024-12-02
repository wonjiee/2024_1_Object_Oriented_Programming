#include <iostream>

using namespace std;

int main() {
	int min=0, max=0;
	int value;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> value;
		if (max == 0 || value >= max) {
			max = value;
		}
		if (min == 0 || value <= min) {
			min = value;
		}
		cout << max << "와 " << min << "의 차는 " << max - min << endl;
	}
	return 0;
}