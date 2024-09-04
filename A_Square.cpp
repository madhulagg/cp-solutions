#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int x[4];
        int y[4];
        for(int i=0;i<4;i++){
            cin>>x[i]>>y[i];
        }
        if(x[0]==x[1]){
        }
        else if(x[0]==x[2]){
            int tempx,tempy;
            tempx = x[1];
            tempy = y[1];
            x[1] = x[2];
            y[1] = y[2];
            x[2] = tempx;
            y[2] = tempy;
        }
        else if(x[0]==x[3]){
            int tempx,tempy;
            tempx = x[1];
            tempy = y[1];
            x[1] = x[3];
            y[1] = y[3];
            x[3] = tempx;
            y[3] = tempy;
        }
        int diffx = abs(x[0] - x[2]);
        int diffy = abs(y[0]- y[1]);
        cout<<(diffx * diffy)<<endl;
    }
}