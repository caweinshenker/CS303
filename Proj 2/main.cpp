#include <iostream>
#include <random>

using std::cout;
using std::endl;
using std::ios_base;

#include "array.hpp"

int main (int argc, char **argv)
{
  cs303::array<double> v(8);

  // Explicit initialization of v.
  std::cout << "v: (size = " << v.size() << ")\n";
  for (long i = 0; i < v.size(); i++) {
    v[i] = (i + 0.25);
  }
  std::cout << v << endl;

  // Copy constructor initialization of w.
  cs303::array<double> w(v);
  std::cout << "w: (size = " << w.size() << ")\n";
  std::cout << w << endl;

  // List initializtion of u.
  // cs303::array<double> u {1, 2, 3, 4, 5};
  // std::cout << "u: (size = " << u.size() << ")\n";
  // std::cout << u << endl;

  std::mt19937 e(42);
  std::normal_distribution<> pdf(0,1); // Mean 0, standard deviation 1 normal distribution.
  for (int i = 0; i < v.size(); i++) {
    v[i] = pdf(e);
  }

  cout.precision(12);  // Set the output precision. (p. 1082)
  cout.setf(ios_base::showpos);   // Print a + sign for positive numbers (p. 1086)
  cout.setf(ios_base::fixed);     // Set the format to fixed-point.
  std::cout << "Before sorting--------------------\n";
  std::cout << "v: (size = " << v.size() << ")\n";
  std::cout << v << endl;

  v.quicksort();
  std::cout << "After sorting--------------------\n";
  std::cout << "v: (size = " << v.size() << ")\n";
  std::cout << v << endl;

  return 0;
}
