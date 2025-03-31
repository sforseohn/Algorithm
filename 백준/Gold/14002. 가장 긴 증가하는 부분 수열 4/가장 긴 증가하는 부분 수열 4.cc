#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 입력
    int n, tmp = 0, idx = 0, len;  // ← 초기화 추가
    int a[1001], dp[1001];
    vector<int> arr;
    cin >> n;

    // 연산
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        len = 0;

        for(int j = 0; j < i; j++) {
            if(a[i] > a[j]) {
                len = max(dp[j], len);
            }
        }
        dp[i] = len + 1;

        if(tmp < dp[i]) {
            tmp = dp[i];
            idx = i;
        }
    }

    for(int i = idx;i >= 0;i--) {
        if(tmp == dp[i]) {
            arr.push_back(a[i]);
            tmp--;
        }
    }

    // 출력
    int size = arr.size();
    cout << size << "\n";

    for(int i = 0; i < size; i++) {
		cout << arr.back() << " ";
        arr.pop_back();
    }

    return 0;
}