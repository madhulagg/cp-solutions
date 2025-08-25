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
void bfs_solve(){
    int n,m;
    cin >> n >> m;//nodes, edges
    vector<vector<int>> edg(n);
    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        a--; // 0-based
        b--; // 0-based
        edg[a].push_back(b);
        edg[b].push_back(a);
    }
    queue<int> q;
    vector<bool>vis(n);
    int src = 0; 
    q.push(src);
    vis[src] = true;
    while(!q.empty()){
        int qq = q.front();
        q.pop();
        cout << qq << " ";
        for(auto it : edg[qq]){
            if(vis[it] == false){
                q.push(it);
                vis[it] = true;
            }
        }
    }
}
// O(n+m)
void dfs(int currNode, vector<vector<int>> &edg, vector<int> &traversal, vector<bool> &vis){
    traversal.push_back(currNode);
    vis[currNode] = true;
    for(auto adj : edg[currNode]){
        if(!vis[adj]){
            dfs(adj, edg, traversal, vis);
    
        }
    }
}

void solve(){
    int n, m; // nodes, edges
    cin >> n >> m;
    vector<vector<int>> edg(n);
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        a--; // 0-based
        b--; // 0-based
        edg[a].push_back(b);
        edg[b].push_back(a);
    }
    vector<int> traversal;
    int source = 0;
    vector<bool> vis(n, false);
    dfs(source, edg, traversal, vis);
    for(auto it : traversal){
        cout << it << " ";
    }
}

 
signed main(){
    FAST;
    // int testcase;
    // cin>>testcase;
    // // testcase = 1;
    // while(testcase--){
    solve();
    // }
}