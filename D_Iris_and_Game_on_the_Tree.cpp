#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX_N = 200005;

// Function to perform BFS and compute path weights
void compute_weights(int root, const vector<vector<int>>& adj, const string& s, vector<int>& leaf_weights) {
    vector<int> visited(MAX_N, 0);
    queue<int> q;
    q.push(root);
    visited[root] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        bool is_leaf = true;
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = 1;
                q.push(v);
                is_leaf = false;
            }
        }

        if (is_leaf) {
            // Compute weight of the leaf
            string path;
            int curr = u;
            while (curr != root) {
                path += s[curr];
                curr = adj[curr][0]; // backtrack to root
            }
            path += s[root];

            int count10 = 0, count01 = 0;
            for (size_t i = 0; i < path.length() - 1; ++i) {
                if (path[i] == '1' && path[i + 1] == '0') ++count10;
                if (path[i] == '0' && path[i + 1] == '1') ++count01;
            }
            leaf_weights.push_back(count10 - count01);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int> > adj(n + 1);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        string s;
        cin >> s;

        vector<int> leaf_weights;
        compute_weights(1, adj, s, leaf_weights);

        int score = 0;
        for (int weight : leaf_weights) {
            if (weight != 0) {
                ++score;
            }
        }

        cout << score << endl;
    }

    return 0;
}
