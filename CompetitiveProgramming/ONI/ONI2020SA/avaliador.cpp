#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "avaliador.h"

bool correct = false;
int n, q, contador, alpha;
int sigma[MAXN], ori[MAXN], found[MAXN];

void end(int type = 0) {
  if (correct)
    cout << "Correto! Usaste " << contador << " perguntas." << endl;
  else {
    if (type == 0)
      cout << "Incorreto, usaste perguntas a mais..." << endl;
    else if (type == 1)
      cout << "Incorreto, input invalido..." << endl;
    else if (type == 2)
      cout << "Incorreto, pergunta fora dos limites..." << endl;
    else
      cout << "Incorreto, devolveste a resposta errada ..." << endl;
  }
  exit(0);
}

int inv() {
  int ans = 0;
  for (int i = 1; i < n; i++)
    for (int j = 0; j < i; j++)
      if (sigma[i] < sigma[j])
        ans++;
  return ans;
}

void resposta(int pi[MAXN]) {
  for (int i = 0; i < n; i++)
    if (pi[i] != ori[i])
      end(3);
  correct = true;
  end();
}

int pergunta(int a, int b) {
  contador++;
  if (contador >= q)
    end();

  if (a < 1 || a > n || b < 1 || b > n)
    end(2);

  swap(sigma[a - 1], sigma[b - 1]);
  return inv();
}

int main() {
  cin >> n >> alpha;
  q = alpha * n;

  if (n < 1 || n > MAXN)
    end(1);

  for (int i = 0; i < n; i++)
    cin >> sigma[i];

  for (int i = 0; i < n; i++)
    if (sigma[i] < 1 || sigma[i] > n)
      end(1);

  memset(found, 0, sizeof found);
  for (int i = 0; i < n; i++) {
    if (found[sigma[i]])
      end(1);
    found[sigma[i]] = 1;
  }

  for (int i = 0; i < n; i++)
    ori[i] = sigma[i];

  resolver(n, inv());
  end(3);

  return 0;
}
