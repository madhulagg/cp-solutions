#include <bits/stdc++.h>
using namespace std;

int calculate_mex(set<int>& friends_values) {
    int mex = 0;
    while (friends_values.count(mex)) ++mex;
    return mex;
}

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> result(n, -1); 
    vector<vector<int> > adj(n); 
    for (int i = 0; i < n; i++) {
        adj[i].push_back((i + 1) % n);
        adj[i].push_back((i - 1 + n) % n);
    }
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1); 
    for (int i = 0; i < n; i++) {
        set<int> friends;
        for (int j = 0; j < adj[i].size(); j++) {
            int n = adj[i][j];
            if (result[n] != -1) {
                friends.insert(result[n]);
            }
        }
        result[i] = calculate_mex(friends);
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
