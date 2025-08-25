#include <iostream>

using namespace std;

int digitSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        bool found = false;
        for (int n = 1; n <= 100000; ++n) {
            if (digitSum(n) == x && digitSum(n + 1) == y) {
                found = true;
                break;
            }
        }
        cout << (found ? "YES\n" : "NO\n");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
