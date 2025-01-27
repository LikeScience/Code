#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int main() {
    fstream fin("avin.in", fstream::in);
    int n, m, k, z; double t; fin >> n >> m >> k >> t;
    vector<vector<int> > v(k, vector<int>(m)), f(n);
    vector<bool> b(n, 1);
    vector<int> s(n, 0);
    F(i,0,k) F(j,0,m){
        int z; fin >> z;
        if (j==0) {f[z].push_back(i); s[z]++;}
        v[i][j] = z;
    }  
    F(i,0,n) {
        int mx = 0, mi;
        F(j, 0, n) {
            if (s[j] > mx) {
                mx = s[j];
                mi = j;
            }
        }
        //F(l,0,n) cout << s[l] << " \n"[l==n-1];
        if (double(mx)/double(k) > t) {
            cout << mi << '\n';
            F(l,0,n) cout << s[l] << " \n"[l==n-1];
            cout << i << ' ' << double(mx)/double(k) << '\n';
            //F(i,0,(int)f[mi].size()) cout << f[mi][i] << '\n';
            break;
        }
        int mn = 10000;
        F(j, 0, n) {
            if (s[j] < mn && s[j] != -1) {
                mn = s[j];
                mi = j;
            }
        }
        b[mi] =0; s[mi]=-1;
        for (int j : f[mi]) {
            int bb= 1;
            F(x,1,m) if (v[j][x] != -1 && b[v[j][x]]) {
                s[v[j][x]]++;
                f[v[j][x]].push_back(j);
                bb=0;
                break;
            } 
            if (bb) k--; 
        }
    }

}