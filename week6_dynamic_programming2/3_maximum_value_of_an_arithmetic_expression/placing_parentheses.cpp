#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#define ll long long

using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}
ll dpM[29][29], dpm[29][29];

long long get_maximum_value(const string &exp) {
  //write your code here
  vector<int> nums;
  vector<char> op;
  for(int i = 0; i < exp.size();++i){
    if((i & 1) == 0) nums.push_back(exp[i]-'0');
    else op.push_back(exp[i]);
  }
  for(int i = 0; i < nums.size();++i){
    for(int j = 0; j < nums.size();++j){
        if(i == j) dpM[i][j] = dpm[i][j] = nums[i];
        else dpM[i][j] = -100000000000000ll, dpm[i][j] = 1000000000000ll;
    }
  }
  for(int i = 1; i < nums.size();++i){
    for(int j = 0; j < nums.size();++j){
        int to = j + i;
        if(to >= (int)nums.size())break;
        for(int k = j; k < to;++k){
            ll va1 = eval(dpM[j][k],dpM[k+1][to],op[k]);
            ll va2 = eval(dpM[j][k],dpm[k+1][to],op[k]);
            ll va3 = eval(dpm[j][k],dpM[k+1][to],op[k]);
            ll va4 = eval(dpm[j][k],dpm[k+1][to],op[k]);
            dpM[j][to] = max(dpM[j][to],max(va1,max(va2,max(va3,va4))));
            dpm[j][to] = min(dpm[j][to],min(va1,min(va2,min(va3,va4))));
        }
      //  std::cout <<j << " " << to << " " << dpM[j][to] << "\n";
    //std::cout <<j << " " << to << " " << dpm[j][to] << "\n";
    }
  }
  return dpM[0][(int)nums.size()-1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
