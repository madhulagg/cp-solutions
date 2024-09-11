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
// n * logn
void solve(){
    int n;
    cin >> n;
    int arr[n];
    unordered_map<int,bool> mpp;
    fl(i, 0, n){
        cin >> arr[i];
        mpp[arr[i]] = true;
    }
    vector<int> ans;
    for(auto it : mpp){
        if(it.second == true){
            it.second = false;
            ans.push_back(it.first);
        }
    }
    sort(ans.begin(), ans.end());
    int cnt = 0;
    for(int i = 1; i < ans.size(); i++){
        if(ans[i] - ans[i-1] == 1){
            cnt++;
        }
    }
    if(cnt == ans.size() - 1) cout << "YES" << endl;
    else cout << "NO" << endl; 

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