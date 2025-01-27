#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i != e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int m , n, x;
    string s;
    cin >> n >> m;
    vector<int> c(m);
    vector<vector<int> > an(n), am(n);
    F(i,0,m) cin >> c[i];
    F(i,0,n) {
        getline(cin,s);
        stringstream ss (s);
        while (ss > x) {
            an[i].push_back(x);
        }
    }
    F(i,0,m) {
        getline(cin,s);
        stringstream ss (s);
        while (ss > x) {
            am[i].push_back(x);
        }
    } x = 0;
    int cn = 0, cm = 0;
    vector<set<int> > rn(n), rm(m);
    vector<int> dn(n,0), dm(m,0);
    while (cn < n && cm < m) {
        F(i,0,n) {
            if (rn)
        }
    }
     

}
