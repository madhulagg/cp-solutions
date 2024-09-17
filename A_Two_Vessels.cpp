#include <bits/stdc++.h>
using namespace std;

// #define int long long int

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    
    if (a == b) {
        cout << "0" << endl;
        return;
    }
    if(a < b){
        swap(a,b);
    }
    if(a > b){
        int cnt = 0;
        while(a>b){
            a-=c;
            b+=c;
            cnt++;
            if(a <= b){
                break;
            }
        }
        cout << cnt << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);

    int testcase;
    cin >> testcase;
    while (testcase--) {
        solve();
    }
    return 0;
}
