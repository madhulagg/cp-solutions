#include <bits/stdc++.h>
#define int long long int
using namespace std;

//Madhul_Aggarwal

using ll = long long;
using lld = long double;
using ull = unsigned long long;

const lld pi = 3.141592653589793238;
const ll INF = LLONG_MAX;
const ll mod = 1e9 + 7;

typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef unordered_map<ll, ll> umll;
typedef map<ll, ll> mll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define fl(i, m, n) for (int i = m; i < n; i++)
#define rl(i, m, n) for (int i = m; i >= n; i--)
#define py cout << "YES\n";
#define pm cout << "-1\n";
#define pn cout << "NO\n";
#define vr(v) v.begin(), v.end()
#define rv(v) v.end(), v.begin()
#define FAST ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

template <typename T>
void vec_input(vector<T>& v, int length, bool one_indexed = false) {
    T temp;
    if (one_indexed) {
        v.emplace_back(0);
    }
    fl(i, 0 + one_indexed, length + one_indexed) {
        cin >> temp;
        v.emplace_back(temp);
    }
}

bool dfs(int node, int par, vector<vector<int>> &adj, vector<int> &vis, vector<int> &parent, int &start, int &endd) {
    vis[node] = 1;
    for (int neigh : adj[node]) {
        if (neigh == par) continue;
        if (vis[neigh]) {
            start = neigh;
            endd = node;
            return true;
        }
        parent[neigh] = node;
        if (dfs(neigh, node, adj, vis, parent, start, endd)) return true;
    }
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<int> vis(n+1, 0), parent(n+1, -1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int start = -1, endd = -1;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(i, -1, adj, vis, parent, start, endd)) break;
        }
    }
    if (start == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> path;
        path.push_back(start);
        for (int v = endd; v != start; v = parent[v]) {
            path.push_back(v);
        }
        path.push_back(start);
        reverse(path.begin(), path.end());
        cout << path.size() << '\n';
        for (int v : path) cout << v << ' ';
        cout << '\n';
    }
}


 
signed main(){
    FAST;
    int testcase;
    // cin>>testcase;
    testcase = 1;
    while(testcase--){
        solve();
    }
}