#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define f first
#define s second

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int n, k;
const int N = 2e5 + 69;
vector <int> adj[N];
int dp[N], ops;
int p[N];

void dfs(int u, int h){
    dp[u] = 1;
    for (int v : adj[u]){
        dfs(v, h);
        dp[u] = max(dp[u], dp[v] + 1);
    }
    
    if (dp[u] == h && u != 1 && p[u] != 1){
        dp[u] = 0;
        ops++;
    }
}

void Solve() 
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) adj[i].clear();
    
    for (int i = 2; i <= n; i++){
        int x; cin >> x;
        adj[x].push_back(i);
        p[i] = x;
    }
    
    int l = 1, r = n;
    while (l != r){
        int mid = (l + r) / 2;
        
        ops = 0;
        dfs(1, mid);
        if (ops <= k) r = mid;
        else l = mid + 1;
    }
    
    cout << l << "\n";
}

int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}