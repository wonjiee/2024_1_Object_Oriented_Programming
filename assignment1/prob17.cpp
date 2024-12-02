#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	double value1 = 0;
	double value2 = 0;
	double value3 = 0;
	double mean;
	vector<int> data(N);
	for (int i = 0; i < N; i++)
		cin >> data[i];
	for (int j = 0; j < N; j++)
		value1 += data[j];
	mean = value1 / N;
	cout << "평균 : " << mean << endl;
	for (int k = 0; k < N; k++)
		value2 += (data[k] - mean) * (data[k] - mean);
	value2 = value2 / N;
	value3 = sqrt(value2);
	cout << "표준편차 : " << value3 << endl;
	return 0;

}