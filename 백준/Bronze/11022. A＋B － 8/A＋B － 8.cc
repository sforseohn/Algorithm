#include <iostream>

using namespace std;
// Case #1: 1 + 1 = 2

int main() {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        cout << "Case #" << i << ": ";
        cout << a << " + " << b << " = " << a + b << '\n';
    }
    
    return 0;
}