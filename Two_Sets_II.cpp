#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int sum = n * (n + 1) / 2;
    if (sum % 2 == 1) {
        cout << 0;
        return;
    }

    int target = sum / 2;
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = target; j >= i; j--) {
            dp[j] += (double)(dp[j - i]%(double)(1e9 + 7));
        }
    }

    cout << dp[target] / 2;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
