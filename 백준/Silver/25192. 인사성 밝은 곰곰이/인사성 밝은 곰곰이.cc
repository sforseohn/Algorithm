#include <iostream>
#include <set>

using namespace std;

int main() 
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n, cnt = 0;
  string input;
  cin >> n;
  set<string> nicknames;
  
  while (n--) {
    cin >> input;
    
    if (input == "ENTER") {
      nicknames.clear();
      continue;
    }
    
    if (nicknames.find(input) == nicknames.end()) {
      cnt++;
      nicknames.insert(input);
    }
  }

  cout << cnt;
  return 0;
}