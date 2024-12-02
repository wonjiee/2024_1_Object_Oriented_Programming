#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;
vector<string>words;
int main() {
	string word;
	ifstream infile("harry.txt");
	while (infile >> word) {
		if (words.size() == 0) {
			words.push_back(word);
			continue;
		}
		auto it = words.begin();
		bool duplication = false;
		while (it != words.end() && word >= *it) {
			if (word == *it) {
				duplication = true;
				break;
			}
			else it++;
		}
		if (duplication) {
			continue;
		}
		if (it == words.end())
			words.push_back(word);
		else words.insert(it, word);
	}

	string pre;
	cin >> pre;
	int count = 0;
	for (int i = 0; i < words.size(); i++) {
		int temp = words.at(i).find(pre);
		if (temp == 0) {
			cout << words.at(i) << endl;
			count++;
		}
	}
	cout << count << endl;
	return 0;


}