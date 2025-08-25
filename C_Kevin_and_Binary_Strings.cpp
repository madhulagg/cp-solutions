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
int bin_to_int(const string& s) {
    int result = 0;
    for (char c : s) {
        result = result * 2 + (c - '0');
    }
    return result;
}
// void solve(){
//     string s;
//     cin >> s; 
//     int n = s.length();
//     int maxval = -1;
//     pair<int, int> p1, p2;
//     for (int i = 0; i < n; i++) {
//         for (int j = i; j < n; j++) {
//             string x = s.substr(i, j - i + 1);
//             int num1 = bin_to_int(x);        
//             for (int p = 0; p < n; p++) {
//                 for (int q = p; q < n; q++) {
//                     string y = s.substr(p, q - p + 1);
//                     int num2 = bin_to_int(y);                        
//                     int xorval = num1 ^ num2;
                        
//                     if (xorval > maxval) {
//                         maxval = xorval;
//                         p1 = make_pair(i + 1, j + 1); 
//                         p2 = make_pair(p + 1, q + 1);  
//                     }
//                 }
//             }
//         }
//     }
//     cout << p1.first << " " << p1.second << " "<< p2.first << " " << p2.second << endl;
// }

void solve(){
    // string s;
    // cin >> s;
    // int n = -1;
    // for(int i = 0; i < s.length(); i++){
    //     if(s[i] == '0'){
    //         n = i;
    //         i = s.length();
    //     }
    // }
    // int k = n;
    // k++;
    // while(s[n] == '0'){
    //     n++;
    // }
    // // 0 = k -> n 
    // int ans = n - k + 1;
    // if(ans <= k){
    //     cout << "1 " << s.length() << " " << k - 1 - ans << " " << k - 1 - ans + k - 1<< endl;
    // }
    // else{
    //     cout << "1 " << s.length() << " " << "1 " << s.length() - k << endl;
    // }
    string s;
    cin >> s;
    int n = -1;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '0'){
            n = i;
            i = s.length();
        }
    }
    if(n == -1){
        cout << "1 " << s.length() <<" 1 1" << endl;
    }
    else{
        int first0 = n;
        while(s[n+1] == '0') n++;
        int last0 = n;
        int consec0 = last0 - first0 + 1;
        // 000 110 2
        if(consec0 <= (first0)){
            cout << "1 " << s.length() - n << " 1 " << s.length() << endl;
        }
        else{

        }
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




