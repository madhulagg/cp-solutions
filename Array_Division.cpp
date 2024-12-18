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
bool predicatefunc(int n, int k, vector<int> &v){
    int init = 1;
    int curr = 0;
    for(auto it : v){
        if(curr + it <= n){
            curr += it;
        }
        else{
            if(init < k){
                init++;
            }
            else{
                return false;
            }
            curr = it;
        }
    }
    return true;
}
// fffffttttttttttttttttt
void solve(){
    int n;
    int k;
    vector<int> v;
    cin >> n >> k;
    vec_input(v,n);
    int l = *max_element(v.begin(), v.end());
    int r = accumulate(v.begin(), v.end(), 0LL);
    int m;
    int ans = LLONG_MAX;
    while(l <= r){
        m = (l + r)/2;
        if(predicatefunc(m,k,v)){
            ans = min(ans, m);
            r = m - 1;
        }
        else{
            l = m + 1;
        }
    }
    cout << ans;
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