#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int t;
    cin >> t;  // Read number of test cases
    while (t--) {
        string a, b, c;
        cin >> a >> b >> c;  // Read the strings a, b, c

        int n = a.length(), m = b.length();

        // dp[i][j] will store the length of the longest valid subsequence
        // using the first i characters of a and the first j characters of b
        vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));

        // Fill dp table
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                int k = i + j - 1;  // the index in string c we're considering

                if (i + j == 0) continue;

                // Case 1: If the current character from a matches c[k]
                if (i > 0 && a[i - 1] == c[k]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
                }

                // Case 2: If the current character from b matches c[k]
                if (j > 0 && b[j - 1] == c[k]) {
                    dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
                }
            }
        }
        int longest_matching_length = dp[n][m];
        int min_changes = (n + m) - longest_matching_length;
        cout << min_changes << endl;
    }
}

int main() {
    solve();
    return 0;
}
