#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i != e; i++)
#define f first
#define s second
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int n;
    vector<int> p;
    ll z, c=0, k, M = 998244353;
    vector<bool> ip(1001,1);
    pair<int, int> a;
    cin >> n >> k;
    int v[n][n], vi[n][n] = {};
    F (i,0,n) F(j,0,n) cin >> v[i][j];
    for (int i = 2; k>1; i++) if (ip[i]){
        while(!(k%i)){
            k/=i;
            p.push_back(i);
            c = c << 1;
            c = c | 1;
        }
        for (int j = i*i; j*j<=k; j+=i) ip[j] = 0;
    }
    cout << c << '\n';
    k=0; z=1;
    map<ll, ll> r[n][n];
    
    F(i,0,p.size()){
        if (!(v[0][0] % p[i])) {
            k = k | z;
            v[0][0]/= p[i];
        }
        z = z << 1;
    }r[0][0][k]=1;
    queue<pair<int, int> > q;
    if (n>1) {
        if (v[1][0] != -1) {q.push({1,0}); vi[1][0] = 1;}
        if (v[0][1] != -1) {q.push({0,1}); vi[0][1] = 1;}
    }
    while(!q.empty()) {
        a = q.front(); q.pop();
        k=0; z=1;
        
        F(i,0,p.size()){
            if (!(v[a.f][a.s] % p[i])) {
                k = k | z;
                v[a.f][a.s]/= p[i];
            }
            z = z << 1;
        }
        
        if (a.f > 0) {
            for (map<ll, ll>::iterator it = r[a.f-1][a.s].begin(); it !=r[a.f-1][a.s].end(); it++) {
                r[a.f][a.s][it->first | k] += it->second;
                r[a.f][a.s][it->first | k] %= M;
            }
        }
        if (a.s > 0) {
            for (map<ll, ll>::iterator it = r[a.f][a.s-1].begin(); it !=r[a.f][a.s-1].end(); it++) {
                r[a.f][a.s][it->first | k] += it->second;
                r[a.f][a.s][it->first | k] %= M;
            }
        }
        //cout << r[a.f][a.s][0] << '\n';
        if (a.f < n-1 && v[a.f+1][a.s] != -1 && !vi[a.f+1][a.s]) {q.push({a.f+1, a.s}); vi[a.f+1][a.s] = 1;}
        if (a.s < n-1 && v[a.f][a.s+1] != -1 && !vi[a.f][a.s+1]) {q.push({a.f, a.s+1}); vi[a.f][a.s+1] = 1;}
    }
    cout << r[n-1][n-1][c] << '\n';
}