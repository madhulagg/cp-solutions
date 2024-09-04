#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        int arr[a];
        bool val = false;
        for(int i=0;i<a;i++){
            cin>>arr[i];
            if(arr[i]==b){
                val = true;
            }
        }
        if(val){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}