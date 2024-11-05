#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll cntPeople(ll n, ll mid, vector<ll> &time){
    // mid 시간에 검사할 수 있는 최대 인원 수
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += mid / time[i];
    }
    return cnt;
}

ll binarySearch(ll n, ll m, vector<ll> &time) {
    ll left = 1;
    ll right = m * time[0];  // 심사 시간이 제일 짧은 데스크에 모든 사람이 검사 받는 경우를 최댓값으로 초기화
    ll mid;
    ll people;

    while (left <= right) {
        mid = (left + right) / 2;
        people = cntPeople(n, mid, time);

        // mid에서 검사 가능 인원이 m 명 이상일 시 -> 조건 만족, 심사시간을 줄여보자
        if (people >= m) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    // 입력
    ll n, m;
    cin >> n >> m;
    vector<ll> time(n);
        for (int i = 0; i < n; i++) {
        cin >> time[i];
    }

    sort(time.begin(), time.end());
    // 연산 & 출력
    cout << binarySearch(n, m, time);

    return 0;
}