#include "avaliador.h"
#include <vector>
#include <iostream>

using namespace std;

int _N, _IS;
int permutacao[MAXN];


void resolver(int n, int is)
{
  _N = n;
  _IS = is;
  int f = 1, mn;
  vector<int> v(n);
  //case i = N
  int x = pergunta(1, n), y, d = x - is;
  f = n;
  v[n-1] = d; mn = d;
  cout << d << endl;
  //other i s
  for (int i = n-1; i >= 2; i--) {
    if (f == n) {
      y = pergunta(1, i);
      y = pergunta(1, n);
      d = 0 - (y - x); 
      v[i-1] = d; if (d < mn) mn = d;
      f = 1;
      x = y;
      cout << d << endl;
    } else if (f == 1) {
      y = pergunta(i, n);
      y = pergunta(1, n);
      d = y - x;
      v[i-1] = d; if (d < mn) mn = d;
      f = n;
      x = y;
      cout << x << endl;
    }
  }
  if (mn >0) {y = 1;} 
  else y = 1 - mn;
  for (int i = 0; i < n; i++) {
    permutacao[i] = v[i] + y;
    cout << permutacao[i] << endl;
  }
  resposta(permutacao);
  return;
}
