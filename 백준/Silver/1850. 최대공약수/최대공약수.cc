#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll getGcd(ll a, ll b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll a, b;
    cin >> a >> b;

    ll ans = getGcd(a, b);
    
    for (ll i = 0; i < ans; i++) {
        cout << "1";
    }
    cout << '\n';
   
    return 0;
}