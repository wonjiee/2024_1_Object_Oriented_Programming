#include <iostream>
#include <vector>
using namespace std;

void compute_set(vector<int>& A, vector<int>& B) {
	vector<int>A_1 = A;
	for (int i = 0; i < B.size(); i++) {
		auto it = A.begin();
		while (it != A.end() && *it < B[i])
			it++;
		if (it == A.end() || *it != B[i])
			A.insert(it, B[i]);
	}
	vector<int>C;
	for (int i = 0; i < A_1.size(); i++) {
		auto it = B.begin();
		while (it != B.end() && *it != A_1[i])
			it++;
		if (it != B.end())
			C.push_back(A_1[i]);
	}
	for (int i = 0; i < C.size(); i++) {
		auto it = A.begin();
		while (it != A.end() && *it != C[i])
			it++;
		if (it != A.end())
			it = A.erase(it);
	}

}

int main() {
	int m, n, k;
	vector<int>first, second;
	cin >> m;
	// m개의 정수가 오름차순으로 정렬되어 입력된다.c
	for (int i = 0; i < m; i++) {
		cin >> k;
		first.push_back(k);
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		second.push_back(k);
	}
	compute_set(first, second);
	for (auto item : first)
		cout << item << " ";
	cout << endl;
	return 0;
}