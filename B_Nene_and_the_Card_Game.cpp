#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b;
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    int cnt = 0;
    for(auto it : mp){
        if(it.second == 1){
            b.push_back(it.first);
        }
        else if(it.second == 0){
            b.push_back(it.first);
            b.push_back(it.first);
            // cnt--;
        }
        else{
            cnt+=2;
        }
    }
    cout << cnt/2 << endl;

}

signed main(){
    int testcase;
    cin>>testcase;
    while(testcase--){
        solve();
    }
}

