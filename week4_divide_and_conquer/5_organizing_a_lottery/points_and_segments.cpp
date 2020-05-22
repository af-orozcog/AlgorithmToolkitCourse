#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[50008];

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<pair<int,int>> see;
  for(int i = 0; i < points.size();++i)
    see.push_back({points[i],i});
  sort(see.begin(),see.end());
  for(int i = 0; i < starts.size();++i){
    pair<int,int> look1 = {starts[i],-1};
    pair<int,int> look2 = {ends[i],1000000};
    int ind1 = lower_bound(see.begin(),see.end(),look1)-see.begin();
    int ind2 = upper_bound(see.begin(),see.end(),look2)-see.begin();
    ++dp[ind1];
    --dp[ind2];
  }
  vector<int> cnt((int)points.size(),0);
  ll acum = 0;
  for(int i = 0; i < points.size();++i){
    acum += dp[i];
    cnt[see[i].second] = (int)acum;
  }
  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
