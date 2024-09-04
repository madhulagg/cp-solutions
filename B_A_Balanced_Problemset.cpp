#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int x, n;
        std::cin >> x >> n;

        // Calculate difficulty per sub-problem (rounded up)
        int difficulty_per_subproblem = std::ceil(static_cast<double>(x) / n);

        // Calculate the GCD of difficulty_per_subproblem and n
        int max_balance = gcd(difficulty_per_subproblem, n);

        std::cout << max_balance << std::endl;
    }

    return 0;
}
