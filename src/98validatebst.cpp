#include <algorithm>
#include <iostream>
#include <climits>
#include <string>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr){};
  TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right){};
};

class Solution {
public:
  TreeNode *insert(TreeNode *root, long val) {

    if (root == nullptr) {
      return new TreeNode(val);
    }
    if (val > LONG_MIN+1) {
      if (val < root->val) {
        root->left = insert(root->left, val);
      } else if (val > root->val) {
        root->right = insert(root->right, val);
      }
    }

    return root;
  }

  void inorder(TreeNode *root) {
    if (root == nullptr) {
      return;
    }

    inorder(root->left);
    std::cout << root->val << " ";
    inorder(root->right);
  }

  bool valid(TreeNode *curr, long left, long right) {
    if (curr == nullptr) {
      return true;
    }

    if (!((curr->val < right) && (curr->val > left))) {
      return false;
    }

    return valid(curr->left, left, curr->val) &&
           valid(curr->right, curr->val, right);
  }

  bool isValidBST(TreeNode *root) { return valid(root, LONG_MIN, LONG_MAX); }
};

int main(int argc, char **argv) {
  std::vector<float> s1 = {2, 1, 3};
  std::vector<float> s2 = {5, 1, 4, LONG_MIN, LONG_MIN, 3, 6};

  Solution sol1 = Solution();
  TreeNode *root1 = nullptr;
  for (auto val : s1) {
    root1 = sol1.insert(root1, val);
  }
  sol1.inorder(root1);
  std::cout << std::boolalpha << sol1.isValidBST(root1) << std::endl;

  Solution sol2 = Solution();
  TreeNode *root2 = nullptr;
  for (auto val : s2) {
    root2 = sol2.insert(root2, val);
  }
  sol2.inorder(root2);
  std::cout << std::boolalpha << sol2.isValidBST(root2) << std::endl;
}