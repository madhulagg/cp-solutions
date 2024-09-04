#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int countSetBits(int x) {
    int count = 0;
    while (x > 0) {
        count += (x & 1);
        x >>= 1;
    }
    return count;
}

int binaryStringToInt(const string &binaryStr) {
    long long result = 0;
    for (char c : binaryStr) {
        result = (result << 1) + (c - '0');
    }
    return (int)result;
}

int possibleDecryptions(const string &binaryStr, int k) {
    long long n = 0;
    for (char c : binaryStr) {
        n = (n << 1) + (c - '0');
    }
    long long count = 0;

    for (long long i = 1; i <= n; i++) {
        long long x = i;
        long long steps = 0;
        
        while (x > 1 && steps < k) {
            x = countSetBits(x);
            steps++; 
        }
        
        if (x == 1 && steps == k) {
            count = (count + 1) % MOD;
        }
    }

    return (int)(count%MOD);
}

int main() {
    string binaryStr;
    int k;
    cin >> binaryStr >> k;
    cout << possibleDecryptions(binaryStr, k) << endl;
    return 0;
}
