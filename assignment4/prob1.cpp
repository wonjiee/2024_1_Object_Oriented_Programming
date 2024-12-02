#include<iostream>
#include<vector>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	vector<vector<int>>data(a, vector<int>(b, 0));
	int n;
	for(int i=0;i<a;i++)
		for (int j = 0; j < b; j++) {
			cin >> n;
			data[i][j] = n;
		}
	for (int i = 0; i < a; i++)
		for (int j = 0; j < b; j++) {
			cin >> n;
			data[i][j] += n;
		}
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cout << data[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}