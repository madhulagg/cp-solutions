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

int func(int n, int a, int b, int c, vector<int> &dp){
    if (n < 0)
        return -INT_MAX;
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = (1 + max({func(n-a,a,b,c, dp), func(n-b,a,b,c, dp), func(n-c,a,b,c, dp)} ));
      return dp[n];
}

void solve(){
    int n,a,b,c;
    cin >> n >> a >> b >> c;
    vector<int> dp(n+1, -1);
    cout << func(n,a,b,c,dp);
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