#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long countValidPairs(const vector<int>& dq) {
    long long count = 0;
    int n = dq.size();

    // Count valid pairs (i, j) such that dq[i] > 2 * dq[j] and i < j
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (dq[i] > 2 * dq[j]) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int N;
    cin >> N;

    vector<int> Arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> Arr[i];
    }

    int M, K;
    cin >> M >> K;

    // Create the deque
    vector<int> dq;

    // Insert from the rear K times
    for (int i = 0; i < K; ++i) {
        dq.push_back(Arr[i]);
    }

    // Insert from the front M times (in reverse order)
    for (int i = K; i < N; ++i) {
        if (M > 0) {
            dq.insert(dq.begin(), Arr[i]);
            M--;
        }
    }

    // Count the valid pairs
    long long validPairs = countValidPairs(dq);

    cout << validPairs << endl;

    return 0;
}
