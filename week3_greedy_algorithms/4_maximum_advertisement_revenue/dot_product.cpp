#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using std::vector;

long long max_dot_product(vector<int> a, vector<int> b) {
  // write your code here
  sort(a.begin(),a.end()); sort(b.begin(),b.end());
  ll result = 0;
  for (size_t i = 0; i < a.size(); i++)
    result += (ll)a[i]*(ll)b[i];
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
