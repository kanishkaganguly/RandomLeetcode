#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// Leetcode 435. Non-overlapping Intervals

class Solution {
public:
  static bool compareFirst(const std::vector<int> &vec1,
                           const std::vector<int> &vec2) {
    return vec1[0] < vec2[0];
  }

public:
  int eraseOverlapIntervals(std::vector<std::vector<int>> &intervals) {
    std::sort(intervals.begin(), intervals.end(), compareFirst);
    int result = 0;
    int prevEnd = intervals[0][1];
    for (std::size_t i = 1; i < intervals.size(); i++) {
      int start = intervals[i][0];
      int end = intervals[i][1];

      // Check not overlapping. Same point is non-overlapping.
      if (start >= prevEnd) {
        prevEnd = end;
      }
      // Check overlapping
      else {
        result += 1;
        prevEnd = std::min(end, prevEnd);
      }
    }
    return result;
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
  std::vector<std::vector<int>> s1 = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
  std::vector<std::vector<int>> s2 = {{1, 2}, {1, 2}, {1, 2}};
  std::vector<std::vector<int>> s3 = {{1, 2}, {2, 3}};
  Solution s = Solution();
  std::cout << s.eraseOverlapIntervals(s1) << std::endl;
  std::cout << s.eraseOverlapIntervals(s2) << std::endl;
  std::cout << s.eraseOverlapIntervals(s3) << std::endl;
}