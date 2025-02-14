#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  
  for (int i = 1; i < n; i++) {
    nums[i] = max(nums[i], nums[i - 1] + nums[i]);
  }

  cout << *max_element(nums.begin(), nums.end());
  return 0;
}