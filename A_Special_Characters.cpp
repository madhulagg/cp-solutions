#include <iostream>
using namespace std;

void s(int n) {
    string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string temp = "";
    if (n % 2 == 0)
    {
        int x = n / 2;
        int i = 0;
        while (x--)
        {
            temp += s[i];
            temp += s[i];
            i++;
        }
    }
    else
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << temp << endl;
}

int main() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        s(n);
    }
    return 0;
}
