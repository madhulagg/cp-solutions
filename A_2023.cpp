#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int lenque;
        int lenans;
        cin>>lenque>>lenans;
        int arr[lenque];
        int arr2[lenans];
        int product=1;
        for(int i=0;i<lenque;i++){
            cin>>arr[i];
            product = product * arr[i];
            if(arr[i]%7 != 0 && arr[i]%17 != 0; arr[i]!=1){
                cout<<"NO"<<endl;
                break;
            }
            else{
                if(((int)2023 % product) == 0){
                    cout<<"YES"<<endl<<(2023/product)<<endl;
                }
                else{
                    cout<<"NO"<<endl;
                }
            }
        }

    }
}