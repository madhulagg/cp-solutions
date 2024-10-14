#include <bits/stdc++.h>
#define int long long int
using namespace std;

//Madhul_Aggarwal

using ll = long long;
using lld = long double;
using ull = unsigned long long;

const lld pi = 3.141592653589793238;
// const ll INF = LONG_LONG_MAX;
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
    int n, r;
    cin >> n >> r;
    int fam[n];
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cin >> fam[i];
        cnt+=fam[i];
    }



    if(cnt <= r){
        cout << cnt << endl;
        return ;
    }
    int cnt1 = 0;
    int cnt2 = 0;

    for(int i = 0; i < n; i++){
        if(fam[i] % 2 == 0){
            cnt2+=(fam[i]/2);
            fam[i] = 0;
        }
        else{
            cnt2+=(fam[i] - 1)/2;
            fam[i] = 1;
            cnt1++;
        }
    }
    
    int remainingrows = r - cnt2 ;
    if(cnt1 <= remainingrows){
        cout << cnt2*2 + cnt1 << endl;
        return;
    }
    else{
        if(cnt1 == remainingrows*2){
            cout << cnt2 * 2 << endl;
            return;
        }
        cout << remainingrows - (cnt1 - remainingrows) + 2 * cnt2 << endl;
        return;
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