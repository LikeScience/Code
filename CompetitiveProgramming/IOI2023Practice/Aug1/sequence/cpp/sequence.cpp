#include "sequence.h"
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define F(i,s,e) for (int i = s; i<e; i++)
#define fi first
#define se second
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> pbds;


int sequence(int N, std::vector<int> A) {
  int t = 0;
  F(l,0,N) {
    map<int, int> m;
    pbds s;
    F(r,l,N) {
      if (m.find(A[r]) == m.end()) {m[A[r]] = 1;}
      else m[A[r]]++;
      s.insert({A[r], r});
      if (((r-l)%2) == 0) {
        int x = s.find_by_order((r-l)/2)->fi;
        t = max(t, m[x]);
        //if (l == 1) cout << l << " " << x << " " << m[x] << " " << '\n';
        //if (m[x] == 19) cout << l << " " << r <<" " << x << '\n';
      } else {
        int x = s.find_by_order((r-l)/2)->fi, y = s.find_by_order((r-l)/2+1)->fi;
        t = max(t, m[x]);
        t = max(t, m[y]);
        //if (m[x] == 19) cout << l << " " << r << " " << x << '\n'; 
        //if (m[y] == 19) cout << l << " " << r << " " << y << '\n'; 
      }
    }
    m.clear();
    s.clear();
  }
  return t;
}
