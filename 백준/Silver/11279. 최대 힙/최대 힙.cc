#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, x;
    
    // 입력
    cin >> n;
    
    priority_queue<int> max_heap;
    
    // 연산    
    while(n--) {
        cin >> x;
        
        // x가 0이면 가장 큰 값을 출력하고 제거
        if (x == 0) {
            if (max_heap.empty()) {
                // 힙이 비었다면 0 출력 
                cout << "0\n";
                continue;
            }
            cout << max_heap.top() << '\n';
            max_heap.pop();
        }
        
        // x가 자연수라면 힙에 x 추가
        else {
            max_heap.push(x);
        }
    }

    return 0;
}