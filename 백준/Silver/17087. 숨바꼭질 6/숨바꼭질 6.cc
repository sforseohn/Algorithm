#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 최대공약수를 구하는 함수
int getGCD(int a, int b) {
    while(b) {
        a %= b;     // 유클리드 호제법 사용
        swap(a, b); // b가 a보다 커졌으므로 둘이 바꿈
    }
    return a; 
}

int main() {
    // 입출력 속도 향상 코드
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, s;
    cin >> n >> s;
    vector<int> diffs;
    int input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        diffs.push_back(abs(s - input));
    }
    
    //sort(diffs.begin(), diffs.end());
    
    int gcd = diffs[0];
    
    for (int i = 1; i < n; i++) {
        gcd = getGCD(diffs[i], gcd);
    }

    cout << gcd;

    return 0;
}