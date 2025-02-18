#include <iostream>

using namespace std;

int getGcd(int a, int b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int getLcm(int a, int b) { // 최소공배수 = 두 수의 곱 / 최대공약수
    int gcd = getGcd(a, b);
    return a * b / gcd;
}

int main() {
    int n, a, b;
    cin >> n;

    while(n--) {
        cin >> a >> b;
        cout << getLcm(a, b) << '\n';
    }

    return 0;
}