#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
  int n;
  cin >> n;
  vector<int> nums(n);
  vector<int> dp(n, 1); // dp[i] : i번째 수를 마지막 원소로 가지는 부분 수열의 최대 길이
  
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
    
  for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
          if (nums[j] < nums[i]) {
              dp[i] = max(dp[i], dp[j] + 1);
          }
      }
  }

  cout << *max_element(dp.begin(), dp.end());
  
  return 0;
} 