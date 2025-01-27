#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;


int main() {
    random_device rd;
    ios::sync_with_stdio(0); cin.tie(0);
    int r=900, c=900, t=10;
    cout << r << " " << c << " " << t << '\n';
    int hr = (rd()%900), hc = (rd()%900);
    F(i,0,r) {
        F(j,0,c) cout << ((i == hr && j == hc) ? 'H' : (rd()%10 ? '.' : 'O'));
        cout << '\n';
    } 
    F(i,0,t) {
        cout << 1+(rd()%900) << " " << 1+(rd()%900) << '\n';
    }
}