#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
  std::unordered_map<int, int> nums1Idx;

public:
  std::vector<int> nextGreaterElement(std::vector<int> &nums1,
                                      std::vector<int> &nums2) {
    for (std::size_t i = 0; i < nums1.size(); i++) {
      nums1Idx[nums1[i]] = i;
    }
    std::vector<int> result(nums1.size(), -1);

    std::vector<int> stack = std::vector<int>();

    for (std::size_t i = 0; i < nums2.size(); i++) {
      int curr = nums2[i];
      while (!stack.empty() && curr > stack.back()) {
        int val = stack.back();
        stack.pop_back();

        int idx = nums1Idx[val];
        result[idx] = curr;
      }
      if (nums1Idx.find(curr) != nums1Idx.end()) {
        stack.push_back(curr);
      }
    }
    return result;
  }
};

int main(int argc, char const *argv[]) { return 0; }
