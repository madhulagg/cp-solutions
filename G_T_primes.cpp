#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 5; 

vector<bool> checkprime() {
    vector<bool> prime(MAX, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < MAX; i++) {
        if (prime[i]) {
            for (int j = i * i; j < MAX; j += i)
                prime[j] = false;
        }
    }
    return prime;
}

int main() {
    vector<bool> prime = checkprime();
    int t;
    cin >> t;
    while (t--) {
        long long x;
        cin >> x;
        long long sq = sqrt(x);
        if (sq * sq == x && prime[sq]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
