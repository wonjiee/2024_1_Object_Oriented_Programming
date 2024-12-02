#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	srand((unsigned int)time(NULL));
	int N;
	cin >> N;
	if (N % 2 == 0) {
		cout << "홀수 N을 입력해주세요.";
		return 0;
	}
	int data_puppy_x[10000];
	int data_puppy_y[10000];
	int data_x[10000];
	int data_y[10000];
	data_puppy_x[0] = (N-1) / 2.0;
	data_puppy_y[0] = (N-1) / 2.0;
	data_x[0] = (N -1)/ 2.0;
	data_y[0] = (N -1)/ 2.0;
	int count1, count2, count3, count4; /*동 서 남 북 순서대로 1 2 3 4 부여.*/
	int clear = 0;
	int xp = 1, yp = 1;
	for (int k = 0; k < 10000; k++) {
		int data_puppy_x[10000] = { (N - 1) / 2.0, };
		int data_puppy_y[10000] = { (N - 1) / 2.0, };
		int data_x[10000] = { (N - 1) / 2.0, };
		int data_y[10000] = { (N - 1) / 2.0, };
	
		count1 = 0, count2 = 0, count3 = 0, count4 = 0;
		xp = 1, yp = 1;
		for (int i = 0; i >= 0; i++) {
			count1 = 0, count2 = 0, count3 = 0, count4 = 0;
			for (int j = 0; j < xp; j++)
				if (data_puppy_y[i] == data_y[j]) {
					if (data_puppy_x[i] + 1 == data_x[j]) {
						count1++;
						break;
					}
				}
			for (int j = 0; j < xp; j++)
				if (data_puppy_y[i] == data_y[j]) {
					if (data_puppy_x[i] - 1 == data_x[j]) {
						count2++;
						break;
					}
				}
			for (int j = 0; j < yp; j++)
				if (data_puppy_x[i] == data_x[j]) {
					if (data_puppy_y[i] - 1 == data_y[j]) {
						count3++;
						break;
					}
				}
			for (int j = 0; j < yp; j++)
				if (data_puppy_x[i] == data_x[j]) {
					if (data_puppy_y[i] + 1 == data_y[j]) {
						count4++;
						break;
					}
				}
			
	
			/*경우의 수가 0일때*/
			if (count1 != 0 && count2 != 0 && count3 != 0 && count4 != 0)
				break;
			/*경우의 수가 1일때*/
			if (count1 == 0 && count2 != 0 && count3 != 0 && count4 != 0) {
				data_puppy_x[i + 1] = data_puppy_x[i] + 1;
				data_x[i + 1] = data_puppy_x[i] + 1;
				data_puppy_y[i + 1] = data_puppy_y[i];
				data_y[i + 1] = data_puppy_y[i];
				xp++;
				yp++;
				if (data_puppy_x[i + 1] >= N) {
					clear++;
					break;
				}
			}

			if (count1 != 0 && count2 == 0 && count3 != 0 && count4 != 0) {
				data_puppy_x[i + 1] = data_puppy_x[i] - 1;
				data_x[i + 1] = data_puppy_x[i] - 1;
				data_puppy_y[i + 1] = data_puppy_y[i];
				data_y[i + 1] = data_puppy_y[i];
				xp++;
				yp++;
				if (data_puppy_x[i + 1] <= 0) {
					clear++;
					break;
				}
			}

			if (count1 != 0 && count2 != 0 && count3 == 0 && count4 != 0) {
				data_puppy_x[i + 1] = data_puppy_x[i];
				data_x[i + 1] = data_puppy_x[i];
				data_puppy_y[i + 1] = data_puppy_y[i] - 1;
				data_y[i + 1] = data_puppy_y[i] - 1;
				xp++;
				yp++;
				if (data_puppy_y[i + 1] <= 0 ){
					clear++;
					break;
				}
			}
			if (count1 != 0 && count2 != 0 && count3 != 0 && count4 == 0) {
				data_puppy_x[i + 1] = data_puppy_x[i];
				data_x[i + 1] = data_puppy_x[i];
				data_puppy_y[i + 1] = data_puppy_y[i] + 1;
				data_y[i + 1] = data_puppy_y[i] + 1;
				xp++;
				yp++;
				if (data_puppy_y[i + 1] >= N) {
					clear++;
					break;
				}
			}
			/*경우의 수가 2일때*/
			if (count1 == 0 && count2 == 0 && count3 != 0 && count4 != 0) {
				int random_value = rand() % 2 + 1;
				if (random_value == 1) {
					data_puppy_x[i + 1] = data_puppy_x[i] + 1;
					data_x[i + 1] = data_puppy_x[i] + 1;
					data_puppy_y[i + 1] = data_puppy_y[i];
					data_y[i + 1] = data_puppy_y[i];
					xp++;
					yp++;
					if (data_puppy_x[i + 1] >= N) {
						clear++;
						break;
					}
				}
				if (random_value == 2) {
					data_puppy_x[i + 1] = data_puppy_x[i] - 1;
					data_x[i + 1] = data_puppy_x[i] - 1;
					data_puppy_y[i + 1] = data_puppy_y[i];
					data_y[i + 1] = data_puppy_y[i];
					xp++;
					yp++;
					if (data_puppy_x[i + 1] <= 0 ){
						clear++;
						break;
					}
				}
			}

			if (count1 == 0 && count2 != 0 && count3 == 0 && count4 != 0) {
				int random_value = rand() % 2 + 1;
				if (random_value == 1) {
					data_puppy_x[i + 1] = data_puppy_x[i] + 1;
					data_x[i + 1] = data_puppy_x[i] + 1;
					data_puppy_y[i + 1] = data_puppy_y[i];
					data_y[i + 1] = data_puppy_y[i];
					xp++;
					yp++;
					if (data_puppy_x[i + 1] >= N) {
						clear++;
						break;
					}
				}
				if (random_value == 2) {
					data_puppy_x[i + 1] = data_puppy_x[i];
					data_x[i + 1] = data_puppy_x[i];
					data_puppy_y[i + 1] = data_puppy_y[i] - 1;
					data_y[i + 1] = data_puppy_y[i] - 1;
					xp++;
					yp++;
					if (data_puppy_y[i + 1] <= 0) {
						clear++;
						break;
					}
				}
			}

			if (count1 == 0 && count2 != 0 && count3 != 0 && count4 == 0) {
				int random_value = rand() % 2 + 1;
				if (random_value == 1) {
					data_puppy_x[i + 1] = data_puppy_x[i] + 1;
					data_x[i + 1] = data_puppy_x[i] + 1;
					data_puppy_y[i + 1] = data_puppy_y[i];
					data_y[i + 1] = data_puppy_y[i];
					xp++;
					yp++;
					if (data_puppy_x[i + 1] >= N) {
						clear++;
						break;
					}
				}
				if (random_value == 2) {
					data_puppy_x[i + 1] = data_puppy_x[i];
					data_x[i + 1] = data_puppy_x[i];
					data_puppy_y[i + 1] = data_puppy_y[i] + 1;
					data_y[i + 1] = data_puppy_y[i] + 1;
					xp++;
					yp++;
					if (data_puppy_y[i + 1] >= N) {
						clear++;
						break;
					}
				}
			}

			if (count1 != 0 && count2 == 0 && count3 == 0 && count4 != 0) {
				int random_value = rand() % 2 + 1;
				if (random_value == 1) {
					data_puppy_x[i + 1] = data_puppy_x[i] - 1;
					data_x[i + 1] = data_puppy_x[i] - 1;
					data_puppy_y[i + 1] = data_puppy_y[i];
					data_y[i + 1] = data_puppy_y[i];
					xp++;
					yp++;
					if (data_puppy_x[i + 1] <= 0) {
						clear++;
						break;
					}
				}
				if (random_value == 2) {
					data_puppy_x[i + 1] = data_puppy_x[i];
					data_x[i + 1] = data_puppy_x[i];
					data_puppy_y[i + 1] = data_puppy_y[i] - 1;
					data_y[i + 1] = data_puppy_y[i] - 1;
					xp++;
					yp++;
					if (data_puppy_y[i + 1] <= 0) {
						clear++;
						break;
					}
				}
			}

			if (count1 != 0 && count2 == 0 && count3 != 0 && count4 == 0) {
				int random_value = rand() % 2 + 1;
				if (random_value == 1) {
					data_puppy_x[i + 1] = data_puppy_x[i] - 1;
					data_x[i + 1] = data_puppy_x[i] - 1;
					data_puppy_y[i + 1] = data_puppy_y[i];
					data_y[i + 1] = data_puppy_y[i];
					xp++;
					yp++;
					if (data_puppy_x[i + 1] <= 0) {
						clear++;
						break;
					}
				}
				if (random_value == 2) {
					data_puppy_x[i + 1] = data_puppy_x[i];
					data_x[i + 1] = data_puppy_x[i];
					data_puppy_y[i + 1] = data_puppy_y[i] + 1;
					data_y[i + 1] = data_puppy_y[i] + 1;
					xp++;
					yp++;
					if (data_puppy_y[i + 1] >= N) {
						clear++;
						break;
					}
				}
			}

			if (count1 != 0 && count2 != 0 && count3 == 0 && count4 == 0) {
				int random_value = rand() % 2 + 1;
				if (random_value == 1) {
					data_puppy_x[i + 1] = data_puppy_x[i];
					data_x[i + 1] = data_puppy_x[i];
					data_puppy_y[i + 1] = data_puppy_y[i] - 1;
					data_y[i + 1] = data_puppy_y[i] - 1;
					xp++;
					yp++;
					if (data_puppy_y[i + 1] <= 0) {
						clear++;
						break;
					}
				}
				if (random_value == 2) {
					data_puppy_x[i + 1] = data_puppy_x[i];
					data_x[i + 1] = data_puppy_x[i];
					data_puppy_y[i + 1] = data_puppy_y[i] + 1;
					data_y[i + 1] = data_puppy_y[i] + 1;
					xp++;
					yp++;
					if (data_puppy_y[i + 1] >= N) {
						clear++;
						break;
					}
				}
			}
			/*경우의 수가 3일때*/
			if (count1 == 0 && count2 == 0 && count3 == 0 && count4 != 0) {
				int random_value = rand() % 3 + 1;
				if (random_value == 1) {
					data_puppy_x[i + 1] = data_puppy_x[i] + 1;
					data_x[i + 1] = data_puppy_x[i] + 1;
					data_puppy_y[i + 1] = data_puppy_y[i];
					data_y[i + 1] = data_puppy_y[i];
					xp++;
					yp++;
					if (data_puppy_x[i + 1] >= N) {
						clear++;
						break;
					}
				}
				if (random_value == 2) {
					data_puppy_x[i + 1] = data_puppy_x[i] - 1;
					data_x[i + 1] = data_puppy_x[i] - 1;
					data_puppy_y[i + 1] = data_puppy_y[i];
					data_y[i + 1] = data_puppy_y[i];
					xp++;
					yp++;
					if (data_puppy_x[i + 1] <= 0) {
						clear++;
						break;
					}
				}
				if (random_value == 3) {
					data_puppy_x[i + 1] = data_puppy_x[i];
					data_x[i + 1] = data_puppy_x[i];
					data_puppy_y[i + 1] = data_puppy_y[i] - 1;
					data_y[i + 1] = data_puppy_y[i] - 1;
					xp++;
					yp++;
					if (data_puppy_y[i + 1] <= 0) {
						clear++;
						break;
					}
				}
			}
			if (count1 == 0 && count2 == 0 && count3 != 0 && count4 == 0) {
				int random_value = rand() % 3 + 1;
				if (random_value == 1) {
					data_puppy_x[i + 1] = data_puppy_x[i] + 1;
					data_x[i + 1] = data_puppy_x[i] + 1;
					data_puppy_y[i + 1] = data_puppy_y[i];
					data_y[i + 1] = data_puppy_y[i];
					xp++;
					yp++;
					if (data_puppy_x[i + 1] >= N) {
						clear++;
						break;
					}
				}
				if (random_value == 2) {
					data_puppy_x[i + 1] = data_puppy_x[i] - 1;
					data_x[i + 1] = data_puppy_x[i] - 1;
					data_puppy_y[i + 1] = data_puppy_y[i];
					data_y[i + 1] = data_puppy_y[i];
					xp++;
					yp++;
					if (data_puppy_x[i + 1] <= 0) {
						clear++;
						break;
					}
				}
				if (random_value == 3) {
					data_puppy_x[i + 1] = data_puppy_x[i];
					data_x[i + 1] = data_puppy_x[i];
					data_puppy_y[i + 1] = data_puppy_y[i] + 1;
					data_y[i + 1] = data_puppy_y[i] + 1;
					xp++;
					yp++;
					if (data_puppy_y[i + 1] >= N) {
						clear++;
						break;
					}
				}
			}
			if (count1 == 0 && count2 != 0 && count3 == 0 && count4 == 0) {
				int random_value = rand() % 3 + 1;
				if (random_value == 1) {
					data_puppy_x[i + 1] = data_puppy_x[i] + 1;
					data_x[i + 1] = data_puppy_x[i] + 1;
					data_puppy_y[i + 1] = data_puppy_y[i];
					data_y[i + 1] = data_puppy_y[i];
					xp++;
					yp++;
					if (data_puppy_x[i + 1] >= N) {
						clear++;
						break;
					}
				}
				if (random_value == 2) {
					data_puppy_x[i + 1] = data_puppy_x[i];
					data_x[i + 1] = data_puppy_x[i];
					data_puppy_y[i + 1] = data_puppy_y[i] - 1;
					data_y[i + 1] = data_puppy_y[i] - 1;
					xp++;
					yp++;
					if (data_puppy_y[i + 1] <= 0) {
						clear++;
						break;
					}
				}
				if (random_value == 3) {
					data_puppy_x[i + 1] = data_puppy_x[i];
					data_x[i + 1] = data_puppy_x[i];
					data_puppy_y[i + 1] = data_puppy_y[i] + 1;
					data_y[i + 1] = data_puppy_y[i] + 1;
					xp++;
					yp++;
					if (data_puppy_y[i + 1] >= N) {
						clear++;
						break;
					}
				}
			}
			if (count1 != 0 && count2 == 0 && count3 == 0 && count4 == 0) {
				int random_value = rand() % 3 + 1;
				if (random_value == 1) {
					data_puppy_x[i + 1] = data_puppy_x[i] - 1;
					data_x[i + 1] = data_puppy_x[i] - 1;
					data_puppy_y[i + 1] = data_puppy_y[i];
					data_y[i + 1] = data_puppy_y[i];
					xp++;
					yp++;
					if (data_puppy_x[i + 1] <= 0) {
						clear++;
						break;
					}
				}
				if (random_value == 2) {
					data_puppy_x[i + 1] = data_puppy_x[i];
					data_x[i + 1] = data_puppy_x[i];
					data_puppy_y[i + 1] = data_puppy_y[i] - 1;
					data_y[i + 1] = data_puppy_y[i] - 1;
					xp++;
					yp++;
					if (data_puppy_y[i + 1] <= 0) {
						clear++;
						break;
					}
				}
				if (random_value == 3) {
					data_puppy_x[i + 1] = data_puppy_x[i];
					data_x[i + 1] = data_puppy_x[i];
					data_puppy_y[i + 1] = data_puppy_y[i] + 1;
					data_y[i + 1] = data_puppy_y[i] + 1;
					xp++;
					yp++;
					if (data_puppy_y[i + 1] >= N) {
						clear++;
						break;
					}
				}
			}
			/*경우의 수가 4일때*/
			if (count1 == 0 && count2 == 0 && count3 == 0 && count4 == 0) {
				int random_value = rand() % 4 + 1;
				if (random_value == 1) {
					data_puppy_x[i + 1] = data_puppy_x[i] + 1;
					data_x[i + 1] = data_puppy_x[i] + 1;
					data_puppy_y[i + 1] = data_puppy_y[i];
					data_y[i + 1] = data_puppy_y[i];
					xp++;
					yp++;
					if (data_puppy_x[i + 1] >= N) {
						clear++;
						break;
					}
				}
				if (random_value == 2) {
					data_puppy_x[i + 1] = data_puppy_x[i] - 1;
					data_x[i + 1] = data_puppy_x[i] - 1;
					data_puppy_y[i + 1] = data_puppy_y[i];
					data_y[i + 1] = data_puppy_y[i];
					xp++;
					yp++;
					if (data_puppy_x[i + 1] <= 0) {
						clear++;
						break;
					}
				}
				if (random_value == 3) {
					data_puppy_x[i + 1] = data_puppy_x[i];
					data_x[i + 1] = data_puppy_x[i];
					data_puppy_y[i + 1] = data_puppy_y[i] - 1;
					data_y[i + 1] = data_puppy_y[i] - 1;
					xp++;
					yp++;
					if (data_puppy_y[i + 1] <= 0) {
						clear++;
						break;
					}
				}
				if (random_value == 4) {
					data_puppy_x[i + 1] = data_puppy_x[i];
					data_x[i + 1] = data_puppy_x[i];
					data_puppy_y[i + 1] = data_puppy_y[i] + 1;
					data_y[i + 1] = data_puppy_y[i] + 1;
					xp++;
					yp++;
					if (data_puppy_y[i + 1] >= N) {
						clear++;
						break;
					}
				}
			}
		}
	}
	cout << clear / 10000.0;
	return 0;
}
