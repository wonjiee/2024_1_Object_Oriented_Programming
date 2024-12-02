#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main() {
	int N;
	cin >> N;
	string word, spell;
	vector<string>words;
	int count = 0;
	int n = 1;
	for (int i = 0; i < N; i++) {
		cin >> word;
		words.push_back(word);
	}
	while (true) {
		word = words[0];
		count = 0;
		spell = word.substr(0, n);
		for (int i = 1; i < N; i++) {
			int temp = words[i].find(spell);
			if (temp != 0) {
				count++;
				if (n == 1) {
					cout << "nothing" << endl;
					return 0;
				}
				spell = word.substr(0, n - 1);
				break;
			}
		}
		if (spell == words[0])
			break;
		if (count == 0)
			n++;
		if (count != 0)
			break;
	}
	cout << spell << endl;
	return 0;
}