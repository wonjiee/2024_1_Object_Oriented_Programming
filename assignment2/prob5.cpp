#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;
const int MAX = 1000;

int main() {
	ifstream infile("sample_lines.txt");
	string word;
	string line;
	string lines[MAX];
	int counts[MAX];
	int count = 0, count1 = 0;
	while (getline(infile, line)) {
		if (line == "")
			continue;
		while (true) {
			int gap = line.find(" ");
			if (gap==0) {
				line.erase(gap,1);
				continue;
			}
			int temp = line.find("  ");
			if (temp == -1)
				break;
			else line.erase(temp, 1);
		}
		lines[count] = line;
		while (true) {
			int temp = line.find(" ");
			if (temp != -1) {
				line.erase(0, temp + 1);
				count1++;
			}
			if (temp == -1) {
				count1++;
				break;
			}
		}
		counts[count] = count1;
		count++;
		count1 = 0;
	}
	for (int i = 0; i < count; i++)
		for (int j = i+1; j < count; j++)
			if (counts[i] < counts[j]) {
				int temp = counts[j];
				counts[j] = counts[i];
				counts[i] = temp;
				string temp1 = lines[j];
				lines[j] = lines[i];
				lines[i] = temp1;
			}
	infile.close();
	for (int i = 0; i < count; i++)
		cout << lines[i] << ":" << counts[i] << endl;
	return 0;
}