#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
    //vector<int> see = a;
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  int m = (left+right)>>1;
  int val1 = get_majority_element(a,left,m);
  int val2 = get_majority_element(a,m,right);
  int co1 = 0;
  int co2 = 0;
  for(int i = left; i < right;++i){
    if(a[i] == val1) ++co1;
    if(a[i] == val2) ++co2;
  }
  if(co1 > co2 && (co1<<1) > (right-left))
    return val1;
  else if((co2<<1) > (right-left))
    return val2;
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, (int)a.size()) != -1) << '\n';
}
