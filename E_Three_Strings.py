def solve():
    t = int(input())  # Read number of test cases
    for _ in range(t):
        a = input()  # Read string a
        b = input()  # Read string b
        c = input()  # Read string c

        n, m = len(a), len(b)

        # dp[i][j] will be the longest common subsequence of a[0..i-1] and b[0..j-1] that matches c[0..i+j-1]
        dp = [[0] * (m + 1) for _ in range(n + 1)]

        # Fill dp table
        for i in range(n + 1):
            for j in range(m + 1):
                if i + j == 0:
                    continue
                k = i + j - 1  # The index in string c we're currently considering

                # Case 1: If the current character from a matches c[k]
                if i > 0 and a[i - 1] == c[k]:
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1)

                # Case 2: If the current character from b matches c[k]
                if j > 0 and b[j - 1] == c[k]:
                    dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1)

        # The longest matching subsequence has length dp[n][m]
        longest_matching_length = dp[n][m]
        # The minimum number of changes required is the total length minus the longest match
        min_changes = (n + m) - longest_matching_length
        print(min_changes)

