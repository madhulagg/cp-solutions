#include <iostream>
#include <vector>

using namespace std;

vector<int> findRemainingMonsters(vector<int>& energy, int n) {
    vector<int> diff(n);  // Stores differences between consecutive monsters' energy

    // Calculate initial differences efficiently using circular indexing
    for (int i = 0; i < n; i++) {
        diff[i] = (energy[(i + 1) % n] - energy[i] + 2e9) % 2e9;  // Handle negative differences
    }

    // Simulate the spell's effect for 100 cycles (or less if divisible by n)
    for (int cycle = 0; cycle < min(100, 100 - (100 % n)); cycle++) {
        vector<int> newDiff(n);
        for (int i = 0; i < n; i++) {
            newDiff[i] = max(0, diff[(i + n - 1) % n] - diff[i]);
        }
        diff = newDiff;
    }

    vector<int> remaining;
    // Find monsters with remaining energy after simulations
    for (int i = 0; i < n; i++) {
        if (diff[i] > 0 || (diff[i] == 0 && energy[i] > 0)) {
            remaining.push_back(i + 1);  // Store indices (1-based)
        }
    }

    return remaining;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> energy(n);
        for (int i = 0; i < n; i++) {
            cin >> energy[i];
        }

        vector<int> remaining = findRemainingMonsters(energy, n);

        cout << remaining.size() << endl;
        for (int i : remaining) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
