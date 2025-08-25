#include <bits/stdc++.h>
using namespace std;
int noofways(vector<int> &nos, int target){
    
}
int main(){
    int n;
    cin >> n;
    vector<int> nos(n);
    for(int i = 0; i < n; i++){
        cin >> nos[i];
    }
    int target;
    cin >> target;
    cout << noofways(nos, target);
}
