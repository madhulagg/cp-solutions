#include <iostream>
#include <vector>
using namespace std;

vector<bool> checkprime(int n) {
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int p = 2; p * p <= n; ++p) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }
    return prime;
}

int countAlmostPrimes(int n) {
    vector<bool> prime = checkprime(n);
    int count = 0;
    for (int i = 2; i <= n; ++i) {
        int temp = i;
        int primeFactors = 0;

        for (int j = 2; j <= temp / j; ++j) {
            if (temp % j == 0 && prime[j]) {
                ++primeFactors;
                while (temp % j == 0) {
                    temp /= j;
                }
            }
        }
        if (temp > 1 && prime[temp]) ++primeFactors;
        

        if (primeFactors == 2) {
            ++count;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    cout << countAlmostPrimes(n);
    return 0;
}
