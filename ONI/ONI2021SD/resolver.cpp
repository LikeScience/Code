/*
  Modifica este ficheiro para fazer a tua solucao do Problema D.

  Nao modifiques mais nenhum ficheiro.
*/

#include "avaliador.h"
#include<bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
int ans[MAXQ];

int resolver(int n, int k, int q) {
  random_device rd;
  vector<int> p;
  int l = 1, r = n, a = 2*n, x = n;
  F(i,0,q) {
    if (x+a>r) {
      a/=2;
      x = l + a/2;
    } else if (x+a < l) {
      x = l + a/2;
      
    } else x += a;
    if (k != 1) if (x > r) {
      x = (l+r)/2;
      a = (r-l)/2;
    }
    if (k == 1) {
      while (x > r) {
        a/=2;
        x = l + a/2;
      }
    }
    p.push_back(x);
    int z = pergunta(x);
    if (z == 1) {
      l = max(l, p[i-k]+1);
    } else if (z == 0) {
      return p[i-k];
    } else if (z == -1){
      r = min(r, p[i-k]-1);
    }

    if (l == r) return l;
  }  
  return -1;
}
