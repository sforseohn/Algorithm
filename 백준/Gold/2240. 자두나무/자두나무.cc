#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t, w;
  cin >> t >> w;

  vector<vector<int> > dp(t + 1, vector<int>(w + 1));
  vector<int> plum(t + 1);
    
  for (int i = 1; i <= t; i++) {
    cin >> plum[i];
  }
    
  int max_fruit_cnt = 0;
  for (int i = 1; i <= t; i++) {
    for (int j = 0; j <= w; j++) {
      // 다른 칸에서 움직임 카운트 소모해서 왔거나 이전 칸에서 유지
      if ((plum[i] == 1 && j % 2 == 0) || (plum[i] == 2 && j % 2 == 1)) {
        // 자두가 1번 나무에 떨어지고, 짝수번 이동한 경우
        // 자두가 2번 나무에 떨어지고, 홀수번 이동한 경우
        dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]);
      }
      max_fruit_cnt = max(dp[i][j], max_fruit_cnt);
    }
  }

  cout << max_fruit_cnt;

  return 0;
}
