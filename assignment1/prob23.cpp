#include <iostream>
using namespace std;

int main() {
	int data[100];
	int count = 1;
	int count1 = 0;
	int count2 = 0;
	int value;
	int value1 = 0;
	cin >> data[0];
	cout << data[0] << endl;
	while (1) {
		count1 = 0;
		count2 = 0;
		cin >> value;
		if (value == -1)
			break;
		for (int i = 0; i < count; i++)
			if (count >= 2 && value == data[i]) {
				cout << "duplicate" << endl;
				count2 = 1;
				break;
			}
		if (count2 == 1)
			continue;
		for (int j = 0; j < count; j++) {
			if (value != data[j])
				count1++;
		}
		if (count1 == count)
			data[count] = value;
		count++;
		for (int k = 0; k < count-1; k++)
			for (int k_1 = k+1; k_1 < count; k_1++)
				if (data[k] > data[k_1]) {
					value1 = data[k];
					data[k] = data[k_1];
					data[k_1] = value1;
				
				}
		for (int q = 0; q < count; q++)
			cout << data[q] << " ";
		cout << endl;
	}
	return 0;
}

				

			

		



