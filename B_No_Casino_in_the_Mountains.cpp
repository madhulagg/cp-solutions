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

int solution(string &s1, string &s2, int idx1, int idx2, string temp){
    if(idx1 <= 0 && idx2 <= 0){
        reverse(temp.begin(), temp.end());
        if(temp == s2) return 1;
        return 0;
    }
    if(s1[idx1] == s2[idx2]){
        int nottake = solution(s1, s2, idx1-1, idx2, temp);
        temp+=s1[idx1];
        int take = solution(s1, s2, idx1-1, idx2-1, temp);
        return take + nottake;
    }
    else{
        return solution(s1, s2, idx1-1, idx2, temp);
    }

}


void solve(){
    int a, b;
    cin >> a >> b;
    vector<int> v(a);
    for(int i = 0; i < a; i++) cin >> v[i];
    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < a; i++){
        if(v[i] == 0){
            cnt++;
            if(cnt == b){
                cnt = 0;
                ans++;
                i++;
            }
        }
        else{
            cnt = 0;
        }
    }
    cout << ans << endl;
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