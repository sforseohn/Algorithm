#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100;

int main() 
{
  vector<long long> lines(MAX + 1);
  
  lines[1] = lines[2] = lines[3] = 1;
  lines[4] = lines[5] = 2;
  
  for (int i = 6; i <= MAX; i++) {
    lines[i] = lines[i - 1] + lines[i - 5];
  }
  
  int t, input;
  cin >> t;
  while (t--) {
    cin >> input;
    cout << lines[input] << '\n';
  }

  return 0;
}