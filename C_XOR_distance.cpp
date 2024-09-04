#include <iostream>
#define int long long
using namespace std;
// Function to find the smallest value of |(a⊕x) - (b⊕x)| for all 0 ≤ x ≤ r
int findSmallestValue(int a, int b, int r) {
    int result = 0;

    // Iterate through all possible values of x from 0 to r
    for (int x = 0; x <= r; ++x) {
        int value = (a ^ x) - (b ^ x);

        // Take absolute value and update result if needed
        value = abs(value);
        if (x == 0 || value < result) {
            result = value;
        }
    }

    return result;
}

signed main() {
    int t;
    cin >> t;
    while(t--){
    int a, b, r;
    cout << "Enter values for a, b, and r: ";
    cin >> a >> b >> r;

    int smallestValue = findSmallestValue(a, b, r);

    cout << smallestValue << endl;
    }
    return 0;
}
