#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, v;
    
    // 입력
    cin >> n;
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    cin >> v;
    
    // 연산
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == v) {
            cnt++;
        }
    }
    
    // 출력
    cout << cnt;

    return 0;
}