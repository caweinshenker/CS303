#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <new>

using std::swap;
using std::vector;

#include "array.hpp"

namespace cs303 {
  template<typename T>
  array<T>::array(long int N)
  {
    if (N < 0) {
      throw std::invalid_argument("Negative vector length specified.");
    }
    n= N;
    a = new T[n];

  }

  template<typename T>
  array<T>::array(const array<T> &v)
  {n = v.size();
   a = new T[n];
    for (long int i = 0; i < n; i++) {
      a[i] = v[i];
    }
  }

  template<typename T>
  array<T>::~array()
  { delete[] a;
  }

  template<typename T>
  array<T>& array<T>::operator=(const array<T> &v)
  {
    if (n != v.size()) {
      throw std::runtime_error("Vectors in call to array<T>::operator= are of unequal size!");
    }
    for (long int i = 0; i < n; i++) {
      a[i] = v[i];
    }

    return *this;
  }

 template<typename T>
  void array<T>::quicksort()
  {quicksort(0, n - 1);
  }


  template<typename T>
  void array<T>::quicksort(long int lo, long int hi)
  { if (hi <= lo) return;
    long int j = partition(lo, hi);
    quicksort(lo, j-1);
    quicksort(j+1, hi);

  }

  template<typename T>
  long int array<T>::partition(long int lo, long int hi)
  {
    long int i = lo;
    long int j = hi + 1;
    double v = a[lo];
      while (true)
      {
	       while (a[++i] < v){if (i == hi) break;}
	       while (v < a[--j]){if (j == lo) break;}
	       if (i >= j) break;
	       std::swap(a[i], a[j]);
      }
    std::swap(a[lo], a[j]);
    return j;
  }

  template class array<double>;
}
