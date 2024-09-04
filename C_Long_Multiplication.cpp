#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string x, y;
        cin >> x >> y;

        long long maxProduct = 0;
        string maxX, maxY;

        for (char d = '0'; d <= '9'; ++d) {
            string tempX = x + d;
            long long product = stoll(tempX) * stoll(y);
            if (product > maxProduct) {
                maxProduct = product;
                maxX = tempX;
                maxY = y;
            }
        }

        cout << maxX << endl;
        cout << maxY << endl;
    }

    return 0;
}
