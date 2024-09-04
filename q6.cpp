#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int len;
        cin>>len;
        int arr1[len];
        int arr2[len];
        for(int i=0; i<len; i++){
            cin>>arr1[i]>>arr2[i];    
        }
        int s = arr1[0];
        for(int i=1; i<len; i++){
            if(s<=arr1[i] && i != (len-1)){
                if(arr2[0]>arr2[i]){
                    continue;
                }
                else if(arr2[0]<=arr2[i]){
                    cout<<"-1"<<endl;
                    break;
                }
            }
            else if(s <= arr1[i] && (i == len-1)){
                if(arr2[0]>arr2[i]){
                    cout<<s<<endl;
                }
                else if(arr2[0]<=arr2[i]){
                    cout<<"-1"<<endl;
                }
            }
            else if(s>arr2[i] && i==(len-1)){
                cout << s << endl;
            }
        }
    }
}