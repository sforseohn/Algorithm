#include <iostream>
#include <map>

using namespace std;

int main() 
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n, cnt = 0;
  string input;
  cin >> n;
  map<string, bool> nicknames;
  
  while (n--) {
    cin >> input;
    
    if (input == "ENTER") {
      nicknames.clear();
      continue;
    }
    
    if (!nicknames[input]) {
      cnt++;
      nicknames[input] = true;
    }
  }

  cout << cnt;
  return 0;
}