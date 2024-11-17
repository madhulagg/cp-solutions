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

bool isComp(int x) {
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) return true;
    }
    return false;
}

void solve() {
    int n;
    cin >> n;

    if (n == 3) {
        cout << -1 << endl;
        return;
    }

    vector<int> odd, even;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) odd.push_back(i);
        else even.push_back(i);
    }
    int ii;
    int jj;
    bool found = false;
    for (int i = 0; i < odd.size(); i++) {
        for (int j = 0; j < even.size(); j++) {
            if (isComp(odd[i] + even[j])) {
                ii = i;
                jj = j;
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (!found) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < odd.size() ; i++) {
            if(i!=ii) cout << odd[i] << " ";
        }
        cout << odd[ii] << " " << even[jj]<< " ";
        for (int i = 0; i < even.size(); i++){ 
            if(i != jj) cout << even[i] << " ";
        }
        cout << endl;
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