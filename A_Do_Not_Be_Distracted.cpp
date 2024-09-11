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
    int n;
    cin >> n;
    vector<int> check(26, 0);
    string s;
    cin >> s;
    for(int i = 0; i < n-1; i++){
        check[s[i] - 'A']++;
        while(s[i] == s[i + 1]){
            i++;
        }
        if(check[s[i] - 'A'] > 1){
            cout << "NO\n";
            return ;
        }
        if(i == n - 2){
            if(s[n-2] != s[n-1]){
                if(check[s[n-1] - 'A'] >= 1){
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";

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