#include <iostream>
#include <vector>
#define min(x,y)(x < y? x:y)

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  while(capacity){
    double ma = 0.0;
    int who = -1;
    for(int i = 0; i < weights.size();++i){
        if((double)values[i]/(double)weights[i] > ma)
            ma = (double)values[i]/(double)weights[i], who = i;
    }
    if(who == -1) break;
    int add = min(capacity,weights[who]);
    value += (double)add*((double)values[who]/(double)weights[who]);
    capacity -= add;
    values[who] = 0;
  }
  // write your code here
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
