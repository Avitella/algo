#ifndef _STRING_FUNCTIONS
#define _STRING_FUNCTIONS

#include <vector>
#include <string>

std::vector<size_t> prefix_function(const std::string& s) {
  std::vector<size_t> prefix(s.length(), 0);
  size_t j = 0;
  for (size_t i = 1; i < s.length(); ++i) {
    while (j > 0 && s[i] != s[j])
      j = prefix[j - 1];
    if (s[i] == s[j])
      ++j;
    prefix[i] = j;
  }
  return prefix;
}

#endif
