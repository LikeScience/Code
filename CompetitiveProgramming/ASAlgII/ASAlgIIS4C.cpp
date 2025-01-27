#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i != e; i++) //Isto e para escrever mais rapido o for
#define f first //Isto serve para escrever mais rapido os pairs (posso escrever p.f em vez de p.first)
#define s second //Igual ao de cima
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int l, g, x, r, c, z;
    bool b;
    
    cin >> l >> g; 
    while (l || g) {
        c=0; b=1;
        vector<pair<int, int> > v; 
        F(i,0,g) {
            cin >> x >> r; 
            v.push_back({(x-r<0) ? 0 : x-r, (x+r>l) ? l : x+r}); //Adicao dos pares (inicio; fim) das bombas de gasolina
            v.push_back({(x+r>l) ? l : x+r, 1000000000}); //Adicao de pares (fim; numero grande qualquer) das bombas de gasolina
        }
        sort(v.begin(), v.end());
        //F(i,0,2*g) cout << v[i].f << " " << v[i].s << '\n'; - Isto podes ignroar, era so para debugging
        if (v[0].f) { //Caso em que a primeira estacao nao comeca no 0
            cout << "-1\n";
            cin >> l >> g; 
            if (!l && !g) break;
            continue;
        }
        x=v[0].s; r = -1; z = 1;//O z e o numero da estacao a considerar para determinar a maior inicialmente (o teu c)
        while (v[z].f==0) {
            if (v[z].s>x) x = v[z].s;
            z++;
        }
        F(i,z,2*g) {
            if (v[i].f == l) break; //Eu tenho no vector tambem um par em que v[i].f e o fim, logo isto verifica se chegamos ao final (se for possivel, entao existe uma bomba que termina aqui)
            if (v[i].s == 1000000000) { //Se estamos a  considerar o final de uma bomba
                if (v[i].f == x) { //Se essa bomba termina no mesmo sitio da nossa "bomba atual"
                    if (r == -1  || r <= x) { //Se nao encontramos nenhuma bomba que comece antes do final da bomba atual e acabe depois desse final, entao e impossivel
                        b=0;
                        break;
                    }
                    c++; //Se nao, entao chegamos ao final da nossa bomba e adicionamos 1 as utilizadas, e trocamos o final da bomba atual para o final da bomba que chega mais longe que tinhamos encontrado ate agora
                    x = r;
                    r = -1;
                }
            } else if (v[i].s > r) r = v[i].s;  //Se estamos a considerar o principio de uma bomba, como ainda nao chegamos ao final da bomba atual, vemos se esta e uma boa candidata para bomba seguinte (se e a que nos permite chegar mais longe)
        }
        if(v[2*g-1].f == l) { // Se a ultima bomba termina em l, chegamos ao final e falta contar 1 bomba; senao e impossivel.
            c++;
        } else b = 0;
        cout << (b ? g-c : -1) << '\n';
        cin >> l >> g; 
    }
}