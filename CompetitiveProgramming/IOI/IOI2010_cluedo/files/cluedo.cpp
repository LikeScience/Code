#include "grader.h"

using namespace std;

void Solve() {
    int k, M=1, L=1, W=1;
    while(M >= 1) {
        k = Theory(M,L,W);
        if (k == 0) return;
        if (k == 1) {
            M++;
        } else if (k==2) {
            L++;
        } else if (k == 3) {
            W++;
        }
    }
};
