#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

int findMEX(const vector<int>& arr) {
  int n = arr.size();
  vector<int> freq(n + 1, 0); // Frequency array for elements (0 to n)
  for (int num : arr) {
    freq[num]++;
  }

  int mex = 0;
  while (freq[mex] == 0) {
    mex++;
  }
  return mex;
}

vector<pair<int, int>> findDivision(const vector<int>& a, int k) {
  int n = a.size();

  // Trivial cases
  if (n == k) {
    int target_mex = findMEX(a);
    if (find(a.begin(), a.end(), target_mex) != a.end()) {
      return vector<pair<int, int>>(k, {0, 0}); // Each element is a subsegment
    } else {
      return vector<pair<int, int>>{{-1, -1}}; // No valid division
    }
  }

  if (k == 1) {
    return a[0] == a[n - 1] ? vector<pair<int, int>>{{0, n - 1}} : vector<pair<int, int>>{{-1, -1}};
  }

  // Calculate MEX of entire array
  int target_mex = findMEX(a);

  // Iterative approach
  vector<pair<int, int>> subsegments;
  int current_mex = -1;
  for (int i = 0; i < n; i++) {
    if (a[i] == target_mex) {
      if (current_mex == -1 || current_mex == target_mex) {
        subsegments.push_back({i, i});
        current_mex = target_mex;
      } else {
        return vector<pair<int, int>>{{-1, -1}}; // Invalid division
      }
    } else {
      current_mex = -1;
    }
  }

  if (subsegments.size() != k) {
    return vector<pair<int, int>>{{-1, -1}}; // Not enough subsegments
  }

  return subsegments;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    vector<pair<int, int>> division = findDivision(a, k);
    if (division[0].first == -1) {
      cout << -1 << endl;
    } else {
      cout << division.size() << endl;
      for (const auto& sub : division) {
        cout << sub.first << " " << sub.second << endl;
      }
    }
  }

  return 0;
}
