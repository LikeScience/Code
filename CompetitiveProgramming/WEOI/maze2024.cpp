#include <bits/stdc++.h>
#include "maze2024.h"
#define F(i,s,e) for (int i = s; i<e; i++)
#define ll long long
using namespace std;

vector<vector<char> > solve(ll k) {
    int maxsz = min(5*3*int(log2(double(k))+1)/4,200);
    vector<vector<char> > v(maxsz, vector<char>(maxsz, '#'));
    F(i,0,maxsz) v[maxsz-1][i]= v[i][maxsz-1] = '.';
    v[0][0] = '.';
    ll x = (ll)(1) << 59;
    bool b = 0, f=1; int sy0 = 0, sx1=6;
    for (int e = 59; e>=0; e--) {
        if (k&x) {
            if (!b) {
                if (f) {f = 0;}
                else v[sy0-3][0] = v[sy0-2][0] =v[sy0-1][0] = v[sy0][0] = '.';
                int curx = 0, cury = sy0; 
                F(i,0,e) {
                  v[cury+1][curx] = v[cury+2][curx] = v[cury+2][curx+1] = v[cury][curx+1] =   v[cury][curx+2] = v[cury+1][curx+2] = v[cury+2][curx+2] = '.';
                  curx+=2; cury+=2;
                }
                F(i,cury+1,maxsz-1) v[i][curx]='.';
                sy0+=6; 
            } else {
                v[0][sx1-3] = v[0][sx1-2] =v[0][sx1-1] = v[0][sx1] = '.';
                int curx = sx1, cury = 0; 
                F(i,0,e) {
                  v[cury+1][curx] = v[cury+2][curx] = v[cury+2][curx+1] = v[cury][curx+1] =   v[cury][curx+2] = v[cury+1][curx+2] = v[cury+2][curx+2] = '.';
                  curx+=2; cury+=2;
                }
                F(i,curx+1,maxsz-1) v[cury][i]='.';
                sx1+=6; 
            }
            b = !b;
        }
        x >>= 1;
    }
    return v;
}