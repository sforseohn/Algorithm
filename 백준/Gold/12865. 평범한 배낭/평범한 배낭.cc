#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

int getLargestValue(int n, int k, vector<ii> &bag) {
    int ans = 0;
    // dp[i]: 무게 i일 때의 최대 가치
    vector<int> dp(k + 1); // 0 ~ k
    for (int i = 0; i < n; i++) {
        vector<int> new_dp = dp;
        // 가방에 넣을 수 있으면 -> 이전 거에 누적해서 저장
        for (int j = 0; j < k; j++) {
            if (j + bag[i].first <= k) {
                new_dp[j + bag[i].first] = max(dp[j + bag[i].first], dp[j] + bag[i].second);
                ans = max(ans, new_dp[j + bag[i].first]);
            }
        }
        dp = new_dp;
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<ii> bag(n);

    for (int i = 0; i < n; i++) {
        // 무게, 가치 입력
        cin >> bag[i].first >> bag[i].second;
    }

    cout << getLargestValue(n, k, bag);

    return 0;
}