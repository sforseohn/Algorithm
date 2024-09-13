#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, x; // 연산 횟수, 연산 종류
    priority_queue<int> pq;

    cin >> n;
    while(n--) {
        cin >> x;
        if(x == 0) {
            // 힙이 비었다면 0을 출력하고
            if(pq.empty()) {
                cout << "0" << '\n';
            }
            // 가장 큰 값을 출력
            else {
                cout << pq.top() << '\n'; // pq.pop()은 리턴값 없음
                pq.pop();
            }
        }
        else {
            // x 삽입
            pq.push(x);
        }
    }
    return 0;
}