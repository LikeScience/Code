#include "ancient2.h"
#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;
#define F(i,s,e) for (int i = s; i<e; i++)

namespace {

int variable_example = 1;

}  // namespace

std::string Solve(int N) {
  string s(N, '0');
  F(i,0,N) {
  int m = i+1;
  std::vector<int> a(m+2), b(m+2);
  F(j,0,m-1) {
    a[j] = j+1;
    b[j] = j+1;
  }
  a[m-1] = m;
  b[m-1] = m+1;
  a[m] = b[m] = m;
  a[m+1] = b[m+1] = m+1;
  s[i] = "01"[Query(m+2, a, b) == m+1];
  
  }
  //cout << s << '\n';
  return s;
}
