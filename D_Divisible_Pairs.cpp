#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        unordered_map<int, int> modX, modY;
        long long beautifulPairs = 0;

        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            int remX = num % x, remY = num % y;

            // For each number, calculate how many previous numbers it can form a beautiful pair with,
            // based on the remainder when divided by x and y.
            if (modX.find((x - remX) % x) != modX.end() && modY.find((y - remY) % y) != modY.end()) {
                beautifulPairs += min(modX[(x - remX) % x], modY[(y - remY) % y]);
            }

            // Update the count of numbers with this remainder.
            modX[remX]++;
            modY[remY]++;
        }

        cout << beautifulPairs << endl;
    }
    return 0;
}
