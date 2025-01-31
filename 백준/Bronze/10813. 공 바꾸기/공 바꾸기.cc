#include <iostream>
#include <vector>
#include <algorithm>

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
        
        swap(nums[i], nums[j]);
    }
    
    for (int i = 1; i <= n; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}