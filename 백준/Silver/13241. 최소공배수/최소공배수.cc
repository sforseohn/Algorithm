#include <iostream>

using namespace std;

typedef long long ll;

ll getGcd(ll a, ll b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll getLcm(ll a, ll b) { // 최소공배수 = 두 수의 곱 / 최대공약수
    ll gcd = getGcd(a, b);
    return a * b / gcd;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll a, b;
    
    cin >> a >> b;
    cout << getLcm(a, b) << '\n';
    
    return 0;
}