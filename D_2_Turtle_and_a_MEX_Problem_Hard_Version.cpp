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

int sum(int x) {
    return x*(x+1)/2;
}
int interval(int l,int r) {
    return sum(r)-sum(l-1);
}
vector<int> son[1000001];
int dp[1000001];
void solve() {
    int n,m,s=0,mint=0;
    map<int,int> cnt;
    cin >> n >> m;
    for(int i=1,u,v;i<=n;++i) {
        int l;
        cin >> l;
        set<int> t;
        for(int i=1,x;i<=l;++i) {
            cin >> x;
            t.insert(x);
        }
        bool flag=true;
        for(int i=0;;++i) {
            if(!t.count(i)) {
                if(flag) {
                    flag=false;
                    u=i;
                    mint=max(mint,u);
                }
                else {
                    v=i;
                    break;
                }
            }
        }
        s=max(s,v);
        son[v].push_back(u);
        cnt[u]++;
    }
    for(int i=0;i<=s;++i) dp[i]=-1;
    for(int i=s;i>=0;--i) {
        if(dp[i]==-1) dp[i]=i;
        for(int j:son[i]) dp[j]=max(dp[j],dp[i]);
    }
    int pp=0;
    for(int i=0;i<=s;++i)
        if(i<=mint) dp[i]=max(dp[i],mint);
    for(auto i:cnt) {
        if(i.second>=2) pp=max(pp,dp[i.first]);
    }
    for(int i=0;i<=s;++i)
        dp[i]=max(dp[i],pp);
    for(int i=0;i<=s;++i) son[i].clear();
    if(m<=s) {
        int sum=0;
        for(int i=0;i<=m;++i) sum+=dp[i];
        cout << sum << endl;
        return;
    }
    int sum=0;
    for(int i=0;i<=s;++i) sum+=dp[i];
    sum+=interval(s+1,m);
    cout << sum << endl;
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