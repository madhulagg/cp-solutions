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

int countGoodSubsegments(int n, int m, int k, const vector<int>& a, const vector<int>& b) {
    unordered_map<int, int> freq_a, freq_b;
    int good_subsegments = 0;
    
    for (int i = 0; i < m; ++i) {
        freq_a[a[i]]++;
        freq_b[b[i]]++;
    }

    int matching_count = 0;
    for (auto& pair : freq_b) {
        int element = pair.first;
        if (freq_a[element] >= pair.second) {
            matching_count += pair.second;
        }
    }
    if (matching_count >= k) {
        good_subsegments++;
    }
    for (int i = m; i < n; ++i) {
        int outgoing_element = a[i - m];
        int incoming_element = a[i];

        freq_a[outgoing_element]--;
        if (freq_a[outgoing_element] == 0) {
            freq_a.erase(outgoing_element);
        }
        freq_a[incoming_element]++;

        matching_count = 0;
        for (auto& pair : freq_b) {
            int element = pair.first;
            if (freq_a[element] >= pair.second) {
                matching_count += pair.second;
            }
        }
        if (matching_count >= k) {
            good_subsegments++;
        }
    }
    
    return good_subsegments;
}
 
signed main(){
    FAST;
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> b(m);
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }

        int result = countGoodSubsegments(n, m, k, a, b);
        cout << result << endl;
    }
    return 0;
}

