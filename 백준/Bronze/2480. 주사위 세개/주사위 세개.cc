#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    
    int result = 0;
    if (a == b && b == c) {
        result = 10000 + a * 1000;
    }
    else if (a == b || b == c) {
        result = 1000 + b * 100;
    }
    else if (c == a) {
        result = 1000 + a * 100;
    }
    else {
        result = max(max(a, b), c) * 100;
    }
    
    cout << result;

    return 0;
}