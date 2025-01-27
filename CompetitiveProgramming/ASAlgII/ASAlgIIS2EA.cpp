#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL); //Esta parte não interessa muito (torna mais eficiente o input/output)
    int n, m, x, d;
    cin >> n >> m;
    if (n >= m) { //caso n > m ou n == m
        cout << n-m << '\n';
    } else { //caso n < m
    vector<int> v(2*m,0);   //guarda os números visitados de 1 a 2m-1 (ingorando o 0)
                            //não é preciso 2m ou acima porque nós só vamos multiplicar por 2 números até m
    queue<pair<int, int> > q;   //guarda o número e a distância em termos de num de operações
    q.push({n,0});
    v[n] = 1;
    while(!q.empty()) {
        x = q.front().first;
        d = q.front().second;
        q.pop();
        if (x == m) {
            cout << d << '\n';
            break;
        }
        if (x-1 > 0 && !v[x-1] ) {
            v[x-1] = 1;
            q.push({x-1, d+1});
        }
        if (x < m && !v[2*x]) {
            v[2*x] = 1;
            q.push({2*x, d+1});
        }
    }
    }
}