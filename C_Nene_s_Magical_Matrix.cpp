#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, vector<int>>> solve(int n) {
  vector<vector<int>> matrix(n, vector<int>(n, 0));
  vector<pair<int, vector<int>>> operations; // Stores operation type and permutation

  // Check initial state and perform operations if needed
  for (int i = 0; i < n; ++i) {
    // Check both diagonals simultaneously (principal and secondary)
    if (matrix[i][i] != 1 && matrix[i][n - i - 1] != 1) {
      int target_i = (matrix[i][i] != 1) ? i : (n - i - 1); // Prioritize principal diagonal

      // Perform operation based on target diagonal
      if (target_i == i) {
        // Type 2 operation (column permutation)
        operations.push_back({2, {i + 1}}); // Type 2 operation (1-based indexing)
        for (int k = 0; k < n; ++k) {
          if (k != target_i) {
            // Swap elements within the column (excluding the diagonal element)
            swap(matrix[k][target_i], matrix[i][target_i]);
          }
        }
      } else {
        // Type 1 operation (row permutation)
        operations.push_back({1, {target_i + 1, i + 1}}); // Type 1 operation and permutation (1-based indexing)
        for (int k = 0; k < n; ++k) {
          if (k != i) {
            swap(matrix[target_i][k], matrix[target_i][i]); // Swap elements within the row (excluding the chosen element)
          }
        }
      }
      matrix[target_i][target_i] = 1; // Set the diagonal element to 1
    }
  }

  return operations;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<pair<int, vector<int>>> operations = solve(n);

    cout << n * (n + 1) << " " << operations.size() << endl; // Total sum and number of operations
    for (auto& op : operations) {
      cout << op.first << " " << op.second.size();
      for (int p : op.second) {
        cout << " " << p;
      }
      cout << endl;
    }
  }

  return 0;
}
