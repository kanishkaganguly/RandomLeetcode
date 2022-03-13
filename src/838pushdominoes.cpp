#include <deque>
#include <iostream>
#include <string>

// Leetcode 838. Push Dominoes

class Solution {
public:
  std::string pushDominoes(std::string dominoes) {
    std::deque<std::pair<int, char>> q;

    for (std::size_t i = 0; i < dominoes.length(); i++) {
      if (dominoes.at(i) != '.') {
        q.push_back(std::make_pair(i, dominoes.at(i)));
      }
    }

    while (!q.empty()) {
      std::pair<int, char> elem = q.front();
      int i = elem.first;
      char d = elem.second;
      q.pop_front();

      if (d == 'L') {
        if ((i > 0) && (dominoes.at(i - 1) == '.')) {
          q.push_back(std::make_pair(i - 1, 'L'));
          dominoes[i - 1] = 'L';
        }
      } else if (d == 'R') {
        if ((i + 1 < dominoes.length()) && (dominoes.at(i + 1) == '.')) {
          if ((i + 2 < dominoes.length()) && (dominoes.at(i + 2) == 'L')) {
            q.pop_front();
          } else {
            q.push_back(std::make_pair(i + 1, 'R'));
            dominoes[i + 1] = 'R';
          }
        }
      }
    }
    return dominoes;
  }
};

int main(int argc, char **argv) {
  std::string input("RR.L");
  std::string input2(".L.R...LR..L..");
  Solution s = Solution();
  std::cout << s.pushDominoes(input) << std::endl;
  std::cout << s.pushDominoes(input2) << std::endl;
}