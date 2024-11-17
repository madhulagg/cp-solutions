import math
MOD = 998244353
def solve(n, a):
    dp = [0] * (n + 1)
    dp[1] = 1
    for i in range(2, n + 1):
        for j in range(1, i):
            if math.gcd(a[i - 1], a[j - 1]) != 1:
                dp[i] = (dp[i] + dp[j]) % MOD
    return dp[n]
n = int(input())
a = list(map(int, input().split()))  

print(solve(n, a))
