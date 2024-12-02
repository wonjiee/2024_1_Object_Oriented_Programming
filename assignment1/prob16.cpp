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
    cout << "1,000,000번 시행결과 6번 던져서 적어도 1번 1이 나오는 사건의 확률은 " << win1 / 1000000.0 << " 입니다." << endl;
    cout << "1,000,000번 시행결과 12번 던져서 적어도 2번 1이 나오는 사건의 확률은 " << win2 / 1000000.0 << " 입니다." << endl;
    return 0;
}