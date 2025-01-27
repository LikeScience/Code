#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll t=0;
    int n, m;
    cin >> n >> m;
    int a[n], b[n], ee[n], ed[n], de[n];
    map<int, int> edm, dem;
    map<pair<int, int>, int> eem;
    F(i,0,n) cin >> a[i];
    F(i,0,n) cin >> b[i];
    edm[a[0]] = 1;
    dem[b[0]] = 1;
    eem[{a[0],b[0]}] = 1; 
    F(i,1,n) {
        ed[i] = edm[a[i]]++;
        //cout << i << " "<< ed[i] << '\n';
    }
    F(i,1,n) {
        de[i] = dem[b[i]]++;
        //cout << i << " "<< de[i] << '\n';
    }
    F(i,1,n) {
        ee[i] = eem[{a[i],b[i]}]++;
        //cout << i << " "<< ee[i] << '\n';
    }
    F(i,1,n) {
        t+= i - de[i] - ed[i] + 2*ee[i];
    }
    cout << t << '\n';
}