#include<bits/stdc++.h>
using namespace std;
int main(){
    // int iter;
    // int maxno;
    // cin>>iter>>maxno;
    // int arr[maxno];
    // for(int i=0;i<maxno;i++){
    //     arr[i]= i + 1;
    // }
    // while(iter--){
    //     int len;
    //     cin>>len;
    //     int arr2[len];
    //     for(int j=0;j<len;j++){
    //         cin>>arr2[j];
    //         arr[(arr2[j])-1]++;
    //     }
    // }
    // for(int i=0;i<maxno;i++){
    //     if(arr[i]==0){
    //         cout<<"NO";
    //         break;
    //     }
    //     else{
    //         bool val = true;
    //         for(int i=0;i<maxno;i++){
    //             if(arr[i] % 2 == 0 || arr[i] == 0){
    //                 val = false;
    //                 break;
    //             }
    //         }
    //         if(!val){
    //             cout<<"YES";
    //             break;
    //         }
    //         else{
    //             cout<<"NO";
    //             break;
    //         }
    //     }
    // }
    int iter;
    int maxno;
    cin>>iter>>maxno;
    set<int> s;
    while(iter--){
        int len;
        cin>>len;
        for(int i=0;i<len;i++){
            int n;
            cin>>n;
            s.insert(n);
        }
    }
    if(s.size()==maxno){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}