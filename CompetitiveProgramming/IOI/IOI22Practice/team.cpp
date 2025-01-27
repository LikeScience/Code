#include "team.h"
#include <vector>
#include <algorithm>

using namespace std;

int maximum_teams(int N, int K, std::vector<int> L) {
  sort(L.begin(), L.end());
  vector<int>::iterator lit = L.begin(), rit = L.end(), f; rit--;
  int cnt = 0, l = 0, r = N-1, t, id;
  while(r - l + 1 >= 3) {
    t = K - L[r] + 1;
    f = lower_bound(lit,rit,t);
    id = f - L.begin();
    if (r - id <= 1) break;
    cnt++;
    l = id + 2; lit = f; lit++; lit++;
    r--; rit--;
  }
  return cnt;
}
