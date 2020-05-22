#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#define min(x,y)(x < y? x:y)

using namespace std;

bool comp(string &a, string &b){
    string comp1 = a + b;
    string comp2 = b + a;
    return comp1 > comp2;
}

string largest_number(vector<string> a) {
  //write your code here
  sort(a.begin(),a.end(),comp);
  string result = "";
  for(auto va: a) result += va;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
