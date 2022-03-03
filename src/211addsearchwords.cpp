#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

class TrieNode {
public:
  TrieNode() {}
  inline bool isInChildren(const char &ch) {
    if (_children.count(ch) > 0) {
      return true;
    } else {
      return false;
    }
  }
  std::map<char, std::shared_ptr<TrieNode>> _children;
  bool _word = false;
};

class WordDictionary {
public:
  WordDictionary() : root(std::make_shared<TrieNode>()) {}
  std::shared_ptr<TrieNode> root;

  void addWord(std::string word) {
    std::shared_ptr<TrieNode> curr = root;
    for (char ch : word) {
      if (!curr->isInChildren(ch)) {
        curr->_children[ch] = std::make_shared<TrieNode>();
      }
      curr = curr->_children[ch];
    }
    curr->_word = true;
  }

  bool trieDFS(const int &index, const std::string &word,
               std::shared_ptr<TrieNode> root) {
    std::shared_ptr<TrieNode> curr = root;

    for (std::size_t i = index; i < word.size(); i++) {
      const char &c = word[i];
      if (c == '.') {
        for (const auto &items : curr->_children) {
          std::shared_ptr<TrieNode> j = items.second;
          if (trieDFS(i + 1, word, j)) {
            return true;
          }
        }
        return false;
      } else {
        if (!curr->isInChildren(c)) {
          return false;
        }
        curr = curr->_children[c];
      }
    }
    return curr->_word;
  }

  bool search(std::string word) { return trieDFS(0, word, root); }
};

int main(int argc, char *argv[]) {
  std::vector<std::string> input = {"WordDictionary", "addWord", "addWord",
                                    "addWord",        "search",  "search",
                                    "search",         "search"};
  std::vector<std::string> input_vals = {"",    "bad", "dad", "mad",
                                         "pad", "bad", ".ad", "b.."};

  WordDictionary *obj = new WordDictionary();

  for (size_t i = 0; i < input.size(); i++) {
    if (input[i].compare("WordDictionary") == 0) {
      std::cout << "null\t";
    } else if (input[i].compare("addWord") == 0) {
      obj->addWord(input_vals[i]);
      std::cout << "null\t";
    } else if (input[i].compare("search") == 0) {
      bool param_2 = obj->search(input_vals[i]);
      std::cout << std::boolalpha << param_2 << "\t";
    }
  }
}