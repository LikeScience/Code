#include "dna.h"
#include <vector>
#include <string>

using namespace std;

vector<int> aca, cca, tca, acb, ccb, tcb, ainc, cina, aint, tina, cint, tinc;

int mn (int m, int n) {
    return ((m < n) ? m : n);
}
int mx (int m, int x) {
    return ((m > x) ? m : x);
}

void init(std::string a, std::string b) {
    int n = (int)a.length();
    aca.push_back(0); cca.push_back(0); tca.push_back(0);
    acb.push_back(0); ccb.push_back(0); tcb.push_back(0);
    aint.push_back(0); tinc.push_back(0); cina.push_back(0);
    tina.push_back(0); ainc.push_back(0); cint.push_back(0);
    for (int i = 0; i < n; i++) {
        aca.push_back(aca[i]); cca.push_back(cca[i]); tca.push_back(tca[i]);
        acb.push_back(acb[i]); ccb.push_back(ccb[i]); tcb.push_back(tcb[i]);
        aint.push_back(aint[i]); tinc.push_back(tinc[i]); cina.push_back(cina[i]);
        tina.push_back(tina[i]); ainc.push_back(ainc[i]); cint.push_back(cint[i]);
        if (a[i] == 'A') {
            aca[i+1]++;
            if (b[i] == 'C') {
                cina[i+1]++;
                ccb[i+1]++;
            }
            else if (b[i] == 'T') {
                tina[i+1]++;
                tcb[i+1]++;
            } else {acb[i+1]++;}
        }
        else if (a[i] == 'C') {
            cca[i+1]++;
            if (b[i] == 'A') {
                ainc[i+1]++;
                acb[i+1]++;
            }
            else if (b[i] == 'T') {
                tinc[i+1]++;
                tcb[i+1]++;
            } else {ccb[i+1]++;}
        } else if (a[i] == 'T') {
            tca[i+1]++;
            if (b[i] == 'A') {
                aint[i+1]++;
                acb[i+1]++;
            }
            else if (b[i] == 'C') {
                cint[i+1]++;
                ccb[i+1]++;
            } else {tcb[i+1]++;}
        }
    }
    return;
}

int get_distance(int x, int y) {
    x++; y++;
    if (((acb[y]-acb[x-1] == aca[y]-aca[x-1]) && (ccb[y]-ccb[x-1] == cca[y]-cca[x-1])) && (tcb[y]-tcb[x-1] == tca[y]-tca[x-1])) {
        int n1 = mn(aint[y]-aint[x-1], tina[y]-tina[x-1]), n2 = mn(ainc[y]-ainc[x-1], cina[y]-cina[x-1]), n3 = mn(cint[y]-cint[x-1], tinc[y]-tinc[x-1]);
        int x1 = mx(aint[y]-aint[x-1], tina[y]-tina[x-1]);
        return n1 + n2 + n3 + 2*(x1-n1);
    } else return -1;
}