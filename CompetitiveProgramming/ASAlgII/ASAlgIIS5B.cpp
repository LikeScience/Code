#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i != e; i++)
using namespace std;

int n, t;

void r(int i, int d) {
    if (d>h || i>=n) return;
    if (d==h) {
        F(j,0,n) o[t].push_back((b[j] ? !v[j] : v[j])); 
        t++;
        return;
    }
    r(i+1,d);
    b[i+1]=1;
    r(i+1,d+1);
    b[i+1]=0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cin >> t
    F(z,0,t) {
        cin >> n;
        
    }

}