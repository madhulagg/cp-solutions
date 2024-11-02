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

string target = "1543";

void solve(){
        int n, m;
        cin >> n >> m;
        
        vector<string> c(n);
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
        }

        vector<string> l;
        int sr = 0, er = n - 1, sc = 0, ec = m - 1;

        while (sr <= er && sc <= ec) {
            string cl;

            for (int j = sc; j <= ec; ++j) cl += c[sr][j];
            for (int i = sr + 1; i < er; ++i) cl += c[i][ec];
            if (sr < er) for (int j = ec; j >= sc; --j) cl += c[er][j];
            if (sc < ec) for (int i = er - 1; i > sr; --i) cl += c[i][sc];

            l.push_back(cl);
            ++sr; --er; ++sc; --ec;
        }

        int total = 0;
        for (const auto& layer : l) {
            string ext_layer = layer + layer.substr(0, target.size() - 1);
            for (int i = 0; i <= ext_layer.size() - target.size(); ++i) {
                if (ext_layer.substr(i, target.size()) == target) {
                    ++total;
                }
            }
        }
        
        cout << total << endl;
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