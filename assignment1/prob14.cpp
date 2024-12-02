#include <iostream>

using namespace std;
int main() {
	int data_1[100];
	int data_2[100];
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	int count4 = 0;
	int count5 = 0;
	for (int i = 2; i <= 98; i++) {
		count1 = 0;
		{
			for (int i_1 = 0; i_1 <= i-2; i_1++)
				if (i % (i_1+2) == 0)
				{
					data_1[count1] = i_1+2;
					count1++;
				}
			for (int j = i + 1; j <= 99; j++) {
				count2 = 0;
				for (int j_1 = 0; j_1 < count1; j_1++)
					if (j % data_1[j_1] == 0)
						count2++;
				if (count2 == 0) {
					count3 = 0;
					for (int j_2 = 0; j_2 <= j - 2; j_2++)
					{
						if (j % (j_2 + 2) == 0)
						{
							data_2[count3] = (j_2 + 2);
							count3++;
						}
					}
					for (int k = j + 1; k <= 100; k++) {
						for (int k_1 = 0; k_1 < count1; k_1++)
							if (k % data_1[k_1] == 0)
								count4++;
						for (int k_2 = 0; k_2 < count3; k_2++)
							if (k % data_2[k_2] == 0)
								count4++;
						if (count4 == 0)
						{
							count5++;
						}
						if (count4 > 0) {
							count4 = 0;
						}

					}
				}
			}
			
			
		}
	}
	cout << count5;
	return 0;
}





