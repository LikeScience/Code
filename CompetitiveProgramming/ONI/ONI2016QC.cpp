#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i < e; i++)
using namespace std;

vector<bool> v;

struct ste {
    int l;
    int r;
    int m;
};

vector<ste> st;

void stb(int l, int r, int x) {
    if (l==r) {
        st[x].l = st[x].r = st[x].m = 1-v[l];
        return;
    }
    stb(l,(l+r)/2,2*x+1);
    stb((l+r)/2+1,r,2*x+2);
    st[x].m = max(max(st[2*x+1].m, st[2*x+2].m),st[2*x+1].r+st[2*x+2].l);
    st[x].l = (st[2*x+1].l != ((l+r)/2-l+1)) ? st[2*x+1].l : st[2*x+1].l + st[2*x+2].l ;
    st[x].r = (st[2*x+2].r != (r-(l+r)/2)) ? st[2*x+2].r : st[2*x+1].r + st[2*x+2].r ;
    return;
}

void stu(int l, int r, int x, int u) {
    //cout << x << " " << l << " " << r << '\n';    
    if (l==r) {
        st[x].m = (st[x].m == 0);
        st[x].l = st[x].r =  st[x].m;
        return;
    }
    if (u <= (l+r)/2) {stu(l,(l+r)/2,2*x+1, u);}
    else stu((l+r)/2+1,r,2*x+2, u);
    st[x].m = max(max(st[2*x+1].m, st[2*x+2].m),st[2*x+1].r+st[2*x+2].l);
    st[x].l = (st[2*x+1].l != ((l+r)/2-l+1)) ? st[2*x+1].l : st[2*x+1].l + st[2*x+2].l ;
    st[x].r = (st[2*x+2].r != (r-(l+r)/2)) ? st[2*x+2].r : st[2*x+1].r + st[2*x+2].r ;
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q, a;
    char c;
    cin >> n >> q;
    st.resize(4*n);
    F(i,0,n) {
        cin >> c;
        v.push_back(c=='1');
    }
    stb(0,n-1,0);
    
    F(i,0,q) {
        cin >> c;
        if (c == 'P' || c == 'A') {
            cin >> a;
            stu(0,n-1,0,a-1);
        } else {
            cout << st[0].m << '\n';
        }
        //F(i,0,2*n) cout << i << " " << st[i].m << " " << st[i].l << " " << st[i].r << '\n';
    }
}