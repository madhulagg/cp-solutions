#include<iostream>
using namespace std;
int main(){
    int testcase;
    cin>>testcase;
    while (testcase--)
    {
        long long sum = 0;
        long long count = 0;
        long long a,b,c;
        cin >> a >> b >> c;
        int arr[c];
        for(long long i = 0 ; i < c ; i++){
            cin>>arr[i];
            if(arr[i] < a){
            sum = sum + arr[i];
            }
            else{
                count++;
            }
        }
        cout<<(b + ((a-1)*count) + sum) <<endl;
    }
    
}