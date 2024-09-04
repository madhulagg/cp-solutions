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
    int n; 
    cin>>n;
    while(n>=11111 && n%11111==0) 
    n/=11111;
    while(n>= 11011 && n%11011==0) 
    n/=11011;
    while(n>=11101 && n%11101==0) 
    n/=11101;
    while(n>=11001 && n%11001==0) 
    n/=11001;
    while(n>=10111 && n%10111==0) 
    n/=10111;
    while(n>=10101 && n%10101==0) 
    n/=10101;
    while(n>=10011 && n%10011==0) 
    n/=10011;
    while(n>=10001 && n%10001==0) 
    n/=10001;
    while(n>=1111 && n%1111==0) 
    n/=1111;
    while(n>=1101 && n%1101==0) 
    n/=1101;
    while(n>=1011 && n%1011==0) 
    n/=1011;
    while(n>=1001 && n%1001==0) 
    n/=1001;
    while(n>=111 && n%111==0) 
    n/=111;
    while(n>=101 && n%101==0) 
    n/=101;
    while(n>=11 && n%11==0) 
    n/=11;
    while(n>=10 && n%10==0) 
    n/=10;
    
    if(n==1) 
    cout<<"YES"<<endl;
    else 
    cout<<"NO"<<endl;
}
 
signed main(){
    FAST;
    int testcase;
    cin>>testcase;
    while(testcase--){
        solve();
    }
}