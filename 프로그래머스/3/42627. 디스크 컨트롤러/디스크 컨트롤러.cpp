#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// 소요시간이 작은 순으로 sort
struct sortByMinTime {
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int curr_time = 0;
    int total_time = 0;
    int next_job = 0;
    int job_cnt = jobs.size();
    
    // 현재 시점에서 요청된 작업을 소요시간이 작은 순으로 저장할 우선순위 큐
    priority_queue<vector<int>, vector<vector<int>>, sortByMinTime> pq;
    
    sort(jobs.begin(), jobs.end()); // 요청시간이 작은 순으로 sort
    
    // 남아있는 작업이 있을 때까지 반복
    while(next_job < job_cnt || !pq.empty()) {
        // 현재 시점에서 요청된 task가 없는 경우
        if (pq.empty()) {
            curr_time = jobs[next_job][0]; // 현재 시점을 가장 빠른 task의 요청 시점으로 변경
            pq.push(jobs[next_job++]);
        }
        
        // 현재 시점에서 요청된 task가 있는 경우
        // pq에 들어 있는 task 중 소요시간이 가장 빠른 작업 수행
        vector<int> curr_job = pq.top();
        pq.pop();
        
        // 시점 갱신
        total_time += curr_time - curr_job[0] + curr_job[1]; // 요청부터 실행된 시점까지 지연된 시간 + 작업의 실제 소요시간
        curr_time += curr_job[1];
        
        // 다음 시점에서 요청된 작업을 pq에 삽입
        while(next_job < job_cnt && jobs[next_job][0] <= curr_time) {
            pq.push(jobs[next_job++]);
        }
    }
    
    answer = int(total_time / job_cnt);
    
    return answer;
}