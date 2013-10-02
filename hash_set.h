#ifndef _HASH_SET_H
#define _HASH_SET_H

#include <vector>
#include <algorithm>

template<const int LIM = (int) 1e+6 + 7> 
class hash_set {
 private:
  std::vector<long long> hash[LIM];
  
 public:
  hash_set() {}
  
  inline int pos(long long h) {
    return (h % LIM + LIM) % LIM;
  }
  
  void insert(long long h) {
    hash[pos(h)].push_back(h);
  }
  
  bool find(long long h) {
    auto first = hash[pos(h)].begin();
    auto last = hash[pos(h)].end();
    return std::find(first, last, h) != last;
  }
  
  void erase(long long h) {
    hash[pos(h)].erase(h);
  }
  
  void clear() {
    for (int i = 0; i < LIM; i++)
      hash[i].clear();
  }
};

#endif
