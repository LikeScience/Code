#include "gralib.hpp"
#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
using namespace std;

int main() {
    
    F(z,0,100) {
        int n = dajN(), k = dajK(), m = dajM();
        int x = 0, y;
        while(1) {
            y = nastepna();
            if (k > n-x) {
                if (y == n-x) {
                    zwieksz();
                    break;
                }
            }
            else {
                if (y == k) {
                    zwieksz();
                    x += y;
                    if (x == n) break;
                }
            }
            //cout << y << " ";
        } //cout << '\n';
        koniec();
    }

    
}
