#include <bits/stdc++.h>
using namespace std;

int get_change(int m) {
  int dp[m+1];
  dp[0] = 0;
  int de[] = {1,3,4};
  for(int i = 1; i <= m;++i){
    dp[i] = 1000000000;
    for(int j = 0; j < 3;++j)
        if(i - de[j] > -1)
            dp[i] = min(dp[i],dp[i-de[j]]+1);
  }
  return dp[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
