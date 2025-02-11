#include <iostream>
#include <vector>

using namespace std;

int findMinPrice(int n, vector<int> road, vector<int> price) {
  int sum = 0;
  int min_price = price[0];
  
  for (int i = 0; i < n - 1; i++) {
    if (min_price > price[i]) {
      min_price = price[i];
    }
    sum += road[i] * min_price;
  }
  return sum;
}

int main() 
{
  // 입력
  int n;
  cin >> n;
  vector<int> road(n-1);
  vector<int> price(n);
  
  for (int i = 0; i < n-1; i++) {
    cin >> road[i];
  }
  
  for (int i = 0; i < n-1; i++) {
    cin >> price[i];
  }
  
  // 연산 & 출력
  cout << findMinPrice(n, road, price);

  return 0;
}