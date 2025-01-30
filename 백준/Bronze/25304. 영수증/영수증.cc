// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

int main() {
    int x, n;
    cin >> x;
    cin >> n;
    
    while(n--) {
        int a, b;
        cin >> a >> b;
        x -= a * b;
    }
    
    if (x != 0) {
        cout << "No";
    }
    else {
        cout << "Yes";
    }
    
    return 0;
}