#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n), operations(n, 0);
    
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    // Check if the total sum is divisible by n
    if (sum % n != 0) {
        cout << "-1\n";
        return;
    }

    long long target = sum / n;

    for (int i = 0; i < n; i++) {
        // Calculate the difference from the target
        long long diff = a[i] - target;

        // If the current element is more than target, we need to reduce it
        if (diff > 0) {
            // We will perform `diff / 2` operations
            operations[i] += diff / 2;
            a[i] -= diff;                  // Reduce current index by diff
            a[(i + 1) % n] += diff / 2;    // Increase next index by half of diff
            a[(i - 1 + n) % n] += diff / 2; // Increase previous index by half of diff
        } else if (diff < 0) {
            // If the current element is less than target, we need to increase it
            long long operations_needed = (-diff + 1) / 2; // Round up if odd
            operations[i] -= operations_needed;
            a[i] += -diff;                 // Increase current index by -diff
            a[(i + 1) % n] -= operations_needed; // Decrease next index
            a[(i - 1 + n) % n] -= operations_needed; // Decrease previous index
        }
    }

    // Output the result
    for (int i = 0; i < n; i++) {
        cout << operations[i] << (i == n - 1 ? '\n' : ' ');
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
