#include <iostream>
#define ll long long
#include <vector>

using namespace std;

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  //write your code here
  return number_of_inversions;
}

ll ans = 0;

ll merge_p(vector<int> &a,int l, int m, int r){
    ll send = 0;
    vector<int> yup;
    for(int i = l; i <= r;++i)
        yup.push_back(a[i]);

    int i = 0,j = m-l;
    int ind = 0;
    while(i < m-l || j <= r-l){
        if(i == m-l)
            a[l+ind] = yup[j++];
        else if(j > r-l)
            a[l+ind] = yup[i++];
        else{
            if(yup[i] > yup[j]){
                send += ((ll)(m-l-i));
                a[l+ind] = yup[j++];
            }
            else
                a[l+ind] = yup[i++];
        }
        ++ind;
    }
    return send;
}

void merge_sort(vector<int> &a, int l, int r){
    vector<int> see = a;
    if(l >= r)
        return;
    if(l+1 == r){
        if(a[l] > a[r]) ++ans,swap(a[l],a[r]);
        return;
    }
    int mid = (l+r)>>1;
    merge_sort(a,l,mid-1);
    see = a;
    merge_sort(a,mid,r);
    see = a;
    ll add = merge_p(a,l,mid,r);
    ans += add;
}


int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  merge_sort(a,0, (int)a.size()-1);
  std::cout << ans << '\n';
  return 0;
}
