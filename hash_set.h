#ifndef _HASH_SET_H
#define _HASH_SET_H

#include <vector>
#include <algorithm>

template<typename T, const int LIM = (int) 1e+6 + 7> 
class hash_set {
 private:
  typename std::vector<T> hash[LIM];
  typename std::vector<T>::iterator first, last;
  
 public:
  hash_set() {}
  
  inline int pos(T h) {
    return (h % LIM + LIM) % LIM;
  }
  
  void insert(T h) {
    hash[pos(h)].push_back(h);
  }
  
  bool find(T h) {
    first = hash[pos(h)].begin();
    last = hash[pos(h)].end();
    return std::find(first, last, h) != last;
  }
  
  void erase(T h) {
    hash[pos(h)].erase(h);
  }
  
  void clear() {
    for (int i = 0; i < LIM; i++)
      hash[i].clear();
  }
};

#endif
