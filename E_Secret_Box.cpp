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
    int x, y, z, k;
    cin >> x >> y >> z >> k;

    int ans = 0;

    for (int a = 1; a * a * a <= k; ++a) {
        if (k % a == 0) {
            int remaining = k / a;
            for (int b = 1; b * b <= remaining; ++b) {
                if (remaining % b == 0) {
                    int c = remaining / b;

                    if (a <= x && b <= y && c <= z) {
                        ans = max(ans, (x - a + 1) * (y - b + 1) * (z - c + 1));
                    }
                    if (a <= x && c <= y && b <= z) {
                        ans = max(ans, (x - a + 1) * (y - c + 1) * (z - b + 1));
                    }
                    if (b <= x && a <= y && c <= z) {
                        ans = max(ans, (x - b + 1) * (y - a + 1) * (z - c + 1));
                    }
                    if (b <= x && c <= y && a <= z) {
                        ans = max(ans, (x - b + 1) * (y - c + 1) * (z - a + 1));
                    }
                    if (c <= x && a <= y && b <= z) {
                        ans = max(ans, (x - c + 1) * (y - a + 1) * (z - b + 1));
                    }
                    if (c <= x && b <= y && a <= z) {
                        ans = max(ans, (x - c + 1) * (y - b + 1) * (z - a + 1));
                    }
                }
            }
        }
    }
    
    cout << ans << endl;
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