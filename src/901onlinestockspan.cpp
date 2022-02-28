#include <algorithm>
#include <functional>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

class StockSpanner {
public:
  StockSpanner() {}
  std::vector<std::pair<int, int>> stack; // (price, span)

  int next(int price) {
    int span = 1;
    while (stack.size() > 0 && stack.back().first <= price) {
      span += stack.back().second;
      stack.pop_back();
    }
    stack.push_back(std::make_pair(price, span));
    return span;
  }
};

int main(int argc, char **argv) {
  std::vector<std::string> input = {"StockSpanner", "next", "next", "next",
                                    "next",         "next", "next", "next"};
  std::vector<int> input_vals = {-1, 100, 80, 60, 70, 60, 75, 85};
  StockSpanner s = StockSpanner();
  for (int i = 0; i < input.size(); i++) {
    if (input[i].compare("StockSpanner") == 0) {
      std::cout << "null\t";
    } else {
      std::cout << s.next(input_vals[i]) << "\t";
    }
  }
}