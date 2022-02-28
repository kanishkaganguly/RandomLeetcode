#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>

class Solution {
public:
  int evalRPN(std::vector<std::string> &tokens) {
    for (auto i : tokens) {
      if (i.compare("+") == 0) {
        stack.push(pop_stack() + pop_stack());
      } else if (i.compare("-") == 0) {
        int a = pop_stack();
        int b = pop_stack();
        stack.push(b - a);
      } else if (i.compare("*") == 0) {
        stack.push(pop_stack() * pop_stack());

      } else if (i.compare("/") == 0) {
        int a = pop_stack();
        int b = pop_stack();
        stack.push(b / a);
      } else {
        stack.push(std::stoi(i));
      }
    }

    return stack.top();
  }

private:
  std::stack<int> stack;
  inline int pop_stack() {
    int val = stack.top();
    stack.pop();
    return val;
  }
};

int main(int argc, char **argv) {
  std::vector<std::string> input = {"2", "1", "+", "3", "*"};
  Solution s = Solution();
  std::cout << s.evalRPN(input) << std::endl;
}