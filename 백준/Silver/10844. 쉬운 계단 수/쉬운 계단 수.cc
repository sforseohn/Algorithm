#include <iostream>
#include <vector>

using namespace std;

const int INF = 1000000000;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<vector<ll>> dp(n + 1, vector<ll>(10));

    // 일의 자리수
    for (int i = 1; i < 10; i++) {
        dp[1][i] = 1;
    }

    // 2의 자리수 ~ n의 자리수
    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i-1][1];
        dp[i][9] = dp[i-1][8];

        for (int j = 1; j < 9; j++) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % INF;
        }
    }
    
    // 정답
    ll ans = 0;
    for (int i = 0; i < 10; i++) {
        ans = (ans + dp[n][i]) % INF;
    }
    
    cout << ans << '\n';

    return 0;
}