#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define x first
#define y second
#define mp make_pair
#define F(i,s,e) for (ll i = s; i<e; i++)
using namespace __gnu_pbds;
typedef  tree<pair<ll, ll>, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> pbds;


int main () {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, q, z, maxt=0;
    
    cin >> n >> q;ll t =n;
    vector<ll> c(n), ans; vector<pii> p;
    ll dst = n, lat=2*n;
    F(i,0,n) {
        cin >> c[i] >> c[i];
    }  
    sort(c.begin(), c.end());
    F(i,0,n-1) p.push_back(mp(c[i+1]-c[i],0));
    F(i,0,n-1) p.push_back(mp(c[i+1]-c[i]+1,1));
    //F(i,0,(int)p.size()) cout << p[i].x << '\n';
    F(i,0,q) {
        cin >> z;
        p.push_back(mp(z, 2));
    }ll inst = 0;sort(p.begin(), p.end());
    F(i,0,(ll)p.size()) {
        //cout << p[i].x << " " << p[i].y << " " << t << '\n';
        cout << t << '\n';
        if (p[i].y == 2) {
            
            if (inst == 0 && p[i].x >= 1) t-= lat-n;
            t += (2*dst + lat)*(p[i].x-inst);
            ans.push_back(t);
            inst = p[i].x;
        } else if (p[i].y == 0) {
            //if (p[i].x == 1) t++;
            if (p[i].x == 1) {
                lat-=2; dst--;
                if (i == (ll)p.size()-1 || p[i].x != p[i+1].x) {
                t += (2*dst )*(p[i].x-inst);
                t+= n;
                inst = p[i].x;
                
            }
                continue;
            }
            if (inst == 0) t-= lat-n;
            if (inst != p[i].x) t += (2*dst + lat)*(p[i].x-1-inst);
            t -= (p[i].x-1-1); lat--; dst--;
            inst = p[i].x-1;
            if (i == (ll)p.size()-1 || p[i].x != p[i+1].x) {
                t += (2*dst + lat)*(p[i].x-inst);
                inst = p[i].x;
            }
           
            
        } else {
            if (inst == 0) t-= lat-n;
            if (inst != p[i].x) t += (2*dst + lat)*(p[i].x-1-inst);
            t -= (p[i].x-1-1); if (p[i].x != 2)lat--;
            inst = p[i].x-1;
            if (i == (ll)p.size()-1 || p[i].x != p[i+1].x) {
                t += (2*dst + lat)*(p[i].x-inst);
                inst = p[i].x;
                
            }
        }
    }
    F(i,0,q) cout << ans[i] << '\n';

}