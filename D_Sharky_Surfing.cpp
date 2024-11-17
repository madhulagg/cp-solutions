#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct PowerUp {
    int x, v;
};

struct Hurdle {
    int l, r;
};

int minPowerUpsToFinish(int n, int m, int L, vector<Hurdle>& hurdles, vector<PowerUp>& powerups) {
    int currentPosition = 1;
    int jumpPower = 1;
    int powerupCount = 0;
    int powerupIdx = 0;
    
    // Max-heap to store power-ups
    priority_queue<int> powerupsHeap;
    
    // Process hurdles and power-ups
    for (int i = 0; i < n; ++i) {
        int l = hurdles[i].l;
        int r = hurdles[i].r;
        
        // Collect power-ups while current position is less than the hurdle start
        while (currentPosition < l) {
            // Collect all power-ups up to current position
            while (powerupIdx < m && powerups[powerupIdx].x <= currentPosition) {
                powerupsHeap.push(powerups[powerupIdx].v); // Push power-up value
                powerupIdx++;
            }
            
            // Check if we can jump over the hurdle
            if (currentPosition + jumpPower >= l) {
                break;
            }
            
            // If we can't jump over, use the best available power-up
            if (powerupsHeap.empty()) {
                return -1; // No power-ups left and can't jump over
            }
            
            // Collect the largest power-up
            int maxPowerUp = powerupsHeap.top();
            powerupsHeap.pop();
            jumpPower += maxPowerUp;
            powerupCount++;
        }
        
        // Check if we can even make it past the current hurdle
        if (currentPosition + jumpPower < l) {
            return -1; // Can't even make it to the next hurdle
        }
        
        // Move past the current hurdle
        currentPosition = r + 1;
    }
    
    // Check if we can jump to the end L
    while (currentPosition < L) {
        // Collect power-ups up to current position
        while (powerupIdx < m && powerups[powerupIdx].x <= currentPosition) {
            powerupsHeap.push(powerups[powerupIdx].v);
            powerupIdx++;
        }
        
        // Check if we can reach the end L
        if (currentPosition + jumpPower >= L) {
            break;
        }
        
        // Use a power-up if we can't jump far enough
        if (powerupsHeap.empty()) {
            return -1; // Can't proceed and no power-ups left
        }
        
        // Collect the largest power-up
        int maxPowerUp = powerupsHeap.top();
        powerupsHeap.pop();
        jumpPower += maxPowerUp;
        powerupCount++;
    }
    
    return powerupCount;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m, L;
        cin >> n >> m >> L;
        
        vector<Hurdle> hurdles(n);
        vector<PowerUp> powerups(m);
        
        // Input hurdles
        for (int i = 0; i < n; ++i) {
            cin >> hurdles[i].l >> hurdles[i].r;
        }
        
        // Input power-ups
        for (int i = 0; i < m; ++i) {
            cin >> powerups[i].x >> powerups[i].v;
        }
        
        int result = minPowerUpsToFinish(n, m, L, hurdles, powerups);
        cout << result << endl;
    }
    
    return 0;
}
