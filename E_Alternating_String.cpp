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

const int ALPHABET_SIZE = 26;
int max_char_count(const vector<int>& counter) {
    return *max_element(counter.begin(), counter.end());
}

int min_operations_even(const string& s) {
    vector<int> even_counter(ALPHABET_SIZE, 0);
    vector<int> odd_counter(ALPHABET_SIZE, 0);
    int n = s.length();
    
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            even_counter[s[i] - 'a']++;
        } else {
            odd_counter[s[i] - 'a']++;
        }
    }

    int even_max_count = max_char_count(even_counter);
    int odd_max_count = max_char_count(odd_counter);

    return (n / 2 - even_max_count) + (n / 2 - odd_max_count);
}

int min_operations_odd(string s) {
    int n = s.length();
    vector<int> even_counter(ALPHABET_SIZE, 0);
    vector<int> odd_counter(ALPHABET_SIZE, 0);
    vector<int> even_counter_after(ALPHABET_SIZE, 0);
    vector<int> odd_counter_after(ALPHABET_SIZE, 0);

    for (int i = 0; i < n - 1; i++) {
        if (i % 2 == 0) {
            even_counter[s[i] - 'a']++;
        } else {
            odd_counter[s[i] - 'a']++;
        }
    }

    int best = LLONG_MAX;
    int even_max_count = max_char_count(even_counter);
    int odd_max_count = max_char_count(odd_counter);

    best = min(best, (n / 2 - even_max_count) + (n / 2 - odd_max_count));

    for (int i = n - 2; i >= 0; i--) {
        if (i % 2 == 0) {
            even_counter[s[i] - 'a']--;
            even_counter_after[s[i + 1] - 'a']++;
        } else {
            odd_counter[s[i] - 'a']--;
            odd_counter_after[s[i + 1] - 'a']++;
        }

        vector<int> even_counter_merged(ALPHABET_SIZE, 0);
        vector<int> odd_counter_merged(ALPHABET_SIZE, 0);

        for (int j = 0; j < ALPHABET_SIZE; j++) {
            even_counter_merged[j] = even_counter[j] + even_counter_after[j];
            odd_counter_merged[j] = odd_counter[j] + odd_counter_after[j];
        }

        even_max_count = max_char_count(even_counter_merged);
        odd_max_count = max_char_count(odd_counter_merged);

        best = min(best, (n / 2 - even_max_count) + (n / 2 - odd_max_count));
    }

    return (n < 2) ? 1 : best + 1;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n < 2) {
        cout << 1 << endl;
    } else if (n % 2 == 0) {
        cout << min_operations_even(s) << endl;
    } else {
        cout << min_operations_odd(s) << endl;
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