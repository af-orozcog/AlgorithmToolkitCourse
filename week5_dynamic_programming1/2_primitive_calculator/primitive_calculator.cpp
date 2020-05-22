#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> optimal_sequence(int n) {
  vector<int> sequence;
  int dp[n+1];
  dp[1] = 0;
  for(int i = 2; i <= n;++i){
    dp[i] = 1000000000;
    if((i&1) == 0) dp[i] = min(dp[i],dp[i>>1]+1);
    if(i % 3 == 0) dp[i] = min(dp[i],dp[i/3]+1);
    dp[i] = min(dp[i],dp[i-1]+1);
  }
  for(int i = n; i != 1;){
    sequence.push_back(i);
    int who,ma = 1000000000;
    if(dp[i-1] < ma) who = i-1,ma = dp[i-1];
    if((i&1) == 0 && dp[i>>1] < ma) who = i>>1,ma = dp[i>>1];
    if(i % 3 == 0 && dp[i/3] < ma) who = i/3,ma = dp[i/3];
    i = who;
  }
  sequence.push_back(1);
  reverse(sequence.begin(),sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
