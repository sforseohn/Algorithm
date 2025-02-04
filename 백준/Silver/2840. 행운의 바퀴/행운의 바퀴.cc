#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, s;
    char ch;
    
    cin >> n >> k;
    vector<char> wheel(n, '?');
    vector<int> is_used(26, false);
    
    int curIdx = 0;
    while (k--) {
        cin >> s >> ch;
        curIdx -= s % n;
        
        //curIdx = (curIdx + n - s) % n;
        curIdx = curIdx >= 0 ? curIdx : n + curIdx;
        if (wheel[curIdx] == ch) {
            continue;
        }
        
        if (wheel[curIdx] != '?' || is_used[ch-'A']) {
            cout << "!";
            return 0;
        }

        wheel[curIdx] = ch;
        is_used[ch-'A'] = true;
    }
    
    string ans = "";
    for(int i = 0; i < n; i++) {
        ans += wheel[(curIdx + i) % n];
    }
    cout << ans;


    return 0;
}