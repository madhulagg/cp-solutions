#include<iostream>
#include<string.h>
#include<math.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long len;
        cin>>len;
        long long sum = 0;
        long long arr[len];
        for(long long i=0;i<len;i++){
            cin>>arr[i];
            sum = sum + arr[i];
        }
        bool check = false;
        for(long long i=0;i<(sum/2);i++){
            long long val = i*i;
            if(sum==(val)){
            check = true;
            }
        }
        if(check)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
}