#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

int main() {
	string line;
	int count = 0;
	ifstream infile("sample.txt");
	vector<string>words;
	while (getline(infile, line)) {
		for (int i = 0; i < line.length(); i++)
			line[i] = tolower(line[i]);
		while (true) {
			int gap = line.find(" ");
			if (gap == 0) {
				line.erase(gap, 1);
				continue;
			}
			else break;
		}
		while (true) {
			int gap2 = line.find("  ");
			if (gap2 != -1) {
				line.erase(gap2, 1);
				continue;
			}
			else break;
		}
		while (true) {
			count = 0;
			int temp = line.find(" ");
			if (temp != -1) {
				string temp2 = line.substr(0, temp);
				for (int i = 0; i < temp2.size(); i++) {
					if (isalpha(temp2[i]) || isdigit(temp2[i]))
						continue;
					else {
						temp2.erase(i, 1);
						i = 0;
					}
				}
				line.erase(0, temp + 1);
				for (int i = 0; i < words.size(); i++) {
					if (words[i] == temp2)
						count++;
				}
				if (count == 0) {
					words.push_back(temp2);
					continue;
				}
			}
			else {
				for (int i = 0; i < words.size(); i++) {
					if (words[i] == line)
						count++;
				}
				if (count == 0)
					words.push_back(line);
				else break;
			}
		}
	}
	infile.close();
	for (int i = 0; i < words.size(); i++)
		for (int j = i + 1; j < words.size(); j++) {
			string temp = words[i];
			int temp2 = words[i].compare(words[j]);
			if (temp2 == 1) {
				words[i] = words[j];
				words[j] = temp;
			}
		}
	for (int i = 0; i < words.size(); i++)
		cout << words[i] << endl;
	return 0;
}