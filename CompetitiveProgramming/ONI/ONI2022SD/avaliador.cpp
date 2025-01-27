#include <stdio.h>
#include <algorithm>
#include "avaliador.h"

int correto = 0;
int N, Q;
int contador;
int curr[MAX_N + 5];
int tmp[MAX_N + 5];
int P[MAX_N + 5];
int S[MAX_N + 5];

void end(int type = 0)
{
  if (correto)
    printf("Correto!\n");
  else
  {
    if (type == 0)
      printf("Incorreto, excedeste o numero de chamadas por intervalo, %d/%d\n", contador, Q);
    else if (type == 1)
      printf("Incorreto, resposta final incorreta...\n");
    else if (type == 2)
      printf("Incorreto, chamada invalida...\n");
    else
      printf("Incorreto, input invalido...\n");
  }
  exit(0);
}

int observacao(int i) {
  if (i < 1 || i > N)
    end(2);
  i--;

  contador++;
  if (contador > Q)
    end(0);
  
  int res = curr[i] + 1;

  for (int i = 0; i < N; i++)
    tmp[S[i]] = curr[i];
  for (int i = 0; i < N; i++)
    curr[i] = tmp[i];

  return res;
}

void resposta(vector<int> Pres, vector<int> Sres) {
  if (int(Pres.size()) != N || int(Sres.size()) != N)
    end(2);

  for (int i = 0; i < N; i++)
    if (Pres[i] - 1 != P[i] || Sres[i] - 1 != S[i]) {
      end(1);
    }
  correto = 1;
  end();
}

int main()
{
  scanf("%d %d", &N, &Q);

  if (N < 1 || N > MAX_N)
    end(5);

  for (int i = 0; i < N; i++) {
    scanf("%d", &P[i]);
    P[i]--;
    curr[i] = P[i];
  }

  for (int i = 0; i < N; i++) {
    scanf("%d", &S[i]);
    S[i]--;
  }

  contador = 0;
  cabras(N, Q);
  end(1);

  return 0;
}
