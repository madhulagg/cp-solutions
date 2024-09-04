#include <bits/stdc++.h>
using namespace std;
/*
Given a box of color, you can remove consecutive color, removing say n consecutive then add n*n to score,
and try to obtain maximum possible sum
*/
int solve(int n, char *arr){
    int count = 0;

}

int main(){
    int n;
    cin >> n;
    char arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << solve(n, arr);
}



/*
#include <bits/stdc++.h>
using namespace std;

int dp[100][100][100]; // dp array to store results of subproblems

int dfs(int l, int r, int k, char *arr) {
    if (l > r) return 0;
    if (dp[l][r][k] != -1) return dp[l][r][k];

    // Maximize score by removing k+1 consecutive elements
    dp[l][r][k] = (k + 1) * (k + 1) + dfs(l + 1, r, 0, arr);

    for (int i = l + 1; i <= r; ++i) {
        if (arr[i] == arr[l]) {
            dp[l][r][k] = max(dp[l][r][k], dfs(l + 1, i - 1, 0, arr) + dfs(i, r, k + 1, arr));
        }
    }

    return dp[l][r][k];
}

int solve(int n, char *arr) {
    memset(dp, -1, sizeof(dp)); // Initialize dp array with -1
    return dfs(0, n - 1, 0, arr);
}

int main() {
    int n;
    cin >> n;
    char arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << solve(n, arr) << endl;
    return 0;
}


*/