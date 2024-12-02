#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
	string data;
	getline(cin, data);
	int sum = 0, start = 0;
	size_t plus = data.find("+");
	size_t minus = data.find("-");
	while (true) {
		if (isdigit(data[0])) {
			if (plus == -1&& minus == -1) {
				sum += stoi(data);
				break;
			}
			else if (plus < minus || minus == -1) {
				string part = data.substr(0, plus);
				data.erase(0, plus);
				sum += stoi(part);
			}
			else if (plus > minus || plus == -1) {
				string part = data.substr(0, minus);
				data.erase(0, minus);
				sum += stoi(part);
			}
		}
		if (data[0] == '+') {
			data.erase(0, 1);
			size_t plus = data.find("+");
			size_t minus = data.find("-");
			if (plus == -1 && minus == -1) {
				sum += stoi(data);
				break;
			}
		
			if (plus < minus || minus == -1) {
				string part = data.substr(0,plus);
				data.erase(0, plus);
				sum += stoi(part);
			}
			if (plus > minus || plus == -1) {
				string part = data.substr(0,minus);
				data.erase(0, minus);
				sum += stoi(part);
			}
		}
		if (data[0] == '-') {
			data.erase(0, 1);
			size_t plus = data.find("+");
			size_t minus = data.find("-");
			if (plus == -1 && minus == -1) {
				sum -= stoi(data);
				break;
			}
			if (plus < minus || minus == -1) {
				string part = data.substr(0, plus);
				data.erase(0, plus);
				sum -= stoi(part);
			}
			if (plus > minus || plus == -1) {
				string part = data.substr(0, minus);
				data.erase(0, minus);
				sum -= stoi(part);
			}
		}
	}
	cout << sum;
	return 0;
}


