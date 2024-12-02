#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int value = 0;
	while (n > 0) {
		value = n % 10;
		cout << value;
		n = n / 10;
		if (n == 0)
			break;
	}
	return 0;
}