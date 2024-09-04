#include <bits/stdc++.h>
using namespace std;
// A->cost of fuel per unit
// B->required fuel on each day

int solve(int n, vector<int> a, vector<int> b) {
    int min_cost = 0;
    int min_price = a[0];
    
    for (int i = 0; i < n; i++) {
        min_price = min(min_price, a[i]);
        min_cost += min_price * b[i];
    }
    
    return min_cost;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    cout << solve(n, a, b) << endl;
    return 0;
}
