#include <bits/stdc++.h>
using namespace std;
int main(){
    // string s;
    // cin >> s;
    // int n = s.size();
    // int localmax = INT_MIN;
    // for(int i = 0; i < n; i++){
    //     localmax = max((int)(s[i]-'0'), localmax);
    // }
    // // localmax = localmax - '0';
    // char ans[n][localmax];
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < localmax; j++){
    //         ans[i][j] = ' ';
    //     }
    // }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < (s[i] - '0'); j++){
    //         ans[j][i] = '*';
    //     }
    // }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < (localmax); j++){
    //         cout << ans[i][j];
    //     }
    //     cout << endl;
    // }
    int n;
    cin >> n;
    string num = to_string(n);
    int len = num.length();
    int arr[len];
    for(int i = 0; i < len; i++){
        arr[i] = num[i] - '0';
    }
    int max = 0;
    for(int i = 0; i < len; i++){
        if (arr[i]>max){
            max = arr[i];
        }
    }
    for(int i = 0; i < max; i++){
        for(int j = 0; j < len; j++){
            if(arr[j] > i){
                cout<<'*';
            }
            else{
                cout<<' ';
            }
        }
        cout << '\n';
    }

}