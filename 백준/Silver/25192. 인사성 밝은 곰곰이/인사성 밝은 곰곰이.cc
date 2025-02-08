#include <iostream>
#include <map>

using namespace std;

int main() 
{
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