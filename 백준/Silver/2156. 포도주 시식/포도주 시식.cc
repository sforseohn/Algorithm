#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> wine(n);
    vector<int> dp(n);

    for (int i = 0; i < n; i++) {
        cin >> wine[i];
    }

    dp[0] = wine[0];
    dp[1] = wine[0] + wine[1];
    for (int i = 2; i < n; i++) {
        dp[i] = wine[i] + max(dp[i-2], dp[i-3] + wine[i-1]);
        dp[i] = max(dp[i-1], dp[i]);
    }

    cout << dp[n-1] << '\n';
    
    return 0;
}