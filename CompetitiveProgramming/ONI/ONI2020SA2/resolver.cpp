#include <bits/stdc++.h>
#include "avaliador.h"
#define F(i,s,e) for (int i =s; i<e; i++)

int _N, _IS;
int p[MAXN];

void resolver(int n, int is)
{
  _N = n;
  _IS = is;
  int sc =0;
  if (n==1) {
    p[0]=1;
    resposta(p);
  }
  vector<int> dif(n+1);
  int s = 1, x = n;
  F(i,0,n-1) {
    if ((i%2) == 0) {
      int t = pergunta(s,x);
      int v = (t-is+((t>is) ? 1 : -1))/2;
      if (t<is) sc++;
      dif[x] = v;
      is = t;
      int tmp = s; s = x; x = tmp+1;
    } else {
      int t = pergunta(x,s);
      int v = (t-is+((t>is) ? 1 : -1))/2;
      if (t>is) sc++;
      dif[x] = -v;
      is = t;
      int tmp = s; s = x; x = tmp-1;
    }
  }
  //F(i,1,n+1) cout << dif[i] << '\n';
  vector<bool> b(n+1, 0);
  b[sc+1]=1;

  p[0] = sc+1; s=1; x=n;
  //cout << p[0] << '\n';
  F(i,0,n-1) {
    int c = 0;
    if (dif[x]>0) {
      for (int j=p[0];c < dif[x]; j++) {
        if (!b[j]) c++;
        if (c==dif[x]) {
          p[x-1] = j;
          b[j]=1;
        }
      }
    } else {
      for (int j=p[0];c > dif[x]; j--) {
        if (!b[j]) c--;
        if (c==dif[x])  {
          p[x-1] = j;
          b[j]=1;
        }
      }
    }
    

    if ((i%2) == 0) {
      int tmp = s; s = x; x = tmp+1;
    } else {
      int tmp = s; s = x; x = tmp-1;
    }
  }
//F(i,0,n) cout << p[i] << '\n';
  resposta(p);
}
