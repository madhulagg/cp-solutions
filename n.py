MOD = 1000000007

# Function to determine if a number is prime
def is_prime(num):
    if num < 2:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

def specialNumber(T, test_cases):
    results = []
    
    for case in test_cases:
        N, M, K = case
        prime_digits = [2, 3, 5, 7]
        non_prime_digits = [0, 1, 4, 6, 8, 9]
        
        # Prepare a list of prime indices and non-prime indices
        prime_indices = [i for i in range(1, N + 1) if is_prime(i)]
        non_prime_indices = [i for i in range(1, N + 1) if not is_prime(i)]

        # DP table: dp[i][r] -> number of ways to form a number of length i with remainder r
        dp = [[0] * M for _ in range(N + 1)]
        
        # Initial condition: no digits, remainder is 0
        dp[0][0] = 1
        
        # Fill the DP table
        for i in range(1, N + 1):
            if i in prime_indices:
                digits = prime_digits
            else:
                digits = non_prime_digits
            
            for digit in digits:
                for remainder in range(M):
                    new_remainder = (remainder * 10 + digit) % M
                    dp[i][new_remainder] = (dp[i][new_remainder] + dp[i - 1][remainder]) % MOD
        
        # The answer is dp[N][K] - the number of N-digit numbers that leave remainder K when divided by M
        results.append(dp[N][K])
    
    # Print all results
    for result in results:
        print(result)

# Example Usage
T = 1
test_cases = [(2, 2, 0)]  # For N = 2, M = 2, K = 0
specialNumber(T, test_cases)
