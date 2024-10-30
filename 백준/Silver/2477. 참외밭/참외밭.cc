#include <iostream>
using namespace std;
pair<int, int> li[12];

int findArea() { // 육각형 모양의 영역 너비를 구하는 함수
    int big_square;
    int small_square;
    for (int i = 0; i < 9; i++) {
        if (li[i].first == li[i + 2].first && li[i + 1].first == li[i + 3].first) { 
            big_square = (li[i].second + li[i + 2].second) * (li[i + 1].second + li[i + 3].second); 
            small_square = li[i + 2].second * li[i + 1].second; 
        }
    }
    return big_square - small_square;
}

int main() {
    int k;
    cin >> k;

    int direction, length;
    for (int i = 0; i < 6; i++) {
        cin >> direction >> length;
        li[i] = {direction, length};
    }

    for (int i = 0; i < 6; i++) { 
        li[i + 6] = li[i];
    }

    int area = findArea();
    cout << k * area << "\n";
    
    return 0;
}