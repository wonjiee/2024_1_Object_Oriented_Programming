#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> data(n);
	for (int i = 0; i < n; i++)
		cin >> data[i];
	int min = -1;


	for (int i = 0; i < n; i++) {
		if (data[i] >= 0) {
			if (min == -1 || data[i] < min)
				min = data[i];
		}
	}
	if (min == -1)
		cout << -1;
	else cout << min;
	return 0;
}