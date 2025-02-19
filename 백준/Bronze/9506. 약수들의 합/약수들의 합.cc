#include <iostream>
#include <vector>

using namespace std;

string checkCompleteNumber(int n) {
    int sum = 0;
    vector<int> divisors;

    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum += i;
            divisors.push_back(i);
        }
    }

    if (n == sum) {
        string ans = to_string(n) + " = ";
        for (int i = 0; i < divisors.size() - 1; i++) {
            ans += to_string(divisors[i]) + " + ";
        }
        return ans + to_string(divisors[divisors.size() - 1]);
    }
    else {
        return to_string(n) + " is NOT perfect.";
    }
}

int main() {
    int n;
    while (true) {
        cin >> n;

        if (n == -1) {
            return 0;
        }

        cout << checkCompleteNumber(n) << '\n';
    }
    
    return 0;
}