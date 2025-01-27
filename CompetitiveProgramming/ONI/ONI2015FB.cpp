#include <bits/stdc++.h>
#define F(i,x,e) for (int i=x; i<e; i++)
#define f first
#define s second
using namespace std;

struct ste {
    int l;
    int m;
    int r;
};

vector<ste> st1;
vector<int> st2;
vector<pair<int, int> > me;

void st1b (int l, int r, int x) {
    if (l == r) {
        st1[x].l = st1[x].r = st1[x].m = 1;
        return;
    }
    st1b(l,(l+r)/2,2*x+1);
    st1b((l+r)/2+1,r,2*x+2);
    st1[x].l = st1[x].r = st1[x].m = r-l+1;
    return;
}

void st1u (int l, int r, int dl, int dr, int x, int v) {
    if (l == dl && r == dr) {
        if (v) {st1[x].l = st1[x].r = st1[x].m = 0;}
        else {st1[x].l = st1[x].r = st1[x].m = r-l+1;}
        return;
    } int m = (l+r)/2;
    if (dr <= m) st1u(l, m, dl, dr, 2*x+1, v);
    else if (dl >= m+1) st1u(m+1, r, dl, dr, 2*x+2, v);
    else {
        st1u(l, m, dl, m, 2*x+1, v);
        st1u(m+1, r, m+1, dr, 2*x+2, v);
    }
    st1[x].m = max(max(st1[2*x+1].m, st1[2*x+2].m), st1[2*x+1].r + st1[2*x+2].l);
    st1[x].l = st1[2*x+1].l +((st1[2*x+1].l == m-l+1) ? st1[2*x+2].l : 0) ;
    st1[x].r = st1[2*x+2].r +((st1[2*x+2].r == r-m) ? st1[2*x+1].r : 0) ;
    return;
}

void st2b (int l, int r, int x) {
    if (l == r) {
        st2[x] = me[l].s;
        return;
    }
    st2b(l,(l+r)/2,2*x+1);
    st2b((l+r)/2+1,r,2*x+2);
    st2[x] = max (st2[2*x+1], st2[2*x+2]);
    return;
}

int st2f(int l, int r, int dl, int dr, int x) {
    if (l == dl && r == dr) {
        return st2[x];
    } int m = (l+r)/2;
    if (dr <= m) {return st2f(l , m , dl , dr ,2*x+1);}
    else if (dl >= m+1) {return st2f(m+1 , r , dl , dr ,2*x+2);}
    else return max(st2f(l , m , dl , m ,2*x+1),st2f(m+1 , r , m+1 , dr ,2*x+2));
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k, p, a, b, c, d;
    cin >> n >> k >> p;
    vector<pair<pair<int, int>, pair<int, int> > > o;
    
    F(i,0,k) {
        cin >> a >> b >> c >> d;
        o.push_back({{c,1},{a,b}});
        o.push_back({{d+1,0},{a,b}});
    }
    st1.resize(4*n);
    st1b(0,n-1,0);
    me.push_back({0,n});
    sort(o.begin(), o.end());
    F(i,0,2*k) {
        a = o[i].f.f; b= o[i].f.s; c = o[i].s.f; d = o[i].s.s;
        st1u(0, n-1, c, d, 0, b);
        if (i == 2*k-1 || o[i+1].f.f != o[i].f.f) me.push_back({a,st1[0].m});
    }
    
    int ms = (int)me.size();
    //F(i,0,ms) cout << me[i].f << " " << me[i].s << '\n';
    st2.resize(4*ms);
    st2b(0,ms-1,0);
    F(i,0,p) {
        cin >> a >> b;
        int i1 = (lower_bound(me.begin(), me.end(), make_pair(a,10000000)) - me.begin()) -1, i2 = (lower_bound(me.begin(), me.end(), make_pair(b,10000000))- me.begin()) -1;
        cout << st2f(0, ms-1, i1, i2, 0) << '\n';
    }
}