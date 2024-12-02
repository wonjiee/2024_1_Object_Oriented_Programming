#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int count = 1;
    for (int i = 1; ; i++) {
        for (int j = 1; j <= (2.0 / 3 * i); j++) {
            if (j <= (2.0 / 3 * i) && j >= (1.0 / 3 * i)) {
                if (i * i + j * j <= 10000) {
                    count++;
                  
                }
                if (i==100)
                {
                    cout << count;
                    return 0;
                }
               
                
            }
        }
    }
    return 0;
}