#include <bits/stdc++.h>
#include <limits.h>
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
    unordered_map<string, int>mpp;
    vector<pair<string, int> >p;
    fl(i, 0, n){
        string s;
        cin >> s;
        int score;
        cin >> score;
        p.push_back(make_pair(s, score));
        mpp[s]+= score;
    }
    int maxi = LLONG_MIN;
    for(auto it : mpp){
        maxi = max(maxi, it.second);
    }
    unordered_map<string, int> poss;
    for(auto it : p){
        poss[it.first] += it.second;
        if(poss[it.first] == maxi && mpp[it.first] == maxi){
            cout << it.first;
            break;
        }
    }
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