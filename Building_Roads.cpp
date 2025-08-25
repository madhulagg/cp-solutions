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

void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    fl(i,0,m){
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<int> visited(n+1,0);
    vector<int> ans;
    function<void(int)> dfs = [&](int node){
        visited[node] = 1;
        for(auto i : adj[node]){
            if(visited[i] == 0){
                dfs(i);
            }
        }
    };
    fl(i,1,n+1){
        if(visited[i] == 0){
            ans.pb(i);
            dfs(i);
        }
    }
    cout << ans.size()-1 << endl;
    fl(i,1,ans.size()){
        cout << ans[i-1] << " " << ans[i] << endl;
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