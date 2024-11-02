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

void solve() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<vector<int>> a(k + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            int t;
            cin >> t;
            t |= a[j][i - 1];
            a[j][i] = t;
        }
    }

    while (q--) {
        int m;
        cin >> m;

        vector<pair<int, int>> lt, gt;

        while (m--) {
            int r, c;
            char op;
            cin >> r >> op >> c;

            if (op == '<') {
                lt.emplace_back(r, c);
            } else {
                gt.emplace_back(r, c);
            }
        }

        int best = 1;

        for (const auto& cond : gt) {
            int r = cond.first, c = cond.second;
            int pos = 1;

            while (pos <= n && a[r][pos] <= c) {
                pos++;
            }
            best = max(best, pos);
        }

        if (best > n) {
            cout << "-1\n";
            continue;
        }

        bool valid = true;

        for (const auto& cond : lt) {
            int r = cond.first, c = cond.second;
            if (a[r][best] >= c) {
                valid = false;
                break;
            }
        }

        if (valid) {
            cout << best << '\n';
        } else {
            cout << "-1\n";
        }
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