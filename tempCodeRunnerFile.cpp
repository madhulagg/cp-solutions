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

class Solver {
public:
    void solve(int testCases);
    
private:
    int mod = 1e9 + 7;
    vector<long long> pow2;

    bool compare(int a, int b, int c) {
        if (c > 30) return true;
        return a < b * (1LL << c);
    }
};

void Solver::solve(int t) {
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        long long result = 0;
        vector<pair<int, int>> vals;
        pow2.assign(n * 32 + 1, 0);
        pow2[0] = 1;
        for (int i = 1; i <= n * 32; i++) 
            pow2[i] = pow2[i - 1] * 2 % mod;

        for (int i = 0; i < n; i++) {
            int val = arr[i], cnt = 0;
            while (val % 2 == 0) {
                val /= 2;
                cnt++;
            }

            while (!vals.empty() && compare(vals.back().first, val, cnt)) {
                result = (result - vals.back().first * pow2[vals.back().second] % mod + mod) % mod;
                result = (result + vals.back().first) % mod;
                cnt += vals.back().second;
                vals.pop_back();
            }
            
            vals.push_back({val, cnt});
            result = (result + vals.back().first * pow2[vals.back().second]) % mod;
            cout << result << ' ';
        }
        cout << '\n';
    }
}
 
signed main(){
    FAST;
    int testCases;
    cin >> testCases;
    // testCases = 1
    Solver solver;
    solver.solve(testCases);
    return 0;
}