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

 
signed main(){
    int num;
    cin>>num;
    set<int> s;
    int len1,len2;
    cin >> len1;
    for(int i = 0; i < len1; i ++){
        int n;
        cin>>n;
        s.insert(n);
    }
    cin >> len2;
    for(int i = 0; i < len2; i ++){
        int n;
        cin>>n;
        s.insert(n);
    }
    // int lastindex;
    // auto it = s.end();
    // it --;
    // lastindex = (*it); 
    if((s.size()) >= num){
        cout << "I become the guy.";
    }
    else{
        cout << "Oh, my keyboard!";
    }
}