#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand((unsigned int)time(NULL)); 
    int count1 = 0;
    int count2 = 0;
    int win1 = 0;
    int win2 = 0;

    for (int count = 0; count < 1000000; count++) {
        count1 = 0;
        for (int i = 0; i < 6; i++) {
            int random_value = rand() % 6 + 1;
            if (random_value == 1)
                count1++;
        }
        if (count1 >= 1)
            win1++;
    }


    for (int count = 0; count < 1000000; count++) {
        count1 = 0;
        for (int i = 0; i < 12; i++) {
            int random_value = rand() % 6 + 1;
            if (random_value == 1)
                count1++;
        }
        if (count1 >= 2)
            win2++;
    }

    cout << win1 << " " << win2 << endl;
    cout << "1,000,000�� ������ 6�� ������ ��� 1�� 1�� ������ ����� Ȯ���� " << win1 / 1000000.0 << " �Դϴ�." << endl;
    cout << "1,000,000�� ������ 12�� ������ ��� 2�� 1�� ������ ����� Ȯ���� " << win2 / 1000000.0 << " �Դϴ�." << endl;
    return 0;
}