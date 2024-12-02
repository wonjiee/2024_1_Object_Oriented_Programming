#include <iostream>

using namespace std;

int main(){

int first[2];
int second[2];
int i, j;
cout << "첫번째 구간을 입력하세요. : " << endl;
for (int i = 0; i < 2; i++) {
	cin >> first[i];
}
cout << "두번째 구간을 입력하세요. : " << endl;
for (int j = 0; j < 2; j++) {  
	cin >> second[j];
}
if (first[0] <= second[0] && second[0] <= first[1]) {
	cout << "Yes";
}
else if (first[0] <= second[1] && second[1] <= first[1]) {
	cout << "Yes";
}
else cout << "No";
return 0;
}

