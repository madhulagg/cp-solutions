#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    int b[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    int cookies = 0;
    while (true) {
        int usedPowder = 0;
        for (int i = 0; i < n; i++) {
            if (b[i] < a[i]) {
                usedPowder = usedPowder + a[i] - b[i];
                if (usedPowder > k) {
                    cout << cookies << endl;
                    return 0;
                }
                b[i] = 0;
            } 
            else {
                b[i] = b[i] - a[i];
            }
        }
        k = k - usedPowder;
        cookies++;
    }
}
