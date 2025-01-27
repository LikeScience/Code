#include <bits/stdc++.h>
#define F(i,s,e) for(int i=s; i<e; i++)
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    vector<ll> p2 = {1}, p5 = {1};
    while(p2[(int)p2.size()-1] <= 1e18) {
        p2.push_back(2*p2[(int)p2.size()-1]);
    }
    while(p5[(int)p5.size()-1] <= 1e18) {
        p5.push_back(5*p5[(int)p5.size()-1]);
    }
    ll a, b; int m2, m5;
    cin >> a >> b;
    for (int i = (int)p2.size()-1; i >= 0; i--) {
        if (b-a+1 >= p2[i]) {m2 = i; break;} 
        if ((a % p2[i]) == 0 || (b%p2[i]) < (a%p2[i])) {m2 = i; break;} 
    }
    for (int i = (int)p5.size()-1; i >= 0; i--) {
        if (b-a+1 >= p5[i]) {m5 = i; break;} 
        if ((a % p5[i]) == 0 || (b%p5[i]) < (a%p5[i])) {m5 = i; break;} 
    }
    cout << min(m2, m5) << '\n';
}