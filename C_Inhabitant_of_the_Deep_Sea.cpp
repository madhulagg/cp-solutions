#include <iostream>
#include <deque>
using namespace std;

void solve() {
    int n,k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    int s,l;
    s = 0;
    l = 0;
    for(int i = 0 ; i < n; i++){
        s = s + arr[i];
        if(s  == ((k+1)/2)){
            s = i + 1;
            break;
        }
        else if(s > (k/2)){
            s = i;
            break;
        }
    }
    int h=-1;
    for(int i = n-1 ; i >= 0; i--){
        h++;
        l = l + arr[i];
        if(l  == ((k+1)/2)){
            l = (h + 1);
            break;
        }
        else if(s > (k/2)){
            l = (h);
            break;
        }
    }
    if(s+l > n){
        s  = 0;
        l = 0;
    }
    cout << s+l << endl;
    
    // int l = 0;
    // int r = n - 1;
    // int round = 0;
    // int sunk = 0;
    // while(k-- && l <= r){
    //     if(round%2 == 0){
    //         arr[l]--;
    //         if(arr[l] == 0){
    //             l++;
    //             sunk++;
    //         }
    //     }
    //     else{
    //         arr[r]--;
    //         if(arr[r] == 0){
    //             r--;
    //             sunk++;
    //         }
    //     }
    //     round++;
    // }
    // cout  << sunk << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
