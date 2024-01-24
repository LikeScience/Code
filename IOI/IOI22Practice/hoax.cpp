#include "hoax.h"
#include <utility>
#include <algorithm>
#include <deque>
#include <vector>
//#include <iostream>

using namespace std;

vector<int> cccp;

void init(int N, int S, std::vector<int> T,
          std::vector<std::vector<int>> A, std::vector<std::vector<int>> B) {
  vector<pair<int, pair<int, int> > > v; //(time, (start 0/end1, idx))
  for (int i = 0; i< N; i++) {
    for (int j = 0; j<T[i]; j++) {
      v.push_back(make_pair(A[i][j], make_pair(0,i)));
      v.push_back(make_pair(B[i][j], make_pair(1,i)));
    }
  }
  sort(v.begin(), v.end());
  int gp = 0, id, on = 0;
  vector<vector<int> > gps(N), gpl(1);
  for (int i = 0; i < (int)v.size(); i++) {
    //cout << v[i].first << " " << v[i].second.first << " " << v[i].second.second << '\n';
    id = v[i].second.second;
    if (!v[i].second.first) {
      if (!on) {
        gp++;
        gpl.push_back({});
      }
      on++;
      gps[id].push_back(gp);
      gpl[gp].push_back(id);
    } else {
      on--;
    }
  }

  /*for (int i = 0; i < N; i++) {
    cout << '\n' << i << ": ";
    for (int j = 0; j < (int)gps[i].size(); j++){
      cout << gps[i][j] << " ";
    }

  }
  cout << "\n";*/
  int ccc= -1;
  vector<int> CCs; vector<int> CC(N), vis(N,0), gis(gp+1,0);
  for (int i = 1; i <= gp; i++) {
    if (!gis[i]) {
      ccc++;
      CCs.push_back(0);
      deque<int> d; d.push_back(i);
      while((int)d.size()>0) {
        
      id = *d.begin();
      //cout << id << " " << ccc << '\n';
      gis[id] = 1;
      for (int j= 0; j < (int)gpl[id].size(); j++) {
        if (!vis[gpl[id][j]]) {
          //cout << "i" << gpl[id][j] << " " << ccc << '\n';
        CC[gpl[id][j]] = ccc;
        CCs[ccc]++;
        vis[gpl[id][j]]=1;
        for (int k = 0; k < (int)gps[gpl[id][j]].size(); k++) {
          if (!gis[gps[gpl[id][j]][k]]) d.push_back(gps[gpl[id][j]][k]);
        }
        }
      }
      d.pop_front();
      }
    }
  }
  for (int i = 0; i < N; i++) {
    cccp.push_back(CCs[CC[i]]);
  }
  return;
}

int count_users(int P) {
  return cccp[P];
}
