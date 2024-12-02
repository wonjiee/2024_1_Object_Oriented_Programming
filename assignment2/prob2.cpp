#include <iostream>
#include <string>
using namespace std;
int main() {
	string line;
	while (true) {
		getline(cin, line);
		if (line == "exit")
			break;
		while (true) {
			int temp = line.find(" ");
			if (temp == 0) {
				line.erase(temp, 1);
				continue;
			}
			else break;
		}
		while (true) {
			int temp = line.find("  ");
			if (temp != -1) {
				line.erase(temp, 1);
				continue;
			}
			else break;
		}
		cout << line << ":" << line.length() << endl;
	}
	return 0;
	
}