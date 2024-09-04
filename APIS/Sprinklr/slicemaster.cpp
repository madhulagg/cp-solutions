#include<bits/stdc++.h>
using namespace std;

int solve(string S) {
    unordered_map<char, int> last_occurrence;
    
    for (int i = 0; i < S.length(); i++) {
        last_occurrence[S[i]] = i;
    }

    int points = 0;
    int start = 0, end = 0;

    for (int i = 0; i < S.length(); i++) {
        end = max(end, last_occurrence[S[i]]);
        
        if (i == end) {
            points += pow((end - start + 1), 2);
            start = i + 1;
        }
    }

    return points;
}

int main() {
    string S;
    cin >> S;
    
    cout << solve(S) << endl;
    return 0;
}

