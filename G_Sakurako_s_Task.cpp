#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Function to compute GCD of two numbers
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Function to compute GCD of a vector of numbers
int computeGCD(const vector<int>& arr) {
    return accumulate(arr.begin(), arr.end(), arr[0], gcd);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> array(n);
        for (int i = 0; i < n; ++i) {
            cin >> array[i];
        }

        // Compute GCD of the array
        int gcd_value = computeGCD(array);

        // Calculate the maximum possible mex_k
        int max_mex_k = gcd_value * (k - 1);
        cout << max_mex_k << "\n";
    }

    return 0;
}
