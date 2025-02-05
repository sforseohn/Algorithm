#include <iostream>

using namespace std;
const int SIZE = 9;

int main() {
    int input, max = -1;
    int x, y;
    for (int i = 1; i <= SIZE; i++) {
        for (int j = 1; j <= SIZE; j++) {
            cin >> input;
            if (input > max) {
                max = input;
                x = i;
                y = j;
            }
        }
    }

    cout << max << '\n';
    cout << x << ' ' << y;
    
    return 0;
}