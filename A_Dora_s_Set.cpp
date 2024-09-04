#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate GCD of two numbers
int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to check if three numbers are co-prime pairwise
bool isCoPrimeTriplet(int a, int b, int c) {
    return gcd(a, b) == 1 && gcd(b, c) == 1 && gcd(a, c) == 1;
}

// Function to find the maximum number of operations
int maxOperations(int l, int r) {
    vector<int> candidates;
    // Collect all integers in range [l, r]
    for (int i = l; i <= r; ++i) {
        candidates.push_back(i);
    }

    int operations = 0;
    size_t n = candidates.size();
    
    // Check all triplets
    vector<bool> used(n, false);
    for (size_t i = 0; i < n - 2; ++i) {
        if (used[i]) continue;
        for (size_t j = i + 1; j < n - 1; ++j) {
            if (used[j]) continue;
            for (size_t k = j + 1; k < n; ++k) {
                if (used[k]) continue;
                if (isCoPrimeTriplet(candidates[i], candidates[j], candidates[k])) {
                    // Mark these indices as used
                    used[i] = used[j] = used[k] = true;
                    ++operations;
                    break;
                }
            }
        }
    }
    
    return operations;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        cout << maxOperations(l, r) << endl;
    }
    return 0;
}
