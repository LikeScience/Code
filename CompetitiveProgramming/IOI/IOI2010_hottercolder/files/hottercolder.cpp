#include "grader.h"
//#include <iostream>

using namespace std;

int HC(int N) {
    int l = 1, r = N, g, lc; //lc = 0 if last is left, 1 if right.
    g = Guess(N);
    lc = 1;
    //int cnt = 0;
    while(1) {
       /* if (cnt < 25) {
            cnt++; cout << l << " " << r << endl;
        }*/
        if (!lc) {
            g = Guess(r);
            if (!g) {
                return (l + r)/2;
            }
            else if (g == 1) {
                l = (l+r+2)/2;
                lc = 1;
            }
            else if (g == -1) {
                g = Guess(l);
                r = (l+r-1)/2;
                lc = 0;
            }
            if (l==r) return l;
        }
        else {
            g = Guess(l);
            if (!g) {
                return (l + r)/2;
            }
            else if (g == 1) {
                r = (l+r-1)/2;
                lc = 0;
            }
            else if (g == -1) {
                g = Guess(r);
                l = (l+r+2)/2;
                lc = 1;
            }
            if (l==r) return l;
        }
    }
}