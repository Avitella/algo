#ifndef _STRING_TOKENIZER
#define _STRING_TOKENIZER

#include <queue>
#include <string>
#include <deque>
#include "string_functions.h"

class string_tokenizer {
 public:
  string_tokenizer(const std::string& s, const std::string& separator) {
    std::string t = separator + '\0' + s;
    std::vector<int> prefix = prefix_function(t);
    std::vector<bool> sep_begin(t.length(), false);
    for (int i = separator.length() + 1; i < prefix.size(); ++i) {
      if (prefix[i] == separator.length()) {
        sep_begin[i - separator.length() + 1] = true;
      }
    }
    std::string add;
    int i = separator.length() + 1;
    while (i < prefix.size()) {
      if (sep_begin[i]) {
        if (!add.empty()) {
          tokens.push(add);
          add.clear();
        }
        i += separator.length();
      } else {
        add += t[i];
        ++i;
      }
    }
    if (!add.empty())
      tokens.push(add);
  }
  
  string_tokenizer(const std::string& s, const char& separator = ' ') {
    std::string add;
    for (auto c : s) {
      if (c != separator) {
        add += c;
      } else if (!add.empty()) {
        tokens.push(add);
        add.clear();
      }
    }
    if (!add.empty())
      tokens.push(add);
  }
  
  void push(std::string s, std::string separator) {
    string_tokenizer(s, separator);
  }
  
  void push(std::string s, char separator = ' ') {
    string_tokenizer(s, separator);
  }
  
  bool empty() {
    return tokens.empty();
  }
  
  int size() {
    return tokens.size();
  }
  
  std::string next_token() {
    std::string res = tokens.front(); 
    tokens.pop();
    return res;
  }
  
  std::string next_element() {
    return tokens.front();
  }
  
  void pop() {
    tokens.pop();
  }
  
  void clear() {
    while (!tokens.empty())
      tokens.pop();
  }
  
 private:
  std::queue< std::string, std::deque<std::string> > tokens;
};

#endif
