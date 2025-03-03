#include <iostream>
#include <vector>

using namespace std;

int findPrime(int n, int k) {
    int cnt = 0;
    vector<bool> is_prime(n+1, true); // 소수 여부 저장

    for (int i = 2; i <= n; i++) {
        if (!is_prime[i]) { // 이미 지워진 수이면 탐색 X
            continue;
        }
        
        for (int j = i; j <= n; j += i) {
            if (!is_prime[j]) { // 이미 지워진 수이면 탐색 X
                continue;
            }

            is_prime[j] = false;

            if (++cnt == k) {
                return j;
            }
        }
    }
    return -1;
}

int main()
{
    int n, k;
    cin >> n >> k;

    cout << findPrime(n, k) << '\n';
}
