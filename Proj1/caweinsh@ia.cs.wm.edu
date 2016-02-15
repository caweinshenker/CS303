#include <string> // The string class: pg 131
#include <vector> // The vector class: pg 1012
#include <stdio.h>

// The standard namespace (std::): pg 59
using std::string;
using std::vector;
using std::min;


#include "sort.hpp"


template <typename T>
void merge(vector<T>&a, vector<T>&aux, int lo, int mid, int hi){
  int i = lo;
 int  j = mid + 1;
  for (int k = lo; k <= hi; k++){
    aux[k] = a[k];
  }

  for (int k = lo; k <= hi; k ++){
    if (i > mid) {a[k] = aux[j++];}
    else if (j > hi) {a[k] = aux[i++];}
      else if (aux[j] < aux[i]) {a[k] = aux[j++];}
      else {a[k] = aux[i++];}
    }
}

template <typename T>
void recursive_mergesort_aux(vector<T>&a, vector<T>&aux,  int  lo, int  hi) {
  if (hi <= lo) return;
   int  mid =  lo + (hi - lo) / 2;
  recursive_mergesort_aux(a, aux,  lo, mid);
  recursive_mergesort_aux(a, aux,  mid + 1, hi);
  merge(a, aux, lo, mid, hi);
}

template <typename T> // template, typename: pg 419
void recursive_mergesort (vector<T> &a) { // vector: pg 1012; & (reference): pg 383
  int mylen = a.size();
  vector<T> aux(mylen);
  int lo(0);
  int hi(mylen - 1);
  recursive_mergesort_aux(a, aux, lo, hi);
}

template <typename T> // template, typename: pg 419
void iterative_mergesort (vector<T> &a) {
  int N = a.size();
 vector<T> aux(N);
  for (int sz = 1; sz <  N; sz = sz + sz) {
    for (int lo = 0; lo < a.size() - sz; lo += sz + sz) {
      merge(a, aux, lo, lo + sz - 1,min(lo + sz + sz - 1, N -1));
    }
  }
}


template void recursive_mergesort<int>(vector<int>&);
template void recursive_mergesort<double>(vector<double>&);
template void recursive_mergesort<string>(vector<string>&);

template void iterative_mergesort<int>(vector<int>&);
template void iterative_mergesort<double>(vector<double>&);
template void iterative_mergesort<string>(vector<string>&);

template void recursive_mergesort_aux<int>(vector<int>&, vector<int>&, int, int);
template void recursive_mergesort_aux<double>(vector<double>&, vector<double>&, int, int);
template void recursive_mergesort_aux<string>(vector<string>&, vector<string>&, int, int);

template void merge<int>(vector<int>&, vector<int>&, int, int, int);
template void merge<double>(vector<double>&, vector<double>&, int, int, int);
template void merge<string>(vector<string>&, vector<string>&, int, int, int);
