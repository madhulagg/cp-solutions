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

// static mt19937 gen(time(0));
// vector<int> available_numbers;
// int current_index = 0;

// void initialize_random_numbers(int min, int max) {
//     for (int i = min; i <= max; i++) {
//         available_numbers.push_back(i);
//     }
//     shuffle(available_numbers.begin(), available_numbers.end(), gen);
// }

// int randomnum() {
//     if (current_index >= available_numbers.size()) {
//         throw runtime_error("No more unique random numbers available!");
//     }
//     return available_numbers[current_index++];
// }

// void solvelr(vector<int>& v, vector<int>& a, int l, int r, int t) {
//     bool val = true;
//     int key;
//     for (int i = 0; i < t; i++) {
//         if ((t % v[i]) == 0) {
//             val = false;
//             key = v[i];
//         }
//     }
//     if (val) {
//         cout << "-1" << endl;
//         return;
//     }
//     int j;
//     for (j = 0; (j + key) < r; j++) {
//         int value = randomnum();
//         a[j] = value;
//         a[j + key] = value;
//     }
//     solvelr(v, a, j, r - j, t);
// }

// void solve(vector<int>& v) {
//     int t;
//     cin >> t;
//     vector<int> a(t);
//     solvelr(v, a, 0, t, t);
//     for (int i = 0; i < t; i++) {
//         cout << a[i] + 1 << " ";
//     }
//     cout << endl;
// }
void solve() {
    int n;
    cin >> n;
    vector<int> out(n,0);
    if(n%2 != 0){
        if(n<27){
            cout << -1 << endl;
            return;
        }
        out[0] = 1;
        out[9] = 1;
        out[25] = 1;
        out[22] = 2;
        out[26] = 2;
        int k = 3;
        int count = 0;
        for(int i = 0; i<n; i++){
            if(out[i]==0){
                out[i] = k;
                count++;
                if(count == 2){
                    count = 0;
                    k++;
                }
            }
        }
    }
    if(n%2 == 0){
        int k = 1;
        for(int i = 0; i<n; i=i+2){
            out[i] = k;
            out[i+1] = k;
            k++;
        }
    }
    for(auto x : out){
        cout << x << " ";
    }
    cout << endl;
}

signed main() {
    FAST;
    int testcase;
    cin >> testcase;

    // // Initialize the pool of random numbers
    // initialize_random_numbers(1, 1e6);

    // vector<int> v;
    // for (int i = 2; i <= 1e3; i++) {
    //     v.push_back(i * i);
    // }
    while (testcase--) {
        solve();
    }
}
