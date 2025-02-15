#include <iostream>
#include <vector>

using namespace std;

const int MAX = 10e6;

int main() 
{
  long long n;
  cin >> n;
  vector<int> dp(n + 1, MAX);
  
  dp[1] = 0;
  dp[2] = 1;
  dp[3] = 1;
  
  for (int i = 4; i <= n; i++) {
    if (i % 3 == 0) {
      dp[i] = min(dp[i], dp[i / 3] + 1);
    }
    
    if (i % 2 == 0) {
      dp[i] = min(dp[i], dp[i / 2] + 1);
    }
    
    dp[i] = min(dp[i], dp[i - 1] + 1);
  }
  
  cout << dp[n];
  
  return 0;
}