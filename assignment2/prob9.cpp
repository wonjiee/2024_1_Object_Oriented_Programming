#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
int main() {

	ifstream infile("shuffled_dict.txt");
	string line, word, explanation;
	vector<string>words;
	vector<string>explanations;
	while (getline(infile, line)) {
		int temp = line.find("\t");
		word = line.substr(0, temp);
		explanation = line.substr(temp + 1);
		while (true) {
			int temp = explanation.find("  ");
			if (temp != -1)
				explanation.erase(temp, 1);
			else break;
		}
		if (words.size() == 0) {
			words.push_back(word);
			explanations.push_back(explanation);
			continue;
		}
		auto it = words.begin();
		auto it2 = explanations.begin();
		while (it != words.end() && *it < word)
			it++, it2++;
		if (it == words.end()) {
			words.push_back(word);
			explanations.push_back(explanation);
		}
		else {
			words.insert(it, word);
			explanations.insert(it2, explanation);
		}
	}
	infile.close();
	cin >> word;
	bool found =false;
	for (int i = 0; i < words.size(); i++) {
		if (words[i] == word) {
			cout << "Found" << endl << words[i] << ": " << explanations[i] << endl<< endl;
			found = true;
			break;
		}
	}
	if (!found) {
		for (int i = 0; i < words.size(); i++) {
			if (i == 0 && word < words[i]) {
				cout << "Not found" << endl << "+ " << words[i] << ": " << explanations[i] << endl << endl;
				break;
			}
			if (i == words.size() - 1 && word > words[i]) {
				cout << "Not found" << endl<< "- " << words[i] << ": " << explanations[i] << endl << endl;
				break;
			}
			if (word>words[i] && word<words[i + 1]) {
				cout << "Not found" << endl;
				cout << "- " << words[i] << ": " << explanations[i] << endl;
				cout << "+ " << words[i + 1] << ": " << explanations[i + 1] << endl;
				cout << endl;
				break;
			}
		}
	}
	cout << "Results of prefix search : " << endl;
	for(int i=0;i<words.size();i++){
		if (words[i].find(word) == 0) {
			cout << words[i] << ": " << explanations[i] << endl;
		}
	}
	return 0;
}