#include <iostream>
#include <vector>

using namespace std;
const int CONNECTED = 1;

void floydWarshall(int n, vector<vector<int>> &graph) {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(graph[i][k] && graph[k][j]) {
                    graph[i][j] = CONNECTED;
                }
            }
        }
    }
}

int findStudent(int n, vector<vector<int>> &graph) {
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int cnt = 0;
        for(int j = 1; j <= n; j++) {
            if(graph[i][j] || graph[j][i]) {
                cnt++;

                if(cnt >= n - 1) {
                    ans++;
                }
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, a, b;

    // 입력
    cin >> n >> m;
    vector<vector<int>> graph(n+1, vector<int>(n+1, 0));

    while(m--) {
        cin >> a >> b;
        graph[a][b] = CONNECTED; // 연결 표시
    }

    // 연산
    floydWarshall(n, graph);

    int ans = findStudent(n, graph);

    cout << ans << '\n';

    return 0;
}