#include <iostream>
#include<cstring>
#include <vector>

using std::vector;

int dp[22][201][201];

int partition3(vector<int> &A) {
  //write your code here
  int sum = 0;
  for(auto va: A) sum += va;
  if(sum % 3 != 0)return 0;
  int tar = sum/3;
  dp[0][0][0] = 1;
  for(int i = 1; i <= A.size();++i){
    for(int j = 0; j <= tar;++j){
        for(int k = 0; k <= tar;++k){
            dp[i][j][k] = dp[i-1][j][k];
            if(j - A[i-1] > -1) dp[i][j][k] = dp[i][j][k] | dp[i-1][j-A[i-1]][k];
            if(k - A[i-1] > -1) dp[i][j][k] = dp[i][j][k] | dp[i-1][j][k-A[i-1]];
        }
    }
  }
  return dp[A.size()][tar][tar];
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
