#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    stops.insert(stops.begin(),0);
    stops.push_back(dist);
    // write your code here
    int i = 0,ans = 0;
    while(i < (int)stops.size()-1){
        int last = i;
        while(i < stops.size() && stops[i] - stops[last] <= tank) ++i;
        --i;
        if(last == i) return -1;
        if(i != (int)stops.size()-1)
            ++ans;
    }
    return ans;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
