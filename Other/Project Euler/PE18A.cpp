#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i != e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    ifstream ci ("triangle.txt", ifstream::in);
    int n, a, m=0; cin >> n;
    vector<vector<int> > v(n), d(n);
    F(i,0,n) F(j,0,i+1) {
        ci >> a;
        v[i].push_back(a);
        d[i].push_back(0);
    } 
    d[0][0]=v[0][0];
    F(i,0,n-1) F(j,0,i+1) {
        d[i+1][j] = max(d[i+1][j], d[i][j]+v[i+1][j]);
        d[i+1][j+1] = max(d[i+1][j+1], d[i][j]+v[i+1][j+1]);
    }
    F(i,0,n) {
        if(d[n-1][i] > m) m = d[n-1][i];
    }
    cout << m << '\n';
}