#include <bits/stdc++.h>
#define int long long int
using namespace std;

//Madhul_Aggarwal

using ll = long long;
using lld = long double;
using ull = unsigned long long;

const lld pi = 3.141592653589793238;
const ll INF = LONG_LONG_MAX;
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

void solve(){
    int n;
    cin >> n;
    vector<int> p(n+1);
    vector<int> f(n+1, -1);
    string s;
    for(int i = 1; i <= n; i++){
        cin >> p[i];
    }
    cin >> s;

    for(int i = 1; i <= n; i++){
        if(f[i] != -1) continue;

        vector<int> cycle;
        int curr = i;

        while(f[curr] == -1){  
            cycle.push_back(curr);
            f[curr] = 0;  
            curr = p[curr];
        }

        int cnt = 0;
        for(int node : cycle){
            if(s[node - 1] == '0') cnt++;
        }

        for(int node : cycle){
            f[node] = cnt;
        }
    }

    for(int i = 1; i <= n; i++){
        cout << f[i] << " ";
    }
    cout << endl;
}

 
signed main(){
    FAST;
    int testcase;
    cin>>testcase;
    // testcase = 1;
    while(testcase--){
        solve();
    }
}