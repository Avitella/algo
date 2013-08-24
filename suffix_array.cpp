#include <vector>
#include <string>

std::vector<int> suffix_array(std::string s, const int alphabet) {
  s += '\0';
  const int N = s.length();
  
  std::vector<int> cls(N), arr(N), cls_t(N), arr_t(N), srt(max(N, alphabet));
  int classes; 
  
  for (int i=0; i<N; ++i)
    ++srt[s[i]];
  for (int i=1; i<=alphabet; ++i)
    srt[i] += srt[i-1];
  for (int i=0; i<N; ++i)
    arr[--srt[s[i]]] = i;
  cls[arr[0]] = 0;
  classes = 1;
  for (int i=1; i<N; ++i) {
    if (s[arr[i]] != s[arr[i-1]]) ++classes;
    cls[arr[i]] = classes-1;
  }
  
  for (int h=0; (1<<h)<N; ++h) {
    for (int i=0; i<N; ++i) {
      arr_t[i] = arr[i]-(1<<h);
      if (arr_t[i] < 0) arr_t[i] += N;
    }
    srt.assign(classes, 0);
    for (int i=0; i<N; ++i)
      ++srt[cls[i]];
    for (int i=1; i<classes; ++i)
      srt[i] += srt[i-1];
    for (int i=N-1; i>=0; --i)
      arr[--srt[cls[arr_t[i]]]] = arr_t[i];
    cls_t[arr[0]] = 0;
    classes = 1;
    for (int i=1; i<N; ++i) {
      int i1 = arr[i-1], i2 = arr[i];
      int j1 = (i1+(1<<h))%N, j2 = (i2+(1<<h))%N;
      if (cls[i1] != cls[i2] || cls[j1] != cls[j2]) ++classes;
      cls_t[arr[i]] = classes-1;
    }
    cls.assign(cls_t.begin(), cls_t.end());
  }
  
  arr.erase(arr.begin());
  return arr;
}
