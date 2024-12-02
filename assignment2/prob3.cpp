#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;
const int MAX = 1000;
int main() {
	ifstream infile("input3.txt");

	string word;
	string line;
	string words[MAX];
	int counts[MAX] = { 0 };
	int count = 0;
	while (getline(infile, line)) {
		while (true) {
			int temp = line.find(" ");
			if (line[0]==' ') {
				line.erase(0, 1);
				continue;
			}
			word = line.substr(0, temp);
			line = line.erase(0, temp + 1);

			for (int i = 0; i < word.length(); i++)
				word[i] = tolower(word[i]);
			bool found = false;
			if (temp == -1) {
				for (int i = 0; i < line.length(); i++)
					line[i] = tolower(line[i]);
				bool found = false;
				for (int i = 0; i < count; i++)
					if (words[i] == line) {
						counts[i] = counts[i] + 1;
						found = true;
						break;
					}
				if (!found) {
					words[count] = line;
					counts[count] = 1;
				}
				break;

			}
			for (int i = 0; i < count; i++)
				if (words[i] == word) {
					counts[i] = counts[i] + 1;
					found = true;
					break;
				}
			if (!found) {
				words[count] = word;
				counts[count] = counts[count] + 1;
				count++;
			}

		}
	}
	infile.close();
	for (int i = 0; i < count; i++)
		for (int j = 0; j <= count; j++) {
			if (counts[j] < counts[i]) {
				int temp = counts[j];
				counts[j] = counts[i];
				counts[i] = temp;
				string temp1 = words[j];
				words[j] = words[i];
				words[i] = temp1;
			}
			if (counts[j] == counts[i])
				if (words[j].compare(words[i]) == 1) {
					int temp = counts[j];
					counts[j] = counts[i];
					counts[i] = temp;
					string temp1 = words[j];
					words[j] = words[i];
					words[i] = temp1;
				}
		}
	for (int i = 0; i < count; i++)
		cout << words[i] << ":" << counts[i] << endl;
	return 0;
}