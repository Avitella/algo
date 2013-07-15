#ifndef _ALGO_MATH_H
#define _ALGO_MATH_H

#include <climits>
#include <vector>

long long bin_pow(long long x, int n, long long mod = LLONG_MAX) {
  if (!n) return 1;
  else if (n & 1) return x * bin_pow(x, n - 1, mod) % mod;
  else return bin_pow(x * x % mod, n >> 1, mod);
}

template<typename T> T gcd(T a, T b) {
  return a ? gcd(b % a, a) : b;
}

template<typename T> T gcd(T a, T b, T& x, T &y) {
  if (!a) return (x = 0), (y = 1), b;
  T x1, y1, g = gcd(b % a, a, x1, y1);
  return (x = y1 - (b / a) * x1), (y = x1), g;
}

template<typename T> T rev(T a, T mod) {
  T x, y; gcd(a, mod, x, y);
  return (x % mod + mod) % mod;
}

void eratosthenes(bool* p, const int& n) {
  std::fill(p, p + n, true);
  p[0] = p[1] = false;
  for (int i = 2; i * i < n; i++) {
    for (int j = i * i; p[i] && j < n; j += i) {
      p[j] = false;
    }
  }
}

#endif
