#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int sum = 0, input;
    
    for (int i = 0; i < 5; i++) {
        cin >> input;
        sum += pow(input, 2);
    }
    
    cout << sum % 10;
    
    return 0;
}