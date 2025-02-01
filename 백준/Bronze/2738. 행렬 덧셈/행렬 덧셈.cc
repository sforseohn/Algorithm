// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>

using namespace std;

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> nums(n, vector<int> (m, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> nums[i][j];
        }
    }
    int num = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> num;
            cout << nums[i][j] + num << " ";
        }
        cout << '\n';
    }

    return 0;
}