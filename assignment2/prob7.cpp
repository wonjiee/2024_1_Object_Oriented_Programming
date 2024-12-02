#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main() {
	string word;
	vector<string>words;
	while (true) {
		cin >> word;
		int count = 0;
		if (word == "exit")
			break;
		for (int i = 0; i < words.size(); i++) {
			int temp = words[i].compare(word);
			if (temp == 0){
				count++;
				break;
			}
		}
		if (count==0)
			words.push_back(word);
		else {
			cout << "duplicate" << endl;
			continue;
		}
		for (int i = 0; i < words.size(); i++)
			for (int j = i + 1; j < words.size(); j++) {
				string temp1 = words[i];
				if (words[i].compare(words[j]) == 1) {
					words[i] = words[j];
					words[j] = temp1;
				}
			}
		for (int i = 0; i < words.size(); i++)
			cout << words[i] << " ";
		cout << endl;
	}
	return 0;
}


					

