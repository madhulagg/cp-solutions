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

void solve(){
    int n, m;
    cin >> n >> m;
    int dirx[4] = {0, 0, 1, -1};
    int diry[4] = {1, -1, 0, 0};
    vector<vector<char>> v(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    pair<int, int> start;
    pair<int, int> end;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(v[i][j] == 'A'){
                start = {i, j};
            }
            if(v[i][j] == 'B'){
                end = {i, j};
            }
        }
    }
    vector<vector<pair<int, int>>>par(n, vector<pair<int, int>>(m, {-1, -1}));
    q.push(start);
    visited[start.ff][start.ss] = 1;
    bool present = false;
    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int x = p.ff + dirx[i];
            int y = p.ss + diry[i];
            if(x >= 0 && x < n && y >= 0 && y < m && visited[x][y] == false && (v[x][y] == '.' || v[x][y] == 'B')){
                par[x][y] = {p.ff, p.ss};
                if(v[x][y] == 'B'){
                    present = true;
                }
                q.push({x, y});
                visited[x][y] = 1;
            }
        }
    }
    if(present == false){
        cout << "NO";
        return;
    }
    cout << "YES\n";

    string ans;

    while(end != start){
        pair<int, int> p = par[end.ff][end.ss];
        if(p.ff - end.ff == 0 && p.ss - end.ss == 1){
            //l
            ans += 'L';
        }
        else if(p.ff - end.ff == 0 && p.ss - end.ss == -1){
            //r
            ans += 'R';
        }
        else if(p.ff - end.ff == 1 && p.ss - end.ss == 0){
            //u
            ans += 'U';
        }
        else if(p.ff - end.ff == -1 && p.ss - end.ss == 0){
            //d
            ans += 'D';
        }
        end = par[end.ff][end.ss];
    }
    cout << ans.length() << endl;
     
    reverse(ans.begin(), ans.end());
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