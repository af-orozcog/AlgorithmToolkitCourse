#include <iostream>
#include <string>
#define min(x,y)(x < y?x:y)
using std::string;

int edit_distance(const string &str1, const string &str2) {
  int dp[(int)str1.size()+1][(int)str2.size()+1];
  for(int i = 0; i <= str1.size();++i) dp[i][0] = i;

  for(int i = 0; i <= str2.size();++i) dp[0][i] = i;

  for(int i = 1; i <= str1.size();++i){
    for(int j = 1; j <= str2.size();++j){
        dp[i][j] = 100000000;
        dp[i][j] = min(dp[i][j],dp[i-1][j]+1);
        dp[i][j] = min(dp[i][j],dp[i][j-1]+1);
        dp[i][j] = min(dp[i][j],dp[i-1][j-1]+(str1[i-1] != str2[j-1]));
    }
  }
  return dp[(int)str1.size()][(int)str2.size()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
