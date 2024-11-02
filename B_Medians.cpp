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
    long long n, k;
    cin >> n >> k;
    
    long long mx_x = min(k - 1, n - k);
    bool found = false;
    vector<long long> pos;

    for (long long x = 1; x <= mx_x; x++) {
        long long tmp = k - 1 - x;
        if (tmp < 0) continue;

        long long tv = (tmp % 2 == 0) ? 0 : 1;
        long long mn_p = min(k - 1 - x, n - k - x);
        if (tv > mn_p) continue;

        long long cm = 1 + 2 * x;
        long long l = k - tv - 1;
        long long r = n - k - tv;
        if (l < x || r < x) continue;

        vector<long long> pos_lst;
        long long p = 1;

        for (long long i = 1; i <= x - 1; i++) {
            pos_lst.push_back(p++);
        }

        if (x > 0) {
            pos_lst.push_back(p);
            p += (l - (x - 1));
        }

        pos_lst.push_back(p);
        p += (2 * tv + 1);

        for (long long i = 1; i <= x - 1; i++) {
            pos_lst.push_back(p++);
        }

        if (x > 0) {
            pos_lst.push_back(p);
            p += (r - (x - 1));
        }

        if (p - 1 == n) {
            for (const auto& item : pos_lst) {
                pos.push_back(item);
            }
            found = true;
            break;
        }
    }

    if (found) {
        cout << pos.size() << endl;
        for (size_t i = 0; i < pos.size(); i++) {
            cout << pos[i] << (i < pos.size() - 1 ? " " : "\n");
        }
        return;
    }

    long long t0 = (n - 1) / 2;
    if (t0 == k - 1) {
        cout << "1\n1\n";
        return;
    }

    cout << "-1\n";
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



