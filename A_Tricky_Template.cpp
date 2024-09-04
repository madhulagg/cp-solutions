#include <bits/stdc++.h>
#define int long long
using namespace std;

//Madhul_Aggarwal
void solve(){
    int len;
        cin>>len;
        string a;
        string b;
        string c;
        cin >> a >> b >> c;
        for(int i=0;i<len;i++){
            if(a[i] != c[i] && b[i] != c[i]){
                cout<<"YES"<<endl;
                return;
            }
        }
        cout<<"NO"<<endl;
}

int main(){
    int testcase;
    cin>>testcase;
    while(testcase--){
        solve();
    }
}