#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "avaliador.h"

int n, q, k, id, step;
int ans_arr[MAXQ];

void end(int type = 0) {
  if (type == 0)
    cout << "Incorreto, usaste perguntas a mais..." << endl;
  else if (type == 1)
    cout << "Incorreto, input invalido..." << endl;
  else if (type == 2)
    cout << "Incorreto, pergunta fora dos limites..." << endl;
  else if (type == 3)
    cout << "Incorreto, devolveste a resposta errada ..." << endl;
  else
    cout << "Correto! Usaste " << step << " perguntas." << endl;
  exit(0);
}

int eval(int res) {
  return res == id;
}

int pergunta(int temp) {
  step++;
  if (step > q)
    end(0);

  if (temp < 1 || temp > n)
    end(2);

  if (temp < id)
    ans_arr[step - 1] = 1;
  else if (temp > id)
    ans_arr[step - 1] = -1;
  else
    ans_arr[step - 1] = 0;
  
  if (step - k - 1 >= 0)
    return ans_arr[step - k - 1];
  return -2;
}

int main() {
  cin >> n >> k >> q >> id;
  if (n < 1 || n > MAXN)
    end(1);

  if (id < 1 || id > n)
    end(1);

  if (k < 1 || k > MAXK)
    end(1);

  step = 0;
  if (eval(resolver(n, k, q)))
    end(4);
  else
    end(3);

  return 0;
}
