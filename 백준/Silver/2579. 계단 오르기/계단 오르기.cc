//
// Created by user on 2025. 3. 31..
//

#include <iostream>
#include <vector>

using namespace std;

int getMaxScore(int n, vector<int> &score) {
    vector<int> dp(n + 1, 0); // dp[i]: i번째 계단까지 왔을 때 점수의 최댓값

    // 초깃값
    dp[1] = score[1];
    dp[2] = score[1] + score[2];

    // 점화식
    for (int i = 3; i <= n; i++) {
        int one_step_before = dp[i - 3] + score[i-1];
        int two_steps_before = dp[i - 2];
        dp[i] = max(one_step_before, two_steps_before) + score[i];
    }
    
    return dp[n];
}

int main() {
    // 입력
    int n;
    cin >> n;
    vector<int> score(n + 1, 0);
    // score[i] -> i번째 계단의 금액
    for (int i = 1; i <= n; i++) {
        cin >> score[i];
    }

    int answer = getMaxScore(n, score);

    cout << answer << '\n';
    
    return 0;
}
