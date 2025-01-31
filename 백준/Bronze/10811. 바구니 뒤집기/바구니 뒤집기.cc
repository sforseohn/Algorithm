#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n + 1);
    
    for (int i = 1; i <= n; i++) {
        nums[i] = i;
    }
    
    while(m--) {
        int i, j;
        cin >> i >> j;
        for (int k = 0; k <= (j - i) / 2; k++) {
            swap(nums[i + k], nums[j - k]);
        }
    }
    
    for (int q = 1; q <= n; q++) {
        cout << nums[q] << " ";
    }
    
    return 0;
}