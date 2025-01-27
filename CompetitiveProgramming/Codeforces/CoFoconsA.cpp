#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int main( ) {
    int t, a, b, c;
    cin >> t;
    F(z,0,t) {
        cin >> a >> b >> c;
        cout << ((c >= min(a,b) && c <= max(b,a)) ? "YES" : "NO") << '\n';
    }
}