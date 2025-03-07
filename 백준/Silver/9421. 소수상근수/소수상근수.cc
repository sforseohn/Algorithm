#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<bool> getPrimes(int n) {
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;

  for (int i = 2; i * i <= n; i++) {
    if (!is_prime[i]) {
      continue;
    }

    for (int j = i * i; j <= n; j += i) {
      is_prime[j] = false;
    }
  }

  return is_prime;
}

bool isTargetNum(int num) {
  vector<int> prev_num;

  while (true) {
    int sum = 0;
    string nums_str = to_string(num);
    for (int j = 0; j < nums_str.length(); j++) {
      int num = nums_str[j] - '0';
      sum += num * num;
    }

    if (sum == 1) {
      return true;
    }

    if (find(prev_num.begin(), prev_num.end(), num) != prev_num.end()) {
      return false;
    }
    prev_num.push_back(num);
    num = sum;
  }
}

int main() {
  int n;
  cin >> n;

  vector<bool> is_prime = getPrimes(n);

  for (int i = 1; i <= n; i++) {
    if (is_prime[i] && isTargetNum(i)) {
      cout << i << '\n';
    }
  }

  return 0;
}