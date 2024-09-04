// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     int len;
//     cin>>len;
//     int arr[len];
//     for(int i=0;i<len;i++){
//         cin>>arr[i];
//     }
//     sort(arr, arr + len);
//     int no;
//     cin>>no;
//     int arr2[no];
//     int cnt;
//     for(int i=0;i<no;i++){
//         cnt = 0;
//         cin>>arr2[i];
//         for(int j=0;j<len;j++){
//             if(arr[j] > arr2[i]){
//                 cnt = j;
//             }
//             else{
//                 continue;
//             }
//         }
//         cout<<cnt<<endl;
//     }

//     // int len;
//     // cin>>len;
//     // int arr[len];
//     // for(int i=0;i<len;i++){
//     //     cin>>arr[len];
//     // }
//     // sort(arr,arr+len);

//     // int no;
//     // cin>>no;
//     // int arr2[no];
//     // int ans;
//     // for(int i=0;i<no;i++){
//     //     cin>>arr2[i];
//     //     for(int j=0;j<len;j++){
//     //         if(arr[j] > arr2[i]){
//     //             ans = j;
//     //             break;
//     //         }
//     //         else{
//     //             continue;
//     //         }
//     //     }
//     //     cout<<ans<<endl;
//     // }
// }
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }
    sort(prices.begin(), prices.end());
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int m;
        cin >> m;
        int count = upper_bound(prices.begin(), prices.end(), m) - prices.begin();
        cout << count << endl;
    }

    return 0;
}
