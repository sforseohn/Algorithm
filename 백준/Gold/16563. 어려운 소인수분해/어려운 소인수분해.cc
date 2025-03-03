#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 5000000;

vector<int> getPrimes() {
    vector<int> primes(MAX + 1, 0);

    for (int i = 2; i <= sqrt(MAX); i++) {
        if (primes[i] != 0) { // 이미 다른 수에 의해 지워짐
            continue;
        }

        // i는 가장 작은 소인수
        for (int j = i * i; j <= MAX; j += i) {
            if (primes[j] == 0) {
                primes[j] = i;
            }
        }
    }

    return primes;
}

vector<int> getPrimeFactors(int k, vector<int> &primes) {
    vector<int> factors;

    while (primes[k] != 0) {
        factors.push_back(primes[k]);
        k /= primes[k];
    }

    factors.push_back(k);
    return factors;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n;

    vector<int> primes = getPrimes();

    while (n--) {
        cin >> k;
        vector<int> factors = getPrimeFactors(k, primes);

        for (int factor : factors) {
            cout << factor << " ";
        }
        cout << '\n';
    }
}

