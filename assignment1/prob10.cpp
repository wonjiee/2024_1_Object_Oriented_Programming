#include <iostream> 
using namespace std;
int main() {
	int N;
	cin >> N;
	double v = 1;
	while (N > v)
		if (v * 2 > N)
			break;
		else v = v * 2;

	cout << "10���� : " << N << endl;

	/* ���⿡�� N���� �۰ų� �����鼭 ���� ū 2�� �ŵ������� v�� ���Ѵ�. */
	cout << "2���� : ";
	while (v > 0) {
		if (v == 1) {
			if (N == 0) {
				cout << 0;
				break;
			}
			if (N == 1) {
				cout << 1;
				break;
			}
		}
		if (N >= v) {
			N = N - v;
			v = v / (double)2;
			cout << 1;
		}
		else {
			v = v / (double)2;
			cout << 0;
		}

		/* N �� v�̸� N = N-v���ǰ� */
		/* 1�� ����Ѵ�. �׷��� ������ */
		/* 0�� ����Ѵ�. �� ��� ��� */
		/* v�� 1/2�Ѵ�. */
	}
	return 0;
}