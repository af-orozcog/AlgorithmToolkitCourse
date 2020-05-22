#include <iostream>
#include<vector>
#define ll long long
using namespace std;
int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
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
    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_naive(n) << "\n";
    n += 2ll;
    ll see = get_fibonacci_huge(n,10ll);
    --see;
    if(see < 0ll) see += 10ll;
    cout << see << "\n";
    return 0;
}
