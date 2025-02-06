#include <iostream>

using namespace std;

const int MAX = 10000;

int main() {
    int x;
    cin >> x;
    
    for (int i = 1; i <= MAX; i++) { // i: 대각선 번호
        if (x - i > 0) {
            x -= i;
            continue;
        }
        int numerator = x; // 분자
        int denominator = i - x + 1; // 분모
        
        if (i % 2 != 0) {
            swap(numerator, denominator);
        }
        
        cout << numerator << "/" << denominator;
        return 0;
    }
    
    return 0;
}