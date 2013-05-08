#ifndef _DSU_H
#define _DSU_H

#include <vector>

class DSU {
 private:
  std::vector<int> dsu, size;
  
 public:
  DSU() {}
  
  void initialize(int n) {
    dsu.resize(n); size.resize(n);
    for (int i = 0; i < n; i++) {
      dsu[i] = i; size[i] = 1;
    }
  }
  
  DSU(int n) {
    initialize(n);
  }
  
  int find(int x) {
    return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
  }
  
  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
      if (size[x] > size[y])
        std::swap(x, y);
      dsu[x] = y;
      size[y] += size[x];
    }
  }
  
  bool equal(int x, int y) {
    return find(x) == find(y);
  }
};

#endif
