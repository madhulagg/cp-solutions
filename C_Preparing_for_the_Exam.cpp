#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        
        // List of missing questions for each list
        vector<int> a(m);
        for (int i = 0; i < m; i++) {
            cin >> a[i];
        }

        // Set of known questions (monocarp knows these)
        unordered_set<int> known_questions;
        for (int i = 0; i < k; i++) {
            int q;
            cin >> q;
            known_questions.insert(q);
        }

        // Result for each test case
        string result;

        // Process each list
        for (int i = 0; i < m; i++) {
            int missing_question = a[i];  // The question that is missing in this list
            
            // If Monocarp knows the missing question, he cannot pass
            if (known_questions.find(missing_question) != known_questions.end()) {
                result += "0";
            } else {
                result += "1";
            }
        }

        // Output the result for the current test case
        cout << result << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Call the function to solve the problem
    solve();
    
    return 0;
}
