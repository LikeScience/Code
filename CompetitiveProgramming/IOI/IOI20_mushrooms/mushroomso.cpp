#include <bits/stdc++.h>
#include "mushrooms.h"
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int count_mushrooms(int n) {
    vector<bool> v(n,0); vector<int> a, b; int c=1, d;
    int i = 0;
    while (i+2<n) {
        d = use_machine({i,i+1,i+2});
        if (d == 0) {
            v[i+2] = v[i];
            if (!v[i]) c+=2;
        } else if (d==1) {
            v[i+2] = !v[i];
            if (!v[i]) {
                a.push_back(i);
                a.push_back(i+1);
            } else {
                c++;
                b.push_back(i);
                b.push_back(i+1);
            }
        } else {
            v[i+2] = v[i];
            c++;
        }
        i+=2;
    } if (i == n-2) {
        d = use_machine({n-2,n-1});
        if ((!v[n-2] && !d) || (v[n-2] && d)) c++;
    }
    if ((int)a.size()>=2) {
        d = use_machine(a);
        c += (int)a.size()/2 - (d+1)/2;
    } if ((int)b.size()>=2) {
        d = use_machine(b);
        c += (d+1)/2;
    }
    return c;
}