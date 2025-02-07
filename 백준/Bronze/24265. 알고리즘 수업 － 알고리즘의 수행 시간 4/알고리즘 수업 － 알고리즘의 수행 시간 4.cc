#include <iostream>
using namespace std;

int main() 
{
  long long n;
  cin >> n;
  
  long long cnt = 0;
  for (int i = 1; i <= n - 1; i++) {
    for (int j = i + 1; j <= n; j++) {
      cnt++;
    }
  }
  cout << cnt << '\n';
  cout << 2;
  return 0;
}