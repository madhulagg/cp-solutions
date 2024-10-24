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

void solve(){
    int n, gSum;
    cin >> n >> gSum;
    int tSum = 0;
    unordered_map<int,int> mpp;
    for(int i = 0; i < n; i++){
        int j;
        cin >> j;
        tSum+=j;
        mpp[j]++;
    }
    int check = 1;
    while(gSum > 0){
        if(mpp[check] == 0){
            gSum -= check;
            tSum += check;
        }
        check++;
    }

    if(gSum < 0){
        cout << "NO" << endl;
        return;
    }
    int k;
    for(int i = 1; ; i++){
        if((i * (i+1)) / 2 >= (tSum + gSum)){
            k = i;
            break;
        }
    }
    if((k * (k+1)) / 2 != (tSum + gSum)){
        cout << "NO" << endl;
        return;
    }    

    cout << "YES" << endl;
    return;

    // int n, sum;
    // cin >> n >> sum;
    // vector<int> givenNum(101,0);
    // for(int i = 0; i < n; i++){
    //     int n;
    //     cin >> n;
    //     givenNum[n - 1]++;
    // }
    // for(int i = 0; sum >= 0; i++){
    //     if(givenNum[i] == 0){
    //         sum-=(i + 1);
    //         givenNum[i]++;
    //     }
    // }
    // if(sum < 0){
    //     cout << "NO" << endl;
    //     return;
    // }
    // bool val = true;
    // for(int i = 0; i < 101; i++){
    //     if(givenNum[i] == 1 && val == false){
    //         cout << "NO" << endl;
    //         return;
    //     }
    //     else if(givenNum[i] == 0){
    //         val = false;
    //     }
    // }
    // cout << "YES" << endl;
    // return;

    // int a,b;
    // // cin >> a >> b;
    // // unordered_map<int,bool> mpp;
    // // for(int i = 0; i < a; i++){
    // //     int n;
    // //     cin >> n;
    // //     mpp[n] = true;
    // // }
    // // for(int i = 1; ; i++){
    // //     if(mpp.find(i) != mpp.end()){
    // //         if(b >= i){
    // //             b-=i;
    // //             mpp[i] = true;
    // //         }
    // //         else{
    // //             cout << "NO" << endl;
    // //             return;
    // //         }
    // //     }
    // // }

    // // if(b > 0){
    // //     cout << "NO" << endl;
    // //     return;
    // // }
    // // for(int i = 1; )
    // int a,b;
    // cin >> a >> b;
    // int arr[a];
    // int sum = 0;

    // for(int i = 0; i < a; i++){
    //     cin >> arr[i];
    //     sum += arr[i];
    // }

    // sum += b;

    // for(int i = 0; ; i++){
    //     if(((i*i) + i)/2 == sum){
    //         cout << "YES" << endl;
    //         return;
    //     }
    //     else if(((i*i) + i)/2 > sum){
    //         cout << "NO" << endl;
    //         return;
    //     }

    // }
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