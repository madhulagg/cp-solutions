#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    
    for (int i = 1; i < s.length(); i++) {
        if(s[i]  == 0 ) i++;
        else{ 
             while (i > 0 && (s[i] > (s[i-1] + 1)) )
            {
                s[i]--;
                swap(s[i], s[i - 1]);
                i--;
            }
        }
    }
    cout << s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
