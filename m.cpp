#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj;
vector<int> vis;

void solve() {
    int n;
    cin >> n;
    adj.resize(n);
    
    // Build the adjacency list
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int N = i + x;  // Server i can send to server N
        int P = i - x;  // Server i can send to server P
        
        if (N < n) {
            adj[i].push_back(N);  // Add edge from i to N
        }
        if (P >= 0) {
            adj[i].push_back(P);  // Add edge from i to P
        }
    }
    
    vis.resize(n, -1);  // Initialize visitation array
    queue<int> Q;
    Q.push(n - 1);  // Start BFS from the master server (index n-1)
    vis[n - 1] = 0;  // Master server takes 0 seconds to send to itself
    
    // BFS to calculate minimum time
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        
        for (int v : adj[u]) {
            if (vis[v] == -1) {  // If server v has not been visited
                Q.push(v);
                vis[v] = vis[u] + 1;  // 1 second to pass the message
            }
        }
    }
    
    // Output the result
    for (int i = 0; i < n; i++) {
        cout << vis[i] << " ";  // Print all times in one line
    }
    cout << endl;  // New line at the end
}

int main() {
    solve();
    return 0;
}