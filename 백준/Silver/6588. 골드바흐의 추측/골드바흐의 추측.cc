#include <iostream>
#include <vector>

using namespace std;
#define MAX 1000000

vector<bool> isPrime(int n) {
    vector<bool> is_prime(n+1, true);;
    is_prime[0] = is_prime[1] = false;
    for(int i = 2;  i*i <= n; i++) {
        if(is_prime[i]) { // i가 소수라면
            for(int j = i*i; j <= n; j += i) { // 처음 지워지는 수는 제곱수부터, i의 각 배수마다 반복
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> evens; // 입력으로 들어온 짝수들을 저장
    int input;

    vector<bool> prime = isPrime(MAX); // 가장 큰 수까지의 소수 한 번에 저장
    
    while(true) {
        cin >> input; 
        if(input == 0) {
            break;
        }
        int target = input;
        bool check = false;
        for(int i = target - 3; i >= target / 2; i -= 2) {   // target으로부터 3 이상 차이나는 수부터 탐색 (다른 수가 3 이상이므로)
            int other = target - i;
            if(prime[i] && prime[other]) {      // 더해질 두 수가 모두 소수면
                check = true;
                cout << target << " = " << other << " + " << i << "\n"; // 작은 수가 먼저 오도록 결과 출력
                break;
            }
        }

        if (!check) {
            cout << "Goldbach's conjecture is wrong.";
        }
    }
    return 0;
}