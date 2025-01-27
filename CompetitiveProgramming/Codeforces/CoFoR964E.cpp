#include <bits/stdc++.h>
#define ll long long
#define F(i,s,e) for (int i = s; i<e; i++) 
using namespace std;

vector<ll> st;

void stu(int l, int r, int d, int x, ll v) {
    if (l == r) {
        st[x] = v;
        return;
    }  int m = (l+r)/2;
    if (d<=m) stu(l,m,d,2*x+1,v);
    else if (d>m) stu(m+1,r,d,2*x+2,v);
    st[x]+=v;
}

ll ste(int l ,int r, int dl ,int dr, int x) {
    if (l == dl && r == dr) return st[x];
    int m = (l+r)/2;
    if (dr <=m) return ste(l,m,dl,dr,2*x+1);
    else if (dl > m) return ste(m+1,r,dl,dr,2*x+2);
    else return ste(l,m,dl,m,2*x+1) + ste(m+1,r,m+1,dr,2*x+2);

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, l, r;
    cin >> t;
    st.assign(4*2e5, 0);
    F(i,1,2e5+1) {
            ll y = i, c=0;
            while(y>0) {
                y/=3;
                c++;
            }
            stu(1,2e5,i,0,c);
        }
    F(z,0,t) {
        cin >> l >> r;
        cout << ste(1,2e5,l,r,0) + ste(1,2e5,l,l,0) << '\n'; 
    }

}
