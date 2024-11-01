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


class PermutationSolver {
public:
    void solve(int s) {
        vector<int> p(s);
        
        if(s == 5) p = {2, 1, 3, 4, 5};  
        else if(s == 6) p = {1, 2, 4, 6, 5, 3};  
        else if(s == 7) p = {2, 4, 5, 1, 3, 6, 7};  
        else if(s == 8) p = {2, 4, 5, 1, 3, 6, 7, 8};  
        else if(s == 9) p = {2, 4, 5, 6, 7, 1, 3, 8, 9};  
        else if(s == 10) p = {1, 2, 3, 4, 5, 6, 8, 10, 9, 7};  
        else for(int i = 0; i < s; i++) p[i] = i + 1;

        int k = 0;
        for(int i = 1; i <= p.size(); i++) {
            if(i % 2 == 1) k &= p[i - 1];
            else k |= p[i - 1];
        }

        cout << k << endl;
        for(int i = 0; i < s; i++) {
            cout << p[i] << (i == s - 1 ? '\n' : ' ');
        }
    }
};




 
signed main(){
    FAST;
    int testcase;
    cin>>testcase;
    // testcase = 1;
    PermutationSolver solver;
    while(testcase--) {
        int n;
        cin >> n;
        solver.solve(n);
    }
    return 0;
}