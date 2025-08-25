#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long solve(int idx, vector<int> v, int k){
        if(k == 0) {
            return LLONG_MAX;
        }
        if(idx == 0){
            return LLONG_MAX;
        } //1634456
        else if(idx == v.size() - 1){
            int nottake = solve(idx - 1, v, k);



            1, 2, 3, 4 -> 2, 3, 1, 4 -> 3, 2, 1, 4 -> 2, 1, 4, 3
 // 1 -> n
            2, 1, 4, 3 -> 3, 2, 1, 4
// 2 -> m
            3, 2, 1, 4



            //. 
//              1, 4, 3, 2 ->  2,3, 1, 4
//              2, 3, 1, 4 
            //

            for(int i = L; i <= R; i++){
                int temp = i;
                while(temp != 0){
                    if((temp & 5) == 5){
                        cnt++;
                        if(cnt == K){
                            return i;
                        }
                    }
                    else{
                        temp = temp / 2;
                    }
                }
            }
            return -1;


            int t = max(nottake, abs(v[idx] - v[idx - 1]));
            v[idx] = v[idx - 1];
            int take = solve(idx - 1, v, k - 1);
            int tt = max(take, abs(v[idx] - v[idx - 1]));
            return min(t, tt);
        }
        else{
            int t, tt;
            int nottake = solve(idx - 1, v, k);
            if(abs(v[idx] - v[idx + 1] > abs(v[idx] - v[idx - 1]))){
                v[idx] = v[idx + 1];
                int take = solve(idx - 1, v, k - 1);
                t = max(take, abs(v[idx + 1] - v[idx]));
            }
            else{ 
                v[idx] = v[idx - 1];
                int take = solve(idx - 1, v, k - 1);
                tt = max(take, abs(v[idx - 1] - v[idx]));
            }   
            return min(t, tt);
        }
    }    

// vector<int> ss(vector<int> &v){

    //     int maxi = 0;
    //     int f, s;

    //     for(int i = 0; i < v.size() - 1; i++){
    //         if(maxi < abs(v[i] - v[i + 1])){
    //             maxi = (v[i] - v[i + 1]);
    //             f = i; s = i+1;
    //         }
    //     }
    //     return {maxi, f, s};
    // }
    // long long solve(vector<int> v, int k){
    //     int n = v.size();
    //     if(n < 2) return 0;
    //     int ans;
    //     while(k--){
    //         vector<int> t = ss(v);
    //         int bb,ss;
    //         if(v[t[1]] < v[t[2]]){
    //             ss = t[1];
    //             bb = t[2];
    //         }
    //         else{
    //             bb = t[1];
    //             ss = t[2];
    //         }
    //         v[bb] = v[ss];
    //         vector<int> ttt = ss(v);
    //         ans = ttt[0];
    //     }
    //     // 
        
    // }
    
};
