#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int year = stoi(s);
        int root = sqrt(year);
        if (root * root != year) {
            cout << -1 << '\n';

            continue;
        }
        for(int i = 0; i < s.size(); ++i) {
            if (s[i] != '0') {
                s[i] = '0';
                break;
            }
        }
        year = stoi(s);
        root = sqrt(year);
        if (root * root != year) {
            cout << -1 << '\n';
            continue;
        }
        bool found = false;
        for (int a = 0; a <= root; ++a) {
            int b = root - a;
            if (a >= 0 && b >= 0) {
                cout << a << " " << b << '\n';
                found = true;
                break;
            }
        }
        if (!found) cout << -1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
