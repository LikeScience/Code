#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i != e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int t, n, c, s, m,p;
    cin >> t;
    F(i,0,t) { 
        cin >> n;
        cin >> p; s=0; m=1;
        F(i,0,n-1) {
            cin >> c;
            if (s+p<c) {
                m++;
                s+=p;
            }
            p=c;
        }
        cout << m << '\n';
    }
}