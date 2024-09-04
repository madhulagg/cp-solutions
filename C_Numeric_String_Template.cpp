#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

struct State {
    int row, col, mask, steps;
};

int shortestPathToCollectGold(vector<vector<int>>& maze, int x, int y) {
    int n = maze.size(), m = maze[0].size();
    int totalGold = 0;
    vector<pair<int, int>> goldPositions;

    // Find all gold positions and calculate total gold
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (maze[i][j] == 2) {
                goldPositions.emplace_back(i, j);
                totalGold++;
            }
        }
    }

    int targetMask = (1 << totalGold) - 1; // All bits set to 1 (indicating all gold collected)
    queue<State> q;
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(1 << totalGold, false)));

    q.push({0, 0, 0, 0}); // Start from (0, 0) with 0 gold collected
    visited[0][0][0] = true;

    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // Directions for movement

    while (!q.empty()) {
        auto [row, col, mask, steps] = q.front();
        q.pop();

        // If all gold collected and at Alice's position
        if (mask == targetMask && row == x && col == y) {
            return steps;
        }

        // Explore all 4 directions
        for (auto& dir : dirs) {
            int newRow = row + dir[0], newCol = col + dir[1];
            int newMask = mask;

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && maze[newRow][newCol] != 1) {
                // Check if the new position has a gold coin
                for (int i = 0; i < goldPositions.size(); ++i) {
                    if (newRow == goldPositions[i].first && newCol == goldPositions[i].second) {
                        newMask |= (1 << i); // Collect the gold
                        break;
                    }
                }

                if (!visited[newRow][newCol][newMask]) {
                    visited[newRow][newCol][newMask] = true;
                    q.push({newRow, newCol, newMask, steps + 1});
                }
            }
        }
    }

    return -1; // If it's not possible to collect all gold and reach Alice
}

int main() {
    int n, m, x, y;
    
    cout << "Enter the number of rows (n): ";
    cin >> n;
    cout << "Enter the number of columns (m): ";
    cin >> m;

    vector<vector<int>> maze(n, vector<int>(m));
    cout << "Enter the maze elements (0 for open, 1 for blocked, 2 for gold):" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> maze[i][j];
        }
    }

    cout << "Enter Alice's position (x y): ";
    cin >> x >> y;

    int result = shortestPathToCollectGold(maze, x, y);
    if (result == -1) {
        cout << "It's not possible for Bob to collect all the gold and reach Alice." << endl;
    } else {
        cout << "Shortest path length: " << result << endl;
    }

    return 0;
}
