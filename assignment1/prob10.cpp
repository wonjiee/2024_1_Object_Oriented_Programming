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

	cout << "10진수 : " << N << endl;

	/* 여기에서 N보다 작거나 같으면서 가장 큰 2의 거듭제곱수 v를 구한다. */
	cout << "2진수 : ";
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

		/* N ≥ v이면 N = N-v가되고 */
		/* 1을 출력한다. 그렇지 않으면 */
		/* 0을 출력한다. 두 경우 모두 */
		/* v는 1/2한다. */
	}
	return 0;
}