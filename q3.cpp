#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int num;
        cin>>num;
        if(num<6){
            cout<<"NO"<<endl;
        }
        else{
            if(num%3 != 0){
                cout<<"YES"<<endl;
                cout<<"1 2 "<<num-3<<endl;
            }
            else{
                if(num == 3 || num == 6 || num ==9){
                    cout<<"NO"<<endl;
                }
                else{
                    cout<<"YES"<<endl<<"1 4 "<<num-5<<endl;
                }
            }
        }
    }
}