#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 가장 인접한 두 공유기 사이의 거리가 dist가 되도록 공유기를 설치했을 때, 설치된 공유기 개수
int cntRouter(int dist, vector<int> &house) {
    int cnt = 1; // 첫 번째 집에 무조건 설치
    int cur = house[0]; // 현재 좌표
    
    for (int i = 0; i < house.size(); i++) {
        if (house[i] - cur >= dist) { // 가장 가까운 집과의 거리가 dist 이상이면
            cnt++; // 공유기 설치
            cur = house[i]; // 좌표 업데이트
        }
    }
    return cnt; 
}

// target개의 공유기를 설치 가능한 최소 인접 거리의 최댓값 (=upper bound 탐색)
int binarySearch(int left, int right, int target, vector<int> &house) {
    while (left <= right) {
        // 가장 인접한 두 공유기 사이의 거리가 mid일 때, 설치할 수 있는 공유기 개수
        int mid = (left + right) / 2;
        int installed = cntRouter(mid, house);
        
        if (installed >= target) { // mid의 거리로 target 개수 이상의 공유기 설치 가능 -> 거리를 늘려보자
            left = mid + 1;
        }
        else { // mid의 거리로는 target만큼의 공유기를 설치할 수 없음 -> 거리를 줄여보자
            right = mid - 1;
        }
    }
    return left - 1; // upper bound에서 1을 뺀 값
}

int main()
{
    int n, c; // 집의 개수, 공유기의 개수
    // 입력
    cin >> n >> c;
    vector<int> house(n); // 집의 좌표 배열
    for (int i = 0; i < n; i++) {
        cin >> house[i];
    }
    
    sort(house.begin(), house.end()); // 정렬
    
    cout << binarySearch(1, house[n - 1] - house[0], c, house);

    return 0;
}