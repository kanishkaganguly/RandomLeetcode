#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// Leetcode 763. Partition Labels

class Solution {
public:
  std::vector<int> partitionLabels(std::string s) {
    std::unordered_map<char, int> lastIndexOfChar;
    // Add last index of each character in string to map
    for (int i = 0; i < s.length(); i++) {
      lastIndexOfChar[s.at(i)] = i;
    }

    std::vector<int> result;
    int size = 0, end = 0;
    for (int i = 0; i < s.length(); i++) {
      size += 1;
      end = std::max(end, lastIndexOfChar[s.at(i)]);
      if (i == end) {
        result.push_back(size);
        size = 0;
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
  std::string s1("ababcbacadefegdehijhklij");
  std::string s2("eccbbbbdec");

  Solution s = Solution();
  std::cout << s.partitionLabels(s1) << std::endl;
  std::cout << s.partitionLabels(s2) << std::endl;
  return 0;
}