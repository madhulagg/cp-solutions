#include <bits/stdc++.h>
// #define int long long
using namespace std;

void solve(){
    int len;
    cin >> len;
    int arr[len];
    for(int i = 0 ; i < len ; i++){
        cin >> arr[i];
    }
    int cnt = 0;
    int val = 0;
    int index;
    int i = 0;
    int say = arr[0];
    while (arr[i] == say)
    {
        i++;
        cnt++;
    }
    index = i;
    i = len - 1;
    while(arr[i] == say && index < i){
        i--;
        val++;
    }
    cout << len - val - cnt << endl;

}
 
int main(){
    // FAST;
    int testcase;
    cin>>testcase;
    while(testcase--){
        solve();
    }
    // return 0;
}