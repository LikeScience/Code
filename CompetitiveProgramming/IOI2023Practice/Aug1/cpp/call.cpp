#include "floppy.h"
#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int main() {
    string s;
    cin >> s;
    int z, n, m;
    
    cin >> z >> n >> m;
    vector<int> a(m), b(m), r(m), x;
    F(i,0,n) cin >> z;
    F(i,0,m) cin >> a[i] >> b[i] >> r[i];
    x = solve_queries(3, n, s, a, b);
    F(i,0,m) cout << x[i] << '\n';
}