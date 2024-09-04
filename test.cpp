#include<iostream>
#include<string.h>
#include<math.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==b){
            cout<<c<<endl;
            break;
        }
        if(b==c){
            cout<<a<<endl;
            break;
        }
        if(a==c){
            cout<<b<<endl;
            break;
        }
    }
}
