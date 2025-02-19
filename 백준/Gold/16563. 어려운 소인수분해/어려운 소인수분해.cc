#include <iostream>
#include <vector>

using namespace std;

const int MAX = 5000000;
vector<int> getPrime() {
    vector<int> prime(MAX+1, 0); // 크기, 초기화
    for(int i = 2; i * i <= MAX; i++) {
        if(prime[i] == 0) {
            for(int j = i*i; j <= MAX; j += i) {
                if(prime[j] == 0) { // j에 저장된 것이 없다면 저장
                    prime[j] = i;
                }
            }
        }
    }
    return prime;
}

// 소인수 전부 찾기
vector<int> getFactors(int k, vector<int> &prime) { // 원본 프라임이 변경됨
    vector<int> factors;
    while(prime[k] != 0) {
        factors.push_back(prime[k]);
        k /= prime[k];
    }
    factors.push_back(k);
    return factors;
}

int main() { // 최대한 메인에서는 입출력만 일어나도록
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n; 

    vector<int> prime = getPrime();
    
    for(int i = 0; i < n; i++) {
        cin >> k;

        // 소인수 출력
        vector<int> factors = getFactors(k, prime);

        for(int num : factors) {
            cout << num << " ";
        }
        cout << "\n";
    }
}