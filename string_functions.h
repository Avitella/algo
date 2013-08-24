#ifndef _STRING_FUNCTIONS
#define _STRING_FUNCTIONS

#include <vector>
#include <string>

std::vector<size_t> prefix_function(const std::string& s) {
  std::vector<size_t> prefix(s.length());
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

std::vector<size_t> z_function(const std::string& s) {
  std::vector<size_t> z(s.length());
  for (size_t i=1, l=0, r=0; i<s.length(); ++i) {
    if (i <= r)
      z[i] = std::min(z[i-l], r-i+1);
    while (i+z[i]<s.length() && s[i+z[i]]==s[z[i]]) ++z[i];
    if (i+z[i]-1 > r) {
      l = i;
      r = i+z[i]-1;
    }
  }
  return z;
}

#endif
