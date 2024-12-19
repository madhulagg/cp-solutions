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

// void solve(){   
//     int m,a,b,c;
//     cin >> m >> a >> b >> c;
//     int tt = 2*m;
//     int cnt = 0;
//     int lefta = 0;
//     int leftb = 0;
//     if(a <= m){
//         cnt+=a;
//         lefta = m - a;
//     }
//     if(b <= m){
//         cnt+=b;
//         leftb = m-b;
//     }
//     if(a > m){
//         cnt+=a;
//     }
//     if(b > m){
//         cnt += b;
//     }
//     if(lefta + leftb <= c) cnt+=c;
//     cout << cnt << endl;

// }
void solve(){   
        long long m, a, b, c;
        cin >> m >> a >> b >> c;
        long long seated_row1 = min(m, a); 
        long long seated_row2 = min(m, b);
        long long remaining_row1 = m - seated_row1;
        long long remaining_row2 = m - seated_row2;
        long long seated_c = min(c, remaining_row1 + remaining_row2);
        long long total_seated = seated_row1 + seated_row2 + seated_c;
        cout << total_seated << endl;
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