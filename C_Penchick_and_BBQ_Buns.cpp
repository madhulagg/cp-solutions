#include <bits/stdc++.h>
#include <random> // Include this for mt19937 and random utilities
#define int long long int
using namespace std;

#define FAST ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

// Static random number generator and data
static mt19937 gen(time(0));
vector<int> available_numbers;
int current_index = 0;

void initialize_random_numbers(int min, int max) {
    for (int i = min; i <= max; i++) {
        available_numbers.push_back(i);
    }
    shuffle(available_numbers.begin(), available_numbers.end(), gen);
}

int randomnum() {
    if (current_index >= available_numbers.size()) {
        throw runtime_error("No more unique random numbers available!");
    }
    return available_numbers[current_index++];
}

void solvelr(vector<int>& v, vector<int>& a, int l, int r, int t) {
    bool val = true;
    int key;
    for (int i = 0; i < t; i++) {
        if ((t % v[i]) == 0) {
            val = false;
            key = v[i];
        }
    }
    if (val) {
        cout << "-1" << endl;
        return;
    }
    int j;
    for (j = 0; (j + key) < r; j++) {
        int value = randomnum();
        a[j] = value;
        a[j + key] = value;
    }
    solvelr(v, a, j, r - j, t);
}

void solve(vector<int>& v) {
    int t;
    cin >> t;
    vector<int> a(t);
    solvelr(v, a, 0, t, t);
    for (int i = 0; i < t; i++) {
        cout << a[i] + 1 << " ";
    }
    cout << endl;
}

signed main() {
    FAST;
    int testcase;
    cin >> testcase;

    // Initialize the pool of random numbers
    initialize_random_numbers(1, 1e6);

    vector<int> v;
    for (int i = 2; i <= 1e3; i++) {
        v.push_back(i * i);
    }
    while (testcase--) {
        solve(v);
    }
}
