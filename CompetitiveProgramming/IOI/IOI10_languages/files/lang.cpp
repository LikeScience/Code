#include <bits/stdc++.h>
#include "lang.h" 
#include "grader.h"
#define F(i,s,e) for (int i = s; i<e; i++)
#define fi first
#define se second
using namespace std;

int n = 56, t = 10000, sn = 65535; bool isf=1; /*int cnt = 0*/;
vector<vector<double> > l;
vector<double> v;

double absv(double x) {return (x >= 0 ? x : -x);}

void excerpt(int *E) {
    //cnt++;
    if (isf) {
        random_device rd;
        l.assign(n, vector<double>(sn, 0));
        v.assign(n, 0);
        int g = language(rd()%n);
        isf = 0;
        v[g]++;
        F(i,0,100) l[g][E[i]]++;
        return;
    }
    int lc=-1, ms=1000000000;
    map<int, int> m;
    F(i, 0, 100) m[E[i]]++;
    F(i,0,n) if (v[i]>0) {
    double s = 100, df = 0;
    for (auto it : m) {
        s -= l[i][it.fi]/v[i];
        df+= absv(l[i][it.fi]/v[i]-it.se);
    }
    df += s;
    if (df < ms) {
        ms = df;
        lc = i;
    }
    }
    //if (cnt == t) F(i,0,56) F(j,0,sn) cout << l[i][j] << " \n"[j==sn-1];
    int g = language(lc);  
    v[g]++;
    F(i,0,100) l[g][E[i]]++;
}

