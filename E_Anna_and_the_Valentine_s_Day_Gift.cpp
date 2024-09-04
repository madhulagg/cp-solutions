#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool annaWins(const vector<int>& numbers, int m) {
    int oddCount = 0;
    for (int number : numbers) {
        if (number % 2 != 0) oddCount++;
    }
    return (oddCount == 0) || (m == 0);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> numbers(n);
        for (int i = 0; i < n; ++i) {
            cin >> numbers[i];
        }
        if (annaWins(numbers, m)) {
            cout << "Anna\n";
        } else {
            cout << "Sasha\n";
        }
    }
    return 0;
}
