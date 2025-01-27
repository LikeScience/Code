#include <bits/stdc++.h>
#define F(i,s,e) for(long long i = s; i < e; i++)

using namespace std;

int main() {
    int n, m, a, b = 1, t = 0;
    cin >> n >> m;
    
    F(i,0,m) {
        cin >> a;
        if (a < 4) {
            b = 0; break;
        }
        t += a/4;
    }
    if (!b || (n > t || m > n)) {
        cout << "NE" << '\n';
    } else cout << "DA" << '\n';
}