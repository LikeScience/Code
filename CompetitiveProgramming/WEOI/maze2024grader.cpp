#include <bits/stdc++.h>
#include "maze2024.h"
#define F(i,s,e) for (int i = s; i<e; i++)
#define ll long long
using namespace std;

int main() {
    int t = 60, c, l; ll mn = 1, mx = 1e18, k;
    random_device rd;
    F(z,0,t) {
        //k = mn+(rd()%(mx-mn));
        //k = ((ll)(1) <<z) +rd()%(((ll)(1)<<z));
        k = ((ll)(1) <<(z+1))-1;
        vector<vector<char> > a = solve(k);
        l = a.size(), c = a[0].size();
        F(i,0,l) {F(j,0,c) cout << a[i][j]; cout << "\n";}
        vector<vector<ll> > v(l, vector<ll>(c,0)); v[0][0] = 1;
        if (a[0][0] != '.' || a[l-1][c-1] !='.') {cout << "WRONG\n"; continue;}
        queue<pair<int, int > > q;
        q.push(make_pair(0,0));
        while (!q.empty()) {
            int y = q.front().first, x = q.front().second; 
            q.pop();
            if (x<c-1 && a[y][x+1]=='.') {
                if (!v[y][x+1]) q.push(make_pair(y,x+1));
                v[y][x+1] += v[y][x];
            }  if (y<l-1 && a[y+1][x]=='.') {
                if (!v[y+1][x]) q.push(make_pair(y+1,x));
                v[y+1][x] += v[y][x];
            }
        }
        //F(i,0,l) F(j,0,c) cout << v[i][j] << " \n"[j==c-1];
        cout << k << " " << v[l-1][c-1] << " " << ((k == v[l-1][c-1]) ? "YES" : "NO") << '\n';
        cout << '\n';
    }
}