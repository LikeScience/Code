#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

const int M = 1e9+1;

int main() {
    random_device rd;
    int p, t, n, w; cin >> p >> t;
    cout << p << '\n' << t << '\n';
    if (p==2) {
        F(z,0,t) cin >> n >> w;
        cout << n << '\n';
        int l = rd() % M, r = rd()%M; if (l>r) swap(l,r); 
        cout << l << " " << r;
        if (w) {
            
        }
    }
    
}