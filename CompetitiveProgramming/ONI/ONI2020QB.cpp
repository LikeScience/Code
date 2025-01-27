#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define F(i,x,e) for (long long i=x; i<e; i++)
#define f first
#define s second
#define ll long long
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main() {
    ll p, n;
    cin >> p >> n;
    if (p==1) {
        vector<ll> t = {0}; vector<bool> v(n+1,1); 
        vector<pair<ll, ll> > o; bool b=0; ll p2=1;
        while (t[(ll)t.size()-1] < 262143){
            p2*=2; 
            t.push_back(p2-1);
        }
        for (ll i = n; i>=1; i--) {
            if (v[i]) {
                if (!b) {
                    b=1;
                    p2 = *upper_bound(t.begin(), t.end(), i);
                }
                v[i] = 0;
                v[p2-i]=0;
                o.push_back({i,p2-i});
            } else b=0;
        }
        F(i,0,n/2) cout << o[i].f << " " << o[i].s << '\n';
    } else {
        vector<ll> t; vector<bool> v(n+1,1), ps(200000, 1); 
        vector<pair<ll, ll> > o; bool b=0; ll pr;
        //cout << "a" << '\n';
        F(i,2,(ll)ps.size()) if (ps[i]){
            t.push_back(i);
            for (long long j = i*i; j<200000; j+=i) ps[j]=0;
        }
        //cout << "a" << '\n';
        for (ll i = n; i>=1; i--) {
            if (v[i]) {
                if (!b) {
                    b=1;
                    pr = *upper_bound(t.begin(), t.end(), i);
                }
                v[i] = 0;
                v[pr-i]=0;
                o.push_back({i,pr-i});
            } else b=0;
        }
         F(i,0,n/2) cout << o[i].f << " " << o[i].s << '\n';
    }
}