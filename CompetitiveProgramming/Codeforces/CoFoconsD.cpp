#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int main( ) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; string s;
    cin >> n >> k; int t = 0, a=0;
    F(i,0,n) {
        cin >> s;
        if (i != 0 && a+s.size()+1 <= k) a += s.size()+1;
        else {
            t++; a= s.size();
        }
    }
    cout << t << '\n';
}