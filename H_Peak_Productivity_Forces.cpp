#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    // Create a mapping from value to index for permutation a
    unordered_map<int, int> pos_a;
    for (int i = 0; i < n; i++) {
        pos_a[a[i]] = i;
    }

    vector<int> operations;

    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            if (pos_a.find(b[i]) == pos_a.end()) {
                cout << -1 << endl;
                return;
            }

            int index = pos_a[b[i]];
            // Bring the required element to the front
            if (index > 0) {
                // Perform shifts to move b[i] to the front
                while (index > 0) {
                    operations.push_back(index + 1); // Store 1-based index
                    int temp = a[index];
                    for (int j = index; j > 0; j--) {
                        a[j] = a[j - 1];
                    }
                    a[0] = temp;
                    
                    // Update positions in the map
                    pos_a[temp] = 0;
                    for (int j = 1; j <= index; j++) {
                        pos_a[a[j]] = j;
                    }
                    index--;
                }
            }
            // Now that b[i] is at the front, we need to shift it to the correct place
            // Shift the remaining elements in the segment
            if (i > 0) {
                operations.push_back(1); // To move the front to back
                int temp = a[0];
                for (int j = 0; j < n - 1; j++) {
                    a[j] = a[j + 1];
                }
                a[n - 1] = temp;
            }
        }
    }

    // Final adjustment if needed
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            operations.push_back(1);
            int temp = a[0];
            for (int j = 0; j < n - 1; j++) {
                a[j] = a[j + 1];
            }
            a[n - 1] = temp;
        }
    }

    cout << operations.size() << endl;
    for (int op : operations) {
        cout << op << " ";
    }
    cout << endl;
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
