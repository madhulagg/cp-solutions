#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int len = s.length();
    bool val = true;
    // if(len != 1){
    for(int i=0;i<len-1;i++){
        if(s[i] == 'A' && s[i+1]=='C'){
            val = false;
            break;
        }
        else if(s[i] == 'B' && s[i+1] == 'A'){
            val = false;
            break;
        }
        else if(s[i] == 'C' && s[i+1] == 'B'){
            val = false;
            break;
        }
    }
    if(val == false){
        cout<<"No";
    }
    else{
        cout<<"Yes";
    }
}
    // else{
    //     if(s[0] == 'A'){
    //         cout<<"Yes";
    //     }
    //     else{
    //         cout<<"NO";
    //     }
    // }
// }