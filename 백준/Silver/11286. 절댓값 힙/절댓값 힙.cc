#include <iostream>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(const int &x, const int &y) {
        // 절댓값이 같은 경우 절댓값이 작은 수를 앞으로
        if (abs(x) != abs(y)) {
            return abs(x) > abs(y);
        }
        // 절댓값이 다른 경우 값이 작은 수를 앞으로
        return x > y;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, x;
    
    // 입력
    cin >> n;
    
    priority_queue<int, vector<int>, cmp> pq;
    
    // 연산    
    while(n--) {
        cin >> x;
        
        // x가 0이면 가장 큰 값을 출력하고 제거
        if (x == 0) {
            if (pq.empty()) {
                // 힙이 비었다면 0 출력 
                cout << "0\n";
                continue;
            }
            cout << pq.top() << '\n';
            pq.pop();
        }
        
        // x가 자연수라면 힙에 x 추가
        else {
            pq.push(x);
        }
    }

    return 0;
}