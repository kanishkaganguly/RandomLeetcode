#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// Leetcode 56. Merge Intervals
// Amazon Interview

class Solution {
public:
  static bool compareFirst(const std::vector<int> &vec1,
                           const std::vector<int> &vec2) {
    return vec1[0] < vec2[0];
  }

  std::vector<std::vector<int>>
  merge(std::vector<std::vector<int>> &intervals) {
    std::sort(intervals.begin(), intervals.end(), compareFirst);
    std::vector<std::vector<int>> output = {intervals[0]};

    for (std::size_t i = 0; i < intervals.size(); i++) {
      int start = intervals.at(i)[0];
      int end = intervals.at(i)[1];
      int lastEnd = output.at(output.size() - 1)[1];

      if (start <= lastEnd) {
        output[output.size() - 1][1] = std::max(lastEnd, end);
      } else {
        output.push_back(intervals.at(i));
      }
    }
    return output;
  }
};

// Pretty printing vectors
template <class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec) {
  for (std::size_t i = 0; i < vec.size(); i++) {
    os << vec[i] << "\t";
  }
  return os;
}

int main(int argc, char **argv) {
  std::vector<std::vector<int>> s1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  std::vector<std::vector<int>> s2 = {{1, 4}, {4, 5}};
  Solution s = Solution();
  std::cout << s.merge(s1) << std::endl;
  std::cout << s.merge(s2) << std::endl;
}