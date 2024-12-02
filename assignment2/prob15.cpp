#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip> // setw 함수 사용하기 위한 헤더 파일

using namespace std;

string user_erase(string a) { // 앞뒤 공백 제거
	while (true) {
		int temp = a.find(" ");
		if (temp == 0) {
			a.erase(temp, 1);
			continue;
		}
		if (temp != 0)
			break;
	}
	while (true) {
		int temp1 = a.find("  ");
		if (temp1 != -1) {
			a.erase(temp1, 1);
			continue;
		}
		if (temp1 == -1)
			break;
	}
	return a;
}


int main() {
	ifstream infile("table.txt");
	string line, line1;
	vector<string>lines;
	int Max_line = 0;
	int x = 0;
	int count = 0;
	int count1 = 0;
	while (getline(infile, line)) { // 첫 번째 라인에서 열의 수를 읽어옴
		if (count == 0) {
			line.erase(0, 2);
			x = stoi(line);
			count++;
			continue;
		}
		if (count != 0)
			while (true) {
				int temp = line.find("&"); // & 기준으로 분할
				if (temp != -1) {
					line1 = line.substr(0, temp);
					line = line.erase(0, temp + 1);
					line1 = user_erase(line1);
					lines.push_back(line1);
					if (line1.size() > Max_line)
						Max_line = line1.size();
				}
				if (temp == -1) {
					line = user_erase(line);
					lines.push_back(line);
					if (line.size() > Max_line)
						Max_line = line.size();
					break;

				}
			}
	}
	infile.close();
	ofstream op;
	op.open("output.txt");
	for (int i = 0; i < lines.size(); i++) {
		op.width(Max_line + 5);
		op <<left << lines[i]; 
		count1++;
		if (count1 == x) {
			op << endl;
			count1 = 0;
		}
	}
	op.close();
	return 0;
}
