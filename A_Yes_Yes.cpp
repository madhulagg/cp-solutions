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

void solve(){
    string s;
    cin >> s;
    string possible = "Yes";
    int n = s.length();
    if(s[0] == possible[0] || s[0] == possible[1] || s[0] == possible[2]){
        if(s[0] == possible[0]){
            for(int i = 0; i < n; i++){
                if(s[i] != possible[i % 3]){
                    cout << "NO" << endl;
                    return;
                }
            }
        }
        else if(s[0] == possible[1]){
            for(int i = 0; i < n; i++){
                if(s[i] != possible[(i+1) % 3]){
                    cout << "NO" << endl;
                    return;
                }
            }
        }
        else{
            for(int i = 0; i < n; i++){
                if(s[i] != possible[(i+2) % 3]){
                    cout << "NO" << endl;
                    return;
                }
            }
        }
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
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