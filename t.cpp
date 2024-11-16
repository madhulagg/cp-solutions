#include <bits/stdc++.h>
using namespace std;
#define int long long

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
    int testcases;
    cin >> testcases;

    for (int i = 0; i < testcases; ++i) {
        temp();
    }

    return 0;
}
