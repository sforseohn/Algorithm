#include <iostream>
#include <vector>

using namespace std;

int cntBlueray(int n, int mid, vector<int> &lesson) {
    int cnt = 1; // 블루레이의 개수
    int cur_sum = 0; // 현재 블루레이에 들어간 총 강의 길이

    for (int i = 0; i < n; i++) {
        if (cur_sum + lesson[i] > mid) {
            cnt++;
            cur_sum = 0;
        }
        cur_sum += lesson[i];
    }
    return cnt;
}

int findSize(int left, int right, vector<int> lesson, int n, int target) {
    while(left <= right) {
        // mid: 블루레이 크기
        int mid = (left + right) / 2;
        // 크기가 mid인 블루레이로 모든 강의를 담을 때 필요한 블루레이의 총 개수
        int cnt = cntBlueray(n, mid, lesson);

        // 필요한 블루레이의 개수가 주어진 개수보다 적음 
        // -> 블루레이의 크기가 큼
        // 블루레이의 크기를 줄여보자
        if (cnt <= target) { 
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    // 입력
    int n, m; // 강의의 수, 블루레이의 수
    cin >> n >> m;
    vector<int> lesson(n); // 강의의 길이

    int sum_len = 0, max_len = 0;

    for (int i = 0; i < n; i++) {
        cin >> lesson[i];
        // left: 강의 길이의 최댓값
        max_len = max(lesson[i], max_len);

        // right: 강의 길이의 총합
        sum_len += lesson[i];
    }

    cout << findSize(max_len, sum_len, lesson, n, m);

    return 0;
}