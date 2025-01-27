#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i < e; i++)
using namespace std;

#define hs (int)h.size()
#define ld long double
vector<ld> x, y;
int m = 0;

int cps(ld a1, ld a2, ld b1, ld b2) { //1 if to left; -1 if to right
    ld r = a1*b2-a2*b1;
    return (r<0) ? -1 : (r>0);
}//cross product sign

bool cmp (int &a, int &b) { //Sorting by increasing angle 
    int r = cps(x[a]-x[m], y[a]-y[m], x[b]-x[m], y[b]-y[m]);
    if (r) return (r+1)/2;
    return abs(x[a]-x[m]) + abs(y[a]-y[m]) < abs(x[b]-x[m]) + abs(y[b]-y[m]);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; vector<int> v, h;
    x.resize(n); y.resize(n);
    F(i,0,n) cin >> x[i] >> y[i];
    F(i,1,n) if (y[i] < y[m] || (y[i] == y[m] && x[i] < x[m])) m = i;
    F(i,0,n) if (i!=m) v.push_back(i); 
    sort(v.begin(), v.end(), cmp); v.push_back(m);  
    h = {m,v[0]}; 
    F(i,1,n) {
        while (hs > 2 && cps(x[h[hs-1]]-x[h[hs-2]],y[h[hs-1]]-y[h[hs-2]],
                             x[v[i]]-x[h[hs-1]],y[v[i]]-y[h[hs-1]]) == -1) h.pop_back(); //If right turn
        h.push_back(v[i]);
    } h.pop_back(); //Remove repeated original vertex
    //Next line only if we need to put those colinear with m
    for(int i = (int)v.size()-3; i>0 && !cps(x[m]-x[v[i]],y[m]-y[v[i]],x[h[hs-1]]-x[m],y[h[hs-1]]-y[m]);i--) h.push_back(v[i]);
    cout << hs << '\n';
    F(i,0,hs) cout << (long long)x[h[i]] << " " << (long long)y[h[i]] << '\n';
} 