#include<bits/stdc++.h>
using namespace std;
int main(){
    int len;
    cin>>len;
    int arr[len];
    int firstindex;
    int ans[len];
    for(int i=0;i<len;i++){
        cin>>arr[i];
        if((arr[i]*(-1)) == 1){
            firstindex = i;
        }
    }
    ans[0] = firstindex + 1;
    int index;
    for(int i = 1; i<len; i++){
        // ans[i] = arr[ans[i-1]];
        for(int j=0; j<len;j++){
            if(ans[i-1] == arr[j]){
                index = j + 1;
            }
        }
        ans[i] = index;
    }
    // for(int i = 0; i<len; i++){
    //     ans[i] = ans[i] + 1;
    // }
    d
    for(int i=0; i<len; i++){
        cout<<ans[i]<<" ";
    }
}