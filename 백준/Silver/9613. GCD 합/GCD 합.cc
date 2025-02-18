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

ll getGcdSum(int n, vector<ll> &nums) {
    ll sum = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            sum += getGcd(nums[i], nums[j]);
        }
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<ll> nums(n);

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        cout << getGcdSum(n, nums) << '\n';
    }
   
    return 0;
}