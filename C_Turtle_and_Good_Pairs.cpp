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
    
    string s;
    cin >> s;
    
    unordered_map<char, int> mp;
    vector<char> ch_arr;
    string res = "";
    
    for (int i = 0; i < n; i++) {
        mp[s[i]]++;
    }
    
    for (int i = 0; i < n; i++) {
        if (mp[s[i]] == 1) {
            ch_arr.push_back(s[i]);
        } else {
            res += s[i];
        }
    }
    
    string ans = "";
    int i = 0;
    
    while (i < max(ch_arr.size(), res.size())) {
        if (i < res.size()) {
            ans += res[i];
        }
        if (i < ch_arr.size()) {
            ans += ch_arr[i];
        }
        i++;
    }
    
    cout << ans << '\n';
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