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

template <typename T>
void vec_input(vector<T>& v, int length, bool one_indexed = false) {
    T temp;
    if (one_indexed) {
        v.emplace_back(0);
    }
    fl(i, 0 + one_indexed, length + one_indexed) {
        cin >> temp;
        v.emplace_back(temp);
    }
}

bool valid(int time, int k, const vector<int>& machines) {
    int totalProducts = 0;
    for (int productionTime : machines) {
        totalProducts += time / productionTime;
        if (totalProducts >= k) return true;
    }
    return totalProducts >= k;
}
// ffffttt
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> machines(n);
    for (int i = 0; i < n; i++) cin >> machines[i];

    int l = 1, r = *min_element(machines.begin(), machines.end()) * k;
    int ans = -1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (valid(mid, k, machines)) {
            ans = mid;
            r = mid - 1; 
        } else {
            l = mid + 1; 
        }
    }

    cout << ans << "\n";
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