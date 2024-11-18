#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        unordered_map<int, int> freq;

        // Read input and count frequencies
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }

        vector<int> candidates;
        for (auto &[key, value] : freq) {
            if (value >= 2) {
                candidates.push_back(key);
            }
        }

        // If less than two candidates, impossible to form a rectangle
        if (candidates.size() < 2) {
            cout << "NO\n";
            continue;
        }

        // Sort candidates
        sort(candidates.begin(), candidates.end());

        // Track best rectangle with the smallest ratio
        double best_ratio = 1e9;
        pair<int, int> best_pair;

        // Check all pairs of candidates
        for (size_t i = 0; i < candidates.size() - 1; i++) {
            int x1 = candidates[i];
            int x2 = candidates[i + 1];

            if (freq[x1] >= 4) {
                best_pair = {x1, x1};
                break;
            }
            if (freq[x2] >= 4) {
                best_pair = {x2, x2};
                break;
            }

            if (freq[x1] >= 2 && freq[x2] >= 2) {
                double side1 = abs(x1 - x2);
                double side2 = 1; // Minimal side for ratio calculation
                double ratio = side1 / side2;

                if (ratio < best_ratio) {
                    best_ratio = ratio;
                    best_pair = {x1, x2};
                }
            }
        }

        // Output results
        if (best_pair.first == 0 && best_pair.second == 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            int x1 = best_pair.first, x2 = best_pair.second;
            cout << x1 << " " << x1 << " " << x2 << " " << x1 << " " << x2 << " " << x2 << " " << x1 << " " << x2 << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
