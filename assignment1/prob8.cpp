#include <iostream>

using namespace std;

int main(){

int first[2];
int second[2];
int i, j;
cout << "ù��° ������ �Է��ϼ���. : " << endl;
for (int i = 0; i < 2; i++) {
	cin >> first[i];
}
cout << "�ι�° ������ �Է��ϼ���. : " << endl;
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

