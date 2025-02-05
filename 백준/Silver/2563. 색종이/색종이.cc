#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 100;
const int PAPER_SIZE = 10;

int main() {
    vector<vector<bool>> is_black(SIZE, vector<bool>(SIZE, false));
    
    int paper_cnt;
    cin >> paper_cnt;
    
    while(paper_cnt--) {
        int min_x, min_y;
        cin >> min_x >> min_y;
        
        for (int i = 0; i < PAPER_SIZE; i++) {
            for (int j = 0; j < PAPER_SIZE; j++) {
                is_black[min_x + i][min_y + j] = true;
            }
        }
    }
    
    int cnt = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (is_black[i][j]) {
                cnt++;
            }
        }
    }
    
    cout << cnt;
    
    return 0;
}