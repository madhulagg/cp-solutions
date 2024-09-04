#include <bits/stdc++.h>
#define int long long
using namespace std;

// Madhul_Aggarwal

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

bool possibility(const string &s, const string &str) {
    int j = 0;
    for (int i = 0; i < s.length() && j < str.length(); i++) {
        if (s[i] == str[j]) {
            j++;
        }
    }
    if(j == str.length()){
        return true;
    }
    return false;
}

bool canfound(int n, int k, const string &s, string &result, int index = 0) {
    if (index == n) {
        if (!possibility(s, result)) {
            return true;
        }
        return false;
    }

    for (int i = 0; i < k; i++) {
        result[index] = 'a' + i;
        if (canfound(n, k, s, result, index + 1)) {
            return true;
        }
    }
    return false;
}

signed main() {
    int testcase;
    cin >> testcase;
    while (testcase--) {
        int n, k, len;
        cin >> n >> k >> len;
        string s;
        cin >> s;

        string result(n, ' ');
        if (canfound(n, k, s, result)) {
            cout << "NO\n" << result << endl;
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}
