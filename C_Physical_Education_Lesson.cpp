#include <iostream>
#include <vector>
using namespace std;

// Function to find possible k values
vector<int> findPossibleKs(int position, int number) {
    vector<int> possibleKs;
    // Iterate over possible k values, starting from the highest number that could match the position and number
    for (int k = 2; k <= position; ++k) {
        int cycleLength = 2 * k - 2;
        if (cycleLength < 2) continue; // k must be greater than 1 for a valid cycle
        
        // Calculate position within the cycle
        int posInCycle = (position - 1) % cycleLength;
        int numAtPos;
        
        if (posInCycle < k) {
            numAtPos = posInCycle + 1; // Increasing part of the cycle
        } else {
            numAtPos = k - (posInCycle + 1 - k); // Decreasing part of the cycle
        }

        // Check if the calculated number matches Vasya's number
        if (numAtPos == number) {
            possibleKs.push_back(k);
        }
    }
    return possibleKs;
}

int main() {
    int T, position, number;
    cin >> T; // Read the number of test cases

    while (T--) {
        cin >> position >> number; // Read each position and number pair

        vector<int> possibleKs = findPossibleKs(position, number);
        
        if (possibleKs.empty()) {
            cout << "0"; // Output 0 if no k value fits
        } else {
            cout << possibleKs.size() << " "; // First, output the number of possible k values
            for (int k : possibleKs) {
                cout << k << " "; // Then, output each possible k value
            }
        }
        cout << endl; // New line for each test case
    }

    return 0;
}
