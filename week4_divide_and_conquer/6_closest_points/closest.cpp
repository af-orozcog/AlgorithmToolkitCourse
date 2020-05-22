#include <bits/stdc++.h>
#define ld long double
#define EPS 1e-9
using namespace std;


double dist(double x1, double y1, double x2, double y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

double minimal_distance(vector<pair<int,int>> &coorX,vector<pair<int,int>> &coorY, int l, int r){
  if(l >= r)
    return (double)100000000000000;
  else if(l+1 == r)
    return dist((double)coorX[l].first,(double)coorX[l].second,(double)coorX[r].first,(double)coorX[r].second);
  int mid = (l+r)>>1;
  vector<pair<int,int>> imp1;
  vector<pair<int,int>> imp2;
  pair<int,int> see = coorX[mid];
  for(int i = 0; i < coorY.size();++i){
    if(coorY[i].first < coorX[mid].first || (coorY[i].second == coorX[mid].second && coorY[i].second < coorX[mid].second))
        imp1.push_back(coorY[i]);
    else imp2.push_back(coorY[i]);
  }
  double ans = (double)100000000000000;
  double val1 = minimal_distance(coorX,imp1,l,mid-1);
  double val2 = minimal_distance(coorX,imp2,mid,r);
  vector<pair<int,int>> comp;
  ans = min(val1,val2);
  for(int i = (int)coorY.size()-1; i > -1;--i)
    if((double)coorX[mid].first + ans - (double)coorY[i].first >= EPS && (double)coorX[mid].first - ans -(double)coorY[i].first <= EPS)
        comp.push_back(coorY[i]);
  for(int i = 0; i < comp.size();++i){
    for(int j = i+1; j - i <= 7 && j < comp.size();++j){
        ans = min(ans,dist((double)comp[i].first,(double)comp[i].second,(double)comp[j].first,(double)comp[j].second));
       // if(dist((double)comp[i].first,(double)comp[i].second,(double)comp[j].first,(double)comp[j].second) == 0.0)
         //   cout << comp[i].first <<  " " << comp[i].second <<  " " << comp[j].first << " " << comp[j].second << "\n";
    }
  }
  return ans;
}

bool comp1(pair<int,int> &a, pair<int,int> &b){
    return a.second < b.second;
}

bool comp2(pair<int,int> &a, pair<int,int> &b){
    return a.first < b.first;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<pair<int,int>> coorX(n);
  vector<pair<int,int>> coorY(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> coorX[i].first >> coorX[i].second;
    coorY[i] = coorX[i];
  }
    sort(coorY.begin(),coorY.end(),comp1);
    sort(coorX.begin(),coorX.end(),comp2);

  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(coorX,coorY,0,n-1) << "\n";
}
