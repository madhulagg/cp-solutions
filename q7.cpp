#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int main(){
    string s;
    cin>>s;
    int len = s.length();
    int arr_len = (len+1)/2 ;
    int arr[arr_len];
    for(int i=0; i<arr_len;i++){
        arr[i] = s[2*i];
    }
    sort(arr, arr + arr_len);
    for(int i=0;i<arr_len-1;i++){
        cout<<arr[i]<<"=";
    }
    cout<<arr[arr_len-1];
}