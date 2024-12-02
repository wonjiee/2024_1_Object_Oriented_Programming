#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	int number;
	vector<int>numbers;
	for (int i = 0; i < n; i++)   { //n개의 정수 크기순으로 저장
		cin >> number;
		if (i == 0) {
			numbers.push_back(number);
			continue;
		}
		auto it = numbers.begin();
		int count = 0;
		for (int j = 0; j < numbers.size(); j++) {
			if (number == numbers.at(j))
				count++;
		}
		if (count != 0) {
			continue;
		}
		while (it != numbers.end() && number > *it)
				it++;
		numbers.insert(it, number);
		
	}
	cout << numbers.size() << ": ";
	for (auto c : numbers)
		cout << c << " ";
	return 0;
}