#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int i = 1, j = 1;
  while(j <= n){
    summands.push_back(i);
    ++i;
    j += i;
  }
  if(summands.size()){
    int left = n - (j - i);
    summands[summands.size()-1]+= left;
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
