#include <iostream>
#include <vector>
#define ll long long
using namespace std;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

ll get_fibonacci_huge(ll n, ll m){
    if(n < 0ll) return 0;
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
    long long from, to;
    std::cin >> from >> to;
    //std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    ++from;
    to += 2;
    ll see1 = get_fibonacci_huge(from,10ll);
    --see1;
    if(see1 < 0ll) see1 += 10ll;
    ll see2 = get_fibonacci_huge(to,10ll);
    --see2;
    if(see2 < 0ll) see2 += 10ll;
    ll ans = see2 - see1;
    if(ans < 0ll) ans += 10ll;
    cout << ans << "\n";
    return 0;
}
