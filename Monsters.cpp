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

int dx[4] = {0, 0, +1, -1};
int dy[4] = {+1, -1, 0, 0};
char dxy[4] = {'R', 'L', 'D', 'U'};

bool dfs(vector<vector<char>> &grid, vector<char> &ans, int x, int y, int m, int n, vector<vector<int>> &vis){
    for(int i = 0; i < 4; i++){
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx >= 0 && xx < m && yy >= 0 && yy < n && (grid[xx][yy] == '.' || grid[xx][yy] == 'A') && vis[xx][yy] == 0){
            vis[xx][yy] = 1;
            ans.push_back(dxy[i]);
            if(grid[xx][yy] == 'A') return true;
            if(!dfs(grid, ans, xx, yy, m, n, vis)){
                ans.pop_back();
            }
            else{
                return true;
            }
        }
    }
    return false;
}

void solve(){
    int m, n;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    vector<pair<int, int>> p;
    for(int i = 0; i < m; i++){
        if(grid[i][0] == '.') p.push_back({i, 0});
        if(grid[i][n-1] == '.') p.push_back({i, n-1}); 
    }
    for(int i = 0; i < n; i++){
        if(grid[0][i] == '.') p.push_back({0, i});
        if(grid[m-1][i] == '.') p.push_back({m-1, i});
    } 

    if(p.empty()){
        cout << "NO";
        return;
    }

    vector<char> ans;
    bool found = false;
    for(int i = 0; i < (int)p.size(); i++){
        vector<vector<int>> vis(m, vector<int>(n, 0)); 
        vis[p[i].first][p[i].second] = 1;
        if(dfs(grid, ans, p[i].first, p[i].second, m, n, vis)){
            found = true;
            break;
        }
    }

    if(!found){
        cout << "NO";
        return;
    }
    cout << "YES" << endl;
    cout << ans.size() << endl;
    for(int i = (int)ans.size() - 1; i >= 0; i--){
        char c = ans[i];
        if(c == 'L') cout << 'R';
        else if(c == 'R') cout << 'L';
        else if(c == 'U') cout << 'D';
        else cout << 'U';
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