#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define fr(i,a,b) for(int i = a; i<b; i++)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
typedef long long ll;

int main()
{
    FAST;
    int t;
    cin>>t;
    int n;
    while(t--){
        cin>>n;
        int ans = 0;
        vector<pair<int,int> > arr(n);
        fr(i,0,n)
            cin>>arr[i].first;
        fr(i,0,n)
            cin>>arr[i].second;
        sort(arr.begin(), arr.end());

        fr(i,0,n)
            cout<<arr[i].first<<' ';
        cout<<endl;
        fr(i,0,n)
            cout<<arr[i].second<<' ';
        cout<<endl;

    //     vector<bool> vis(n);
    //     fr(i,0,n)
    //     {
    //         int k = arr[i].second;
    //         vis[k-1] = true;
    //         fr(j,0,k)
    //         {
    //             if(!vis[j])
    //                 ans++;
    //         }
    //     }
    //     cout<<ans<<endl;
    }
    return 0;
}