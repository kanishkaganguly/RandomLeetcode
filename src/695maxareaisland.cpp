#include <algorithm>
#include <functional>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
public:
  int maxAreaOfIsland(std::vector<std::vector<int>> &grid) {
    int numRows = grid.size();
    int numCols = grid[0].size();
    int area = 0;

    for (int r = 0; r < numRows; r++) {
      for (int c = 0; c < numCols; c++) {
        area = std::max(area, dfs(grid, numRows, numCols, r, c));
      }
    }
    return area;
  }

  bool inVisitSet(const int &r, const int &c) {
    if (visit.find(std::make_pair(std::ref(r), std::ref(c))) == visit.end()) {
      return false;
    } else {
      return true;
    }
  }

  int dfs(const std::vector<std::vector<int>> &grid, const int &numRows,
          const int &numCols, const int &r, const int &c) {
    if (r < 0 || r == numRows || c < 0 || c == numCols || grid[r][c] == 0 ||
        inVisitSet(r, c)) {
      return 0;
    }
    visit.insert(std::make_pair(r, c));
    return (1 + Solution::dfs(grid, numRows, numCols, r + 1, c) +
            Solution::dfs(grid, numRows, numCols, r - 1, c) +
            Solution::dfs(grid, numRows, numCols, r, c + 1) +
            Solution::dfs(grid, numRows, numCols, r, c - 1));
  }

private:
  struct hashFunction {
    std::size_t operator()(const std::pair<int, int> &x) const {
      return x.first ^ x.second;
    }
  };

  std::unordered_set<std::pair<int, int>, Solution::hashFunction> visit;
};

int main(int argc, char **argv) {
  std::vector<std::vector<int>> input = {
      {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
      {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
      {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
  Solution s = Solution();
  std::cout << s.maxAreaOfIsland(input) << std::endl;
}