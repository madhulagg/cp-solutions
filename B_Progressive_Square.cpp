#include <bits/stdc++.h>
#define int long long
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

bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
bool isPerfectSquare(ll x)
{
    if (x >= 0)
    {
        ll sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}
int binarysearch(int arr[], int len, int tofind){
    int low = 0;
    int high = len - 1;
    int mid;
    while(low<=high){
        mid = low + ((high - low)/2) ;
        if(arr[mid] == tofind){
            return mid;
            // first occurence thing changes here
            // for last occurence we need to add a parameter to check the last occurence limiting case is last element of A array
        }
        else if(arr[mid] > tofind){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}

void solve(){
    
    int n, c, d;
    cin >> n >> c >> d;
    vector<int>v(n*n);
    for(int i = 0 ; i < (n*n) ; i++){
        cin >> v[i];
    }
    bool val = false;
    int x,y;
    sort(v.begin(), v.end());
    int min = v[0];
    vector<int>q;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            q.push_back(min + (i*c) + (j*d));
        }
    }
    sort(q.begin(), q.end());
    for(int i = 0 ; i < (n*n); i++){
        if(q[i] != v[i]){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;

    // int a,d,c;
    // cin >> a >> c >> d;
    // int matrix[a][a];
    // for(int i = 0 ; i < a ; i++){
    //     for(int j = 0 ; j < a ; j++){
    //         cin >> matrix[i][j];
    //     }
    // }
    // bool val1 = false;
    // for(int i = 1 ; i < a ; i++){
    //     for(int j = 1 ; j < a ; j++){
    //         if(matrix[i][j] == (matrix[i-1][j] + d))
    //         {
    //             if(matrix[i][j] == (matrix[i][j-1] + d))
    //             {
    //                 val1 = true;
    //             }
    //         }
    //     }
    // }
    // if(val1){
    //     cout << "YES" << endl;
    // }
    // else{
    //     cout << "NO" << endl;
    // }

}
 
signed main(){
    FAST;
    int testcase;
    cin>>testcase;
    while(testcase--){
        solve();
    }
}