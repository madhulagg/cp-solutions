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
// 2 power hai ya nhi - t / f (bool) ;  0,1(int/bool) 
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
    string s;
    cin >> s;
    int hour = stoi(s.substr(0, 2));
    int minute = stoi(s.substr(3, 2));

    string result = "";
    if (hour == 0) {
        result += "12";
        result += ":";
        result += s.substr(3, 2);
        result += " AM";
    } else if (hour < 12) {
        result += s.substr(0, 2);
        result += ":";
        result += s.substr(3, 2);
        result += " AM";
    } else if (hour == 12) {
        result += "12";
        result += ":";
        result += s.substr(3, 2);
        result += " PM";
    } else {
        hour -= 12;
        if(hour < 10){
            result+="0";
        }
        result += to_string(hour);
        result += ":";
        result += s.substr(3, 2);
        result += " PM";
    }

    cout << result << endl;
}
// void solve(){
//     string s;
//     cin >> s;
//     int num = (10*(s[0]-'0') + (s[1])-'0');
//     int min = (10*(s[3]-'0') + s[4] - '0');
    
//     if(num >= 12){
//         if (num != 12) num = num - 12;
//         if(min > 10){
//             if(num >= 10)
//             cout<<num<<":"<<min<<" PM"<< endl;
//             else{
//                 cout<<"0"<<num<<":"<<min<<" PM"<< endl;
//             }
//         }
//         else{
//             if(num >= 10)
//             cout<<num<<":0"<<min<<" PM"<< endl;
//             else
//             cout<<"0"<<num<<":0"<<min<<" PM"<< endl;
//         }
//     }
//     else{
//         if(num == 0){
//         num = 12;
//         }
//         if(min >10){
//             if(num >= 10)
//             cout<<num<<":"<<min<<" AM"<< endl;
//             else
//             cout<<"0"<<num<<":"<<min<<" AM"<< endl;

//         }
//         else{
//             if(num >= 10)
//             cout<<num<<":0"<<min<<" AM"<< endl;
//             else{
//                 cout<<"0"<<num<<":0"<<min<<" AM"<< endl;
//             }
//         }
//     }
// }
 
signed main(){
    FAST;
    int testcase;
    cin>>testcase;
    while(testcase--){
        solve();
        /*
        int 
        int x = solve();*/
    }
}