#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define F(i,s,e) for (int i =s; i<e; i++)
#define ll long long
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int c, m; ll ma;
vector<ll> pk;
vector<bool> am;
vector<ll> a, b;

void genrec(vector<ll> v, ll s, ll id) {
    if (((int)pk.size() - (int)v.size()) *min(m-s, b[id]-1) < m-s) return;
    //cout << m << m-s << '\n';
    //F(i,0,(int)v.size()) cout << v[i] << ' '; cout << '\n';
    if ((int)v.size() == (int)pk.size()) {
        if (s < m) return;
        ll t=0;
        F(i,0,(int)v.size()) {t+= v[i]*pk[i]; }
        if (t <= ma && am[t]) c++;
        //cout << t << '\n';
        return;
    }
    F(i,0,min(m-s+1, b[id])) {
        
        v.push_back(i);
        genrec(v, s+i, id);
        v.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> m >> q;
    a.resize(n); b.resize(q);
    F(i,0,n) cin >> a[i];
    F(i,0,q) cin >> b[i];
    if (n <= 1000 && q <= 1000) {
    F(i,0,q) {
        c=0;
        sort(a.begin(), a.end());
        vector<ll> pk = {1};
        while(pk[(int)pk.size()-1] < a[n-1]) {pk.push_back(b[i]*pk[(int)pk.size()-1]);}
        F(j,0,n) {
            int pm=0; ll aj = a[j];
            for (int z = (int)pk.size()-1; z>=0; z--) {
                pm += aj/pk[z];
                aj -= pk[z]*(aj/pk[z]);
            }
            if (pm == m) c++;
            //cout << b[i] << " " << a[j] << "  " << pm << '\n';
        }
        cout << c << '\n';
    }
    } else {
        ma = 0;
        F(i,0,n) ma = max(a[i], ma);
        am.assign(ma+1, 0);
        F(i,0,n) am[a[i]] = 1;
        F(i,0,q) {
            c= 0;
            pk = {1};
            while(pk[(int)pk.size()-1] < ma) {pk.push_back(b[i]*pk[(int)pk.size()-1]);}
            genrec({}, 0, i);
            cout << c << '\n';
        }
    }
}