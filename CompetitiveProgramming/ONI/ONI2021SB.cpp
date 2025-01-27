#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define s second
#define f first
#define F(i,x,e) for (ll i = x; i<e; i++)
#define ll long long 
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<pair<ll, ll> > st;

void stu(ll l, ll r, ll x, ll d, ll k) {
    if (l == r) {
        st[x].s += k;
        st[x].f += l*k;
        return;
    } ll m = (l+r)/2;
    if (d <= m) { stu(l,m,2*x+1,d,k);}
    else stu(m+1,r,2*x+2,d,k);
    st[x].f = st[2*x+1].f + st[2*x+2].f;
    st[x].s = st[2*x+1].s + st[2*x+2].s;
    return;
}

ll ste(ll l, ll r, ll x, ll c) {
    if (l==r) {
        return c*l;
    } ll m = (l+r)/2;
    if (c > st[2*x+2].s) return st[2*x+2].f + ste(l,m, 2*x+1, c-st[2*x+2].s);
    if (c == st[2*x+2].s) return st[2*x+2].f;
    return ste(m+1,r, 2*x+2, c);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, a; char c;
    st.assign(4000000,{0,0});
    cin >> n;
    map<ll, bool> v;
    F(z,0,n) {
        cin >> c >> a;
        if (c == 'A') {
            if (int(v.size()) == 0) {
                v[a]=1;
                continue;
            }
            map<ll, bool>::iterator it = v.upper_bound(a);
            if (it == v.begin()) {
                //cout << "SW" << '\n';
                stu(0,999999,0,v.begin()->f-a, 1);
                v[a]=1;
            } else if (it == v.end()) {
                it--;
                stu(0,999999,0,a-it->f, 1);
                v[a]=1;
            } else {
                map<ll, bool>::iterator it2 = it; it2--;
                stu(0,999999,0,it->f -it2->f, -1);
                stu(0,999999,0,it->f -a, 1);
                stu(0,999999,0,a-it2->f , 1);
                v[a] = 1;
            }
        } else if (c == 'R') {
            if (int(v.size()) == 1) {
                v.erase(a);
                continue;
            }
            map<ll, bool>::iterator it = v.lower_bound(a), it2;
            if (it == v.begin()) {
                it++;
                stu(0,999999,0,it->f -a, -1);
                v.erase(v.begin());
            } else if (++it == v.end()) {
                it--; it--;
                stu(0,999999,0,a-it->f, -1);
                v.erase(a);
            } else {
                
                it2 = --it; it++; it2--;
                //cout << it->f << " " << 1 << " " << a << '\n';
                //cout << it->f-it2->f << ' ' << it->f-a << ' ' << a-it2->f << '\n';
                
                stu(0,999999,0,it->f - it2->f, 1);
                stu(0,999999,0,it->f -a, -1);
                stu(0,999999,0,a-it2->f, -1);
                v.erase(a);
                //for(it = v.begin(); it != v.end(); it++) cout << it->f << " ";
                //cout << '\n';
            }
        } else if (c == 'D') {
            map<ll, bool>::iterator it = v.end(); it--;
            cout << it->f - v.begin()->f -ste(0,999999, 0, a-1) << '\n';
            //F(i,0,4*3) cout << st[i].f << '\n';
            
        }
    }
}