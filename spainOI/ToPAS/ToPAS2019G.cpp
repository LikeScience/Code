#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define F(i,s,e) for(long long i = s; i < e; i++)

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int E, S, D, B, V, id, t, p, r, K, ki, mn = 2000000000; 
    cin >> E >> S >> D >> B >> V;

    vector<int> solv(E+1,0), lsub(E+1, 0);
    vector<int> time(E+1,0); //inclui penalizações, porque se alguma equipa tiver problemas nao resolvidos nao ganha; nas equipas que
                             //resolveram todos estao sempre todas as penalizacoes.
    
    for (int i = 0; i < S; i++) {
        cin >> id >> t >> p >> r;
        if (r) {
            time[id] += t;
            solv[id]++;
        } else time[id] += 1200;
    lsub[id] = t;
    }

    for (int j = 1; j <= E; j++) {

        if (j == V) {
            cin >> K;
            time[V] += (K-1)*1200;
            for (int i = 0; i <K; i++) {
                cin >> ki;
                if (i == K-1) time[V] += ki;
            }
            if (time[V] < mn) mn = time[V];

        } else {

            int bs, dur, Ttime;
            bs = ((lsub[j]+D) > B) ? (lsub[j]+D) : B;
            dur = 14400 - bs;
            if (solv[j] + 1 + dur/D >= 7 ) {
                Ttime = time[j] + (7-solv[j]) * bs + D * (7-solv[j]) * (7-solv[j] -1) / 2 ;
            }
            if (Ttime<mn) mn = Ttime;
        }
    }

    if (time[V] <= mn) {
        cout << "Vencemos" << '\n';
    } else cout << "Nao sabemos" << '\n';
}
