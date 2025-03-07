#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getGcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return getGcd(b, a % b);
}

// 가능한 모든 M을 반환하는 함수
vector<int> solution(int n, vector<int> &numbers) {
    vector<int> result;

    // 이웃한 수들 간의 차의 최대공약수 구하기
    sort(numbers.begin(), numbers.end());
    int gcd = numbers[1] - numbers[0];

    for (int i = 2; i < n; i++) {
        gcd = getGcd(gcd, numbers[i] - numbers[i - 1]);
    }

    // 최대공약수의 약수 구해서 리턴
    for (int i = 2; i <= gcd / 2; i++) {
        if (gcd % i == 0) {
            result.push_back(i);
        }
    }
    result.push_back(gcd);
    return result;
}

int main() {
    // 입력
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    vector<int> result = solution(n, numbers);

    for (int i: result) {
        cout << i << ' ';
    }
    return 0;
}
