#include <bits/stdc++.h>
#define ll long long
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; ll n, a, b;
    cin >> t; 
    F(z,0,t) {
        cin >> n >> a >> b;
        ll t=0;
        if (b>a) {
            if (n>=(b-a)) {
                t = b*(b+1)/2 - (a)*(a+1)/2 + (n-(b-a))*a;
            } else {
                t = b*(b+1)/2 - (b-n)*(b-n+1)/2;
            }
        } else {
            t = n*a;
        }
        cout << t << '\n';
    }
}