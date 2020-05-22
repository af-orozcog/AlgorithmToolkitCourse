#include <iostream>
#include<vector>
#define ll long long
using namespace std;

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

ll get_fibonacci_huge(ll n, ll m){
    if(n <= 1ll) return n;
    if(n == 2ll) return 1;
    vector<int> dp;
    dp.push_back(0);dp.push_back(1);dp.push_back(1);
    for(int i = 3; 1;++i){
        if(i > 3 && dp[i-1] == 1 && dp[i-2] == 1 && dp[i-3] == 0) break;
        ll temp = dp.back();
        temp += dp[i-2];
        if(temp >= m) temp = temp % m;
        dp.push_back(temp);
    }
    dp.pop_back();dp.pop_back();dp.pop_back();
    n = n % (ll)dp.size();
    return dp[n];
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    cout << get_fibonacci_huge(n,m) << "\n";
    return 0;
}
