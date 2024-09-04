#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    long long testcase;
    cin>>testcase;
    while(testcase--){
        long long len1,len2,c;
        cin>>len1>>len2>>c;
        long long arr1[len1];
        long long arr2[len2];
        for(long long i=0;i<len1;i++){
            cin>>arr1[i];
        }
        for(long long i=0;i<len2;i++){
            cin>>arr2[i];
        }
        sort(arr1, arr1 + len1);
        sort(arr2, arr2 + len2);
        long long min = arr1[0];
        long long max = arr2[len2-1];
        long long sum = 0;
        if(c%2 == 1){
            for(int i=0;i<len1;i++){
                sum = sum + arr1[i];
            }
        }
        else{
            arr1[0] = max;
            for(int i=0;i<len1;i++){
            sum = sum + arr1[i];    
            }
        }
    cout<<sum<<endl;
    }
}