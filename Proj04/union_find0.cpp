#include <algorithm> // Needed for the PRNG routines.
#include <chrono>    // Needed for the timing routines.
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;

#include "union_find0.hpp"

Union_Find::Union_Find (unsigned long int N) : num_components(N), id(N) {
  for (Site i = 0; i < N; i++) {
    id[i] = {i};
  }
}

Component Quick_Find::find (const Site &p) {
  return id[p];
}

void Quick_Find::onion (const Site &p, const Site &q) {
  auto p_id = find(p);
  auto q_id = find(q);

  if (p_id == q_id) return;

  for (Site i = 0; i < id.size(); i++) {
    if (id[i] == p_id) id[i] = q_id;
  }
  num_components--;
}

Component Quick_Union::find (const Site &p) {
  Site q = p;
  while (q != id[q]) {
    q = id[q];
  }
  return q;
}

void Quick_Union::onion (const Site &p, const Site &q) {
  auto i = find(p);
  auto j = find(q);

  if (i == j) return;

  id[i] = j;
  num_components--;
}

void Weighted_Quick_Union::onion (const Site &p, const Site &q) {
  auto i = find(p);
  auto j = find(q);

  if (i == j) return;

  if (sz[i] < sz[j]) {
    id[i] = j;
    sz[j] += sz[i];
  }
  else {
    id[j] = i;
    sz[i] += sz[j];
  }

  num_components--;
}

Component Weighted_Quick_Union_with_Path_Compression::find (const Site &p) {
  if (p == id[p]) return p;
  id[p] = find(id[p]);
  return id[p];
}

void test (string title, Union_Find &uf, vector<Site> &p, vector<Site> &q, vector<Site> &r)
{
  auto N = p.size();

  auto t_start = std::chrono::high_resolution_clock::now();
  for (Site i = 0; i < N; i++) {
    uf.onion(p[i], q[i]);
  }
  auto t_end = std::chrono::high_resolution_clock::now();
  cout << "-----------------------------------------------------------\n";
  cout << "Union (" << title << "):\n";
  cout << "  Elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(t_end-t_start).count() <<  "ms\n";

  t_start = std::chrono::high_resolution_clock::now();
  for (Site i = 0; i < N; i++) {
    uf.connected(p[i], q[i]);
    uf.connected(p[i], r[i]);
  }
  t_end = std::chrono::high_resolution_clock::now();
  cout << "Connected (" << title << "):\n";
  cout << "  Elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(t_end-t_start).count() <<  "ms\n";
}

int main (int argc, char **argv) {
  unsigned long int E, V;

  cout << "Enter the number of vertices (sites):    ";
  cin >> V;

  cout << "Enter the number of edges (connections): ";
  cin >> E;

  //  Quick_Find  qf(V);
  //  Quick_Union qu(V);
  Weighted_Quick_Union wqu(V);
  Weighted_Quick_Union_with_Path_Compression wqupc(V);

  vector<Site> p(E), q(E), r(E);

  //---------------------------------------------------------------------------------------------------------
  // Fill p and q with random integers.
  std::mt19937 e(0); // America's favorite pseudo-random number engine: the Mersenne twister.
  std::uniform_int_distribution<unsigned long int> u(0,V-1); // Convert engine output to a uniform integer distribution.
  auto t_start = std::chrono::high_resolution_clock::now();
  for (auto &w : p) w = u(e);
  for (auto &w : q) w = u(e);
  for (auto &w : r) w = u(e);
  auto t_end = std::chrono::high_resolution_clock::now();
  cout << "Initialization:\n";
  cout << "  Elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(t_end-t_start).count() <<  "ms\n";

  //---------------------------------------------------------------------------------------------------------
  // Timing tests.

  // test("Quick find", qf, p, q, r);
  // test("Quick union", qu, p, q, r);
  test("Weighted quick union", wqu, p, q, r);
  test("Weighted quick union with path compression", wqupc, p, q, r);
}
