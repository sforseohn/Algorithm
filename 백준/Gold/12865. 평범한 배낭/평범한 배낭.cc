#include <iostream>
#include <vector>

using namespace std;

// 1차원 DP 배열 사용
int knapsack1(int n, int k, vector<int>& w, vector<int>& v) {
	// dp[i]: 배낭의 무게가 i일 때, 물건들을 넣어 얻을 수 있는 가치합의 최대값
	vector<int> dp(k + 1, 0);

	// i: 현재 넣으려는 물건
	// j: 배낭의 무게
	for (int i = 0; i < n; i++) {
		for (int j = k; j >= w[i]; j--) {
			// 물건을 넣는 경우 vs 넣지 않는 경우
			int packing = dp[j - w[i]] + v[i];
			int not_packing = dp[j];
			dp[j] = max(packing, not_packing);
		}
	}
	return dp[k];
}

// 2차원 DP 배열 사용
int knapsack2(int n, int k, vector<int>& w, vector<int>& v) {
	// dp[i][j]: 배낭이 버틸 수 있는 무게가 j일 때, 1~i번 물건들을 넣어 얻을 수 있는 가치합의 최대값
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

	// i: 현재 넣으려는 물건
	// j: 배낭이 버틸 수 있는 무게
	for (int i = 0; i < n; i++) {
		// 배낭이 버틸 수 있는 무게 < 물건의 무게
		for (int j = 0; j < w[i]; j++) {
			// 현재 물건을 넣지 못함
			dp[i][j] = dp[i - 1][j];
		}
		 
		// 배낭이 버틸 수 있는 무게 >= 물건의 무게
		for (int j = w[i]; j <= k; j++) {
			// 물건을 넣는 경우 vs 넣지 않는 경우
			int packing = dp[i - 1][j - w[i]] + v[i];
			int not_packing = dp[i - 1][j];
			dp[i][j] = max(packing, not_packing);
		}
	}
	return dp[n][k];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	// 입력
	int n, k;
	cin >> n >> k;

	vector<int> w(n);
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}

	// 연산 & 출력
	cout << knapsack1(n, k, w, v);

	return 0;
}