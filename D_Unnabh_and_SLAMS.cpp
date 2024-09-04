#include <iostream>
#include <vector>
#include <string>
using namespace std;

int calculateScore(const vector<string>& target) {
    int score = 0;
    int ringValues[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (target[i][j] == 'X') {
                int distanceFromCenter = max(abs(i - 4), abs(j - 4));
                int ring = min(distanceFromCenter, 4);
                score += ringValues[ring];
            }
        }
    }

    return score;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        vector<string> target(10);
        for (int i = 0; i < 10; ++i) {
            cin >> target[i];
        }
        
        cout << calculateScore(target) << endl;
    }

    return 0;
}
