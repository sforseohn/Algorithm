#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

int main() 
{
  int n;
  cin >> n;
  vector<ii> lines(n);
  vector<int> dp(n, 1); // dp[i] : i번째 수를 마지막 원소로 가지는 부분 수열의 최대 길이
  
  for (int i = 0; i < n; i++) {
    cin >> lines[i].first >> lines[i].second;
  }
  
  // 정렬
  sort(lines.begin(), lines.end());
  
  // 최장 증가 부분 수열 문제 (LIS)
  // 각 요소를 순회하며 앞 요소 중 자신보다 작은 수가 있다면 dp 업데이트
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (lines[j].second < lines[i].second) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }

  cout << n - *max_element(dp.begin(), dp.end());
  
  return 0;
} 