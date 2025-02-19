#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 에라토스테네스의 체로 소수 판정
int isPrime(int n, int target) {
    vector<bool> is_prime(n + 1, true);
    int cnt = 0;

    for (int i = 2; i <= n; i++) {
        if (!is_prime[i]) {
            continue;
        }

        for (int j = i; j <= n; j += i) {
            if (!is_prime[j]) {
                continue;
            }

            if (++cnt == target) {
                return j;
            }
            is_prime[j] = false;
        }
    }
    return 0;
}

int main() {
    int n, k;
    cin >> n >> k;

    int ans = isPrime(n, k);

    cout << ans << '\n';
    
    return 0;
}