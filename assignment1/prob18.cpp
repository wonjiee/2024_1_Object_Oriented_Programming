#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int count = 0;
	int count0 = 0;
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	int count4 = 0;
	int count5 = 0;
	int count6 = 0;
	int count7 = 0;
	int count8 = 0;
	int count9 = 0;
	int value1 = 0;
	int data[1000];
	while (1) {
		data[count] = N % 10;
		N = N / 10;
		count++;
		if (N < 10) {
			data[count] = N;
			count++;
			break;
		}
	}
	for (int i = 0; i < count; i++) {
		if (data[i] == 0)
			count0++;
		if (data[i] == 1)
			count1++;
		if (data[i] == 2)
			count2++;
		if (data[i] == 3)
			count3++;
		if (data[i] == 4)
			count4++;
		if (data[i] == 5)
			count5++;
		if (data[i] == 6)
			count6++;
		if (data[i] == 7)
			count7++;
		if (data[i] == 8)
			count8++;
		if (data[i] == 9)
			count9++;
	}
	cout << count0 << count1 << count2 << count3 << count4 << count5 << count6 << count7 << count8 << count9 << endl;
	return 0;

			
		
		
		
}