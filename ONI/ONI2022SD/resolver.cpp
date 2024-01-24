#include <bits/stdc++.h>
#include "avaliador.h"
#define F(i,s,e) for (int i=s; i<e; i++)
using namespace std;

int n, q;

void cabras(int N, int Q) {
  n = N;
  q = Q;
  int k = 1;
  int p=-1, id=-1;
  vector<vector<int> > gs;
  vector<vector<pair<int, int> > > gp;
  vector<int> g(n+1,-1), gm, P(n), S(n), mg(n+1);
  while (k<=n) {
    int x = observacao(k); p++;
    if (g[x] == -1) {
      vector<int> t = {x};id++;
      while(1) {
        t.push_back(observacao(k)); p++;
        g[t[(int)t.size()-1]] = id;
        if (t[(int)t.size()-1] == t[0]) break;
      }
      
      gm.push_back((int)t.size()-1);
      gs.push_back(vector<int>(gm[id]));
      gp.push_back({{k,1}});
      int v = p % gm[id];
      F(i,0,gm[id]) {
        gs[id][v] = t[i];
        mg[t[i]] = v;
        v = (v+1) % gm[id];
      }
    } else {
      int z = (p%gm[g[x]]) - mg[x]; if (z<0) z += gm[g[x]];
      gp[g[x]].push_back({k,z+1});
    }
    k++;
  }
  /*F(i,1,n+1) cout << g[i] << " " << mg[i] << '\n'; 
  F(i,0,id+1) {
    cout << gm[id] << '\n';
    F(j,0,gm[id]) cout << gs[i][j] << " "; 
    cout << '\n';
    F(j,0,gm[id]) cout << gp[i][j].first << " " << gp[i][j].second << '\n'; 
  }*/
  F(i,0,id+1) {
    F(j,1,gm[i]) {
      int fr=0, to=0;
      F(z,0,gm[i]) {
        if (gp[i][z].second == j) fr = gp[i][z].first-1;
        if (gp[i][z].second == j+1) to = gp[i][z].first;
      }
      S[fr] = to;
    }
    int fr=0, to=0;
      F(z,0,gm[i]) {
        if (gp[i][z].second == gm[i]) fr = gp[i][z].first-1;
        if (gp[i][z].second == 1) to = gp[i][z].first;
      }
      S[fr] = to;
  }
  F(i,0,id+1) {
    //cout << i << '\n';
    F(j,0,gm[i]) {
      F(z,0,gm[i]) {
        if (j == 0 && gp[i][z].second == 1) {P[gp[i][z].first-1] =gs[i][j]; /*cout << gp[i][z].first-1 << " " << gs[i][j] << '\n';*/}
        else if (gp[i][z].second == gm[i]-j+1) {P[gp[i][z].first-1] =gs[i][j];/*cout << gp[i][z].first-1 << " " << gs[i][j] << '\n';*/}
      }
    }
  }
  /*F(i,0,n) cout << P[i] << " "; 
  cout << '\n';
  F(i,0,n) cout << S[i] << " ";
  cout << '\n'; */
  resposta(P,S);
}
