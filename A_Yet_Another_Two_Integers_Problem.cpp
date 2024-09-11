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
    int a,b;
    // a -> b
    cin >> a >> b;
    if(a == b){
        cout << "0" << endl;
        return;
    }
    if(a < b){
        int i = 0;
        int ans = (b-a)/10;
        int rem = (b-a)%10;
        if(rem != 0){
            ans++;
        }
        cout << ans << endl;
        return;
    }
    else{
        int i = 0;
        int ans = (a-b)/10;
        int rem = (a-b)%10;
        if(rem != 0){
            ans++;
        }
        cout << ans << endl;
        return;
    }
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