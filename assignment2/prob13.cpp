#include <iostream>
#include <string>
#include <vector>
using namespace std;

int user_compare(string a, string b) {
	if (a.length() == b.length()) {
		if (a > b)
			return 0;
		else
			return 1;
	}
	if (a.length() > b.length()) {
		return 2;
	}
	if (a.length() < b.length()) {
		return 3;
	}
}

int main() {
	int n;
	cin >> n;
	string word;
	vector<string>words;
	for (int i = 0; i < n; i++) {
		cin >> word;
		words.push_back(word);
	}
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			int temp = user_compare(words.at(i), words.at(j));
			string temp1 = words.at(j);
			if (temp == 0)
				if (words.at(i) > words.at(j)) {
					words.at(j) = words.at(i);
					words.at(i) = temp1;
				}
			if (temp == 2) {
				words.at(j) = words.at(i);
				words.at(i) = temp1;
			}
		}
	for (auto a : words)
		cout << a << endl;
	return 0;
}




	