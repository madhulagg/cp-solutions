#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
vector<vector<long long> > dp(N, vector<long long>(N, LLONG_MIN));

long long solve(vector<int> &x, int l, int r) {
    if (l > r) return 0;
    if (dp[l][r] != LLONG_MIN) return dp[l][r];
    long long takeLeft = x[l] - solve(x, l + 1, r);
    long long takeRight = x[r] - solve(x, l, r - 1);
    return dp[l][r] = max(takeLeft, takeRight);
}

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];

    cout << (accumulate(x.begin(), x.end(), 0LL) + solve(x, 0, n - 1)) / 2 << endl;
    return 0;
}
