#include <bits/stdc++.h>
using namespace std;

vector<int> st;

void update(int l, int r, int x, int idx, int v) {
    if (l == r) {
        st[x] = v;
        return;
    } int m = (l+r)/2;
    if (idx <= m) update(l, m, 2*x+1, idx, v);
    else update(m+1, r, 2*x+2, idx, v);
    st[x] = min (st[2*x+1], st[2*x+2]);
}

int eval(int l, int r, int dl, int dr, int x) {
    if (l == dl && r == dr) {
        return st[x];
    } int m = (l+r)/2;
    if (dr <= m) return eval(l, m, dl, dr, 2*x+1);
    if (dl > m) return eval(m+1, r, dl, dr, 2*x+2);
    return min ( eval(l, m, dl, m, 2*x+1),  eval(m+1, r, m+1, dr, 2*x+2));
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i=0; i<n; i++) cin >> v[i];
    st.assign(4*n,2e9);

    for (int i=0; i<n; i++) update(0,n-1,0,i,v[i]);
    for (int i = 0; i<q; i++) {
        int k, a, b;
        cin >> k >> a >> b;
        //cout << i << flush;
        if (k == 1) {
            update(0,n-1,0,a-1,b);
        }
        else cout << eval(0,n-1,a-1,b-1, 0) << '\n';
    }


}