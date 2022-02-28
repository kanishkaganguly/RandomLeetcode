#include <algorithm>
#include <iostream>
#include <locale>
#include <string>

class Solution {
public:
  bool isPalindrome(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    int len = s.size();
    char *c = new char[len + 1];
    std::copy(s.begin(), s.end(), c);
    c[len] = '\0';

    char *l, *r;
    l = c;
    r = c + len - 1;

    while (l < r) {
      // std::cout << "L: " << *l << " R: " << *r << std::endl;
      while (l < r && !std::isalnum(*l)) {
        l += 1;
      }
      while (r > l && !std::isalnum(*r)) {
        r -= 1;
      }

      if (*l != *r) {
        return false;
      }
      l += 1;
      r -= 1;
    }

    return true;
  }
};

int main(int argc, char **argv) {
  std::string input("A man, a plan, a canal: Panama");
  Solution s = Solution();
  std::cout << s.isPalindrome(input) << std::endl;
}