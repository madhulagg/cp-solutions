#include<bits/stdc++.h>
// #include<iostream>
// #include<vector>
// #include<algorithm>
using namespace std;
#define ll long long
#define pb push_back 
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<ll>v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        sort(v.begin(),v.end());
        vector<ll>diff;
        for(int i=0;i<n-1;i++)
            if((v[i+1] - v[i]) >0)
                diff.pb(v[i+1] - v[i]);
        ll sum = 0;
        ll max_c = 0;
        ll count = 0;
        int j = 0;
        for(int i=0;i<diff.size();i++)
        {
            sum+= diff[i];
            if(sum<n)
            {
                count++;
                max_c = max(count,max_c);
            }
            else
            {
                count++;
                while(sum>=n && count)
                {
                    sum-=diff[j];
                    count--;
                    j++;
                }
            }
        }
        cout<<max_c + 1<<endl;
    }
}