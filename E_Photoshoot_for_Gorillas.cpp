#include <bits/stdc++.h>
#define int long long
using namespace std;

// Madhul_Aggarwal

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

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> cnt;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) { 
            int x = max(i - k + 1, 0LL); 
            int y = max(j - k + 1, 0LL);
            int u = min(i + 1, n - k + 1);
            int v = min(j + 1, m - k + 1);
            cnt.push_back((u - x) * (v - y));
        }
    }

    sort(cnt.begin(), cnt.end(), greater<int>());

    int w;
    cin >> w;
    vector<long long> a(w);
    for (int i = 0; i < w; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<long long>());
    
    long long ans = 0;
    for (int i = 0; i < w; i++) {
        ans += a[i] * cnt[i];
    }
    
    cout << ans << endl;
}
 
signed main(){
    FAST;
    int testcase;
    // testcase = 1;
    cin >> testcase;
    while (testcase--) {
        solve();
    }
    return 0;
}
