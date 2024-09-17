#include <iostream>
#include <queue>

using namespace std;

void balance(priority_queue<int> &max_pq, priority_queue<int, vector<int>, greater<>> &min_pq) {
    // 각 우선순위 큐의 top값 저장
    int top_max = max_pq.top();
    int top_min = min_pq.top();

    // max_pq의 top 값이 min_pq의 top값보다 클 때 교환
    if (max_pq.top() > min_pq.top()) {
        max_pq.pop();
        min_pq.pop();

        max_pq.push(top_min);
        min_pq.push(top_max);
    }
    return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

    int n, num;
    // 비교적 작은 값을 저장해줄 max heap (왼쪽 큐)
    priority_queue<int> max_pq;

    // 비교적 큰 값을 저장해줄 min heap (오른쪽 큐)
    priority_queue<int, vector<int>, greater<>> min_pq;

    // 입력
    cin >> n;
    while(n--) {
        cin >> num;

        // 우선순위 큐에 num 저장
        // max_pq의 사이즈가 min_pq의 사이즈와 같거나 하나 더 많게 저장
        if (max_pq.size() > min_pq.size()) {
            min_pq.push(num);
        }
        else {
            max_pq.push(num);
        }

        // 균형 맞추기
        if (!max_pq.empty() && !min_pq.empty()) {
            balance(max_pq, min_pq);
        }
        // 출력
        cout << max_pq.top() << '\n';
    }

	return 0;
}