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
    int n, m;
    cin >> n >> m;
        
    vector<int> a(n);
    int max_value = 0;
        
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > max_value) {
            max_value = a[i];
        }
    }
        
        vector<int> result;
        
        while (m--) {
            char c;
            int l, r;
            cin >> c >> l >> r;
            
            if (l <= max_value && max_value <= r) {
                if (c == '+') {
                    max_value += 1;
                } else if (c == '-') {
                    max_value -= 1;
                }
            }
            
            result.push_back(max_value);
        }
        
        for (int value : result) {
            cout << value << " ";
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