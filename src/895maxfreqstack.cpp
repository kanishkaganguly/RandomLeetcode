#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class FreqStack {
public:
  std::unordered_map<int, int> count;
  std::unordered_map<int, std::vector<int>> stacks;
  int maxCount;

public:
  FreqStack() : maxCount(0) {}

  void push(int val) {
    int valCount = 1 + count[val];

    count[val] = valCount;
    if (valCount > maxCount) {
      maxCount = valCount;
      stacks.insert({valCount, std::vector<int>()});
    }
    stacks[valCount].push_back(val);
  }

  int pop() {
    int res = stacks[maxCount].back();
    stacks[maxCount].pop_back();

    count[res] -= 1;
    if (stacks[maxCount].empty()) {
      maxCount -= 1;
    }
    return res;
  }
};

int main(int argc, char **argv) {
  std::vector<std::string> input = {"FreqStack", "push", "push", "push",
                                    "push",      "push", "push", "pop",
                                    "pop",       "pop",  "pop"};
  std::vector<int> input_vals = {
      -1, 5, 7, 5, 7, 4, 5, -1, -1, -1, -1,
  };

  FreqStack *obj = new FreqStack();
  for (int i = 0; i < input.size(); i++) {
    std::cout << "Input: " << input[i] << std::endl;

    if (input[i].compare("FreqStack") == 0) {
      std::cout << "Output: "
                << "null"
                << "\n";
    } else if (input[i].compare("push") == 0) {
      obj->push(input_vals[i]);
      std::cout << "PushOutput: "
                << "null"
                << "\n";
    } else if (input[i].compare("pop") == 0) {
      int param_2 = obj->pop();
      std::cout << "PopOutput: " << param_2 << "\n";
    }
  }
}