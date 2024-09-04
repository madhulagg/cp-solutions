#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canMakeCookies(const vector<int>& a, const vector<int>& b, int k, int n, int mid) {
    long long powderNeeded = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] * mid > b[i]) {
            powderNeeded += (long long)(a[i] * mid - b[i]);
        }
        if (powderNeeded > k) return false;
    }
    return true;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    int low = 0, high = 2000000000, maxCookies = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canMakeCookies(a, b, k, n, mid)) {
            maxCookies = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << maxCookies << endl;
    return 0;
}
