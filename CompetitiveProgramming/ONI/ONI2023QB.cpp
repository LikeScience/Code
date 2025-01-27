#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
#define ll long long
#define fi first
#define se second
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int p, t, n;
    cin >> p >> t;
    if (p==1) {
        F(z,0,t) {
            cin >> n; bool bb=1;
            int l, r, li, ri;
            cin >> l >> r;
            F(i,1,n) {
                cin >> li >> ri;
                l = max(l+1,li);
                r = min(r+1,ri);
                if (r < l) bb=0;
            }
            if (bb) {
                cout << "SIM" << '\n';
                F(i,l-n+1, l) cout << i << " ";
                cout << l << '\n';
            } else cout << "NAO" << '\n';
        }
    } else {
        F(z,0,t) {
            cin >> n; bool bb=1;
            int l, r, li, ri;
            vector<int> lv, rv, o(n);
            cin >> l >> r;
            lv.push_back(l); rv.push_back(r);
            F(i,1,n) {
                cin >> li >> ri;
                l = max(l-1,li);
                r = min(r+1,ri);
                lv.push_back(l);
                rv.push_back(r);
                if (r < l) bb=0;
            }
            if (bb) {
                cout << "SIM" << '\n';
                o[n-1] = l;
                for (int i=n-2; i>=0; i--) {
                    if (lv[i] <= o[i+1] && o[i+1] <= rv[i]) {o[i] = o[i+1];}
                    else if (o[i+1] < lv[i]) {o[i] = o[i+1]+1;}
                    else o[i] = o[i+1]-1;
                }
                F(i,0, n) cout << o[i] << " ";
            } else cout << "NAO" << '\n';
        }
    }

}