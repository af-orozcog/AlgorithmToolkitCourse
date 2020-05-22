#include <iostream>
#define ll long long

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

ll gcd(ll a,ll b){
    return b == 0ll? a: gcd(b,a%b);
}

ll lcm(ll a, ll b){
    return (a/gcd(a,b))*b;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm(a, b) << std::endl;
  return 0;
}
