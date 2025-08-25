#include <bits/stdc++.h>
using namespace std;

void merge(int l, int m, int r, vector<int> &x) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = x[l + i];
    for (int j = 0; j < n2; j++) R[j] = x[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            x[k++] = L[i++];
        } else {
            x[k++] = R[j++];
        }
    }

    while (i < n1) x[k++] = L[i++];
    while (j < n2) x[k++] = R[j++];
}

void mergesort(int l, int r, vector<int> &x){
    if(l >= r) return;
    int m = l + (r-l)/2;
    mergesort(l, m, x);
    mergesort(m+1, r, x);
    merge(l, m, r, x);
}

int main(){
    int n;
    cin >> n;
    vector<int> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];
    mergesort(0, n-1, x);
    for(int i = 0; i < n; i++) cout << x[i] << " ";
    cout << endl;
    return 0;
}