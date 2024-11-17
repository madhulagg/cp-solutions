#include <iostream>
#include <vector>
#include <cmath>

const int MOD = 998244353;

// Function to compute gcd
long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    
    // Reading attractiveness values
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    // DP array to store number of distinct paths to each city
    std::vector<long long> dp(n + 1, 0);
    dp[1] = 1;  // There's exactly one way to reach city 1, starting there
    
    // Use a sieve-like approach to count paths based on gcd conditions
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            if (gcd(a[j - 1], a[i - 1]) != 1) {  // cities i and j are connected
                dp[i] = (dp[i] + dp[j]) % MOD;
            }
        }
    }

    // Output the result which is the number of paths to city n
    std::cout << dp[n] << std::endl;

    return 0;
}
