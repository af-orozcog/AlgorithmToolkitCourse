#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}
int fibonacci_fast_last(int n) {
    // write your code here
    if(n <= 1) return n;
    if(n == 2) return 1;
    int last1,last2;
    last1 = last2 = 1;
    for(int i = 3; i <= n;++i){
        int temp = last2;
        last2 += last1;
        last1 = temp;
        if(last2 > 9) last2 -= 10;
    }
    return last2;
}

int main() {
    int n;
    std::cin >> n;
    //int c = get_fibonacci_last_digit_naive(n);
    int c = fibonacci_fast_last(n);
    std::cout << c << '\n';
}
