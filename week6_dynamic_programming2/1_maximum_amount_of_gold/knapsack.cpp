#include <iostream>
#include<cstring>
#include <vector>
#define max(x,y)(x > y?x:y)

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int dp[W+1];
  memset(dp,0,sizeof(dp));
  dp[0] = 1;
  int ans = 0;
  for(auto va:w){
    for(int i = W; i > -1;--i){
        if(i - va > -1) dp[i] = dp[i] | dp[i-va];
        if(dp[i]) ans = max(ans,i);
    }
  }
  return ans;
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
