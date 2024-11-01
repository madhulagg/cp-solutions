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

int diff(const string &s) {
    int sum1 = 0, sum2 = 0;
    for (size_t i = 0; i < s.length(); i++) {
        if ((i + 1) % 2 == 1) {
            sum1 += (s[i] - '0');
        } else {
            sum2 += (s[i] - '0');
        }
    }
    int d = (sum1 - sum2) % 11;
    if (d < 0) d += 11;
    return d;
}

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "-1\n";
        return;
    }

    string s(n - 1, '3');
    s += '6';
    int d = diff(s);
    if (d == 0) {
        cout << s << endl;
        return;
    }

    int req = (-d) % 11;
    if (req < 0) req += 11;

    vector<int> odd, even;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '3') {
            if ((i + 1) % 2 == 1) {
                odd.push_back(i);
            } else {
                even.push_back(i);
            }
        }
    }

    bool found = false;
    string res = "";

    for (int k = 1; k <= n - 1 && !found; k++) {
        for (int x = 0; x <= k && x <= odd.size(); x++) {
            int y = k - x;
            if (y > even.size()) continue;

            int mod = ((x - y) * 3) % 11;
            if (mod < 0) mod += 11;

            if (mod == req) {
                string temp = s;

                for (int i = 0; i < x; i++) {
                    if (i < odd.size()) {
                        temp[odd[odd.size() - 1 - i]] = '6';
                    }
                }

                for (int i = 0; i < y; i++) {
                    if (i < even.size()) {
                        temp[even[even.size() - 1 - i]] = '6';
                    }
                }

                int new_d = diff(temp);
                if (new_d == 0) {
                    if (!found || temp < res) {
                        res = temp;
                        found = true;
                    }
                }
            }
        }
    }

    if (found) {
        cout << res << endl;
    } else {
        cout << "-1\n";
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