#include <bits/stdc++.h>
#define F(i,s,e) for (ll i = s; i<e; i++)
#define ll long long
using namespace std;

vector<int> dec(int x) {
    vector<int> o;
    while (x) {
        o.push_back(x%10);
        x/=10;
    }
    return o;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll a, q, n;
    cin >> a >> q;
    bool b = 1;
    vector<int> va = dec(a), v(10,0), p9 = {1}, p10 = {1};
    int vs = (int)va.size();
    F(i,1,vs) if (va[i] != va[0]) b = 0;
    F(i,0,9) p9.push_back(9*p9[i]); F(i,0,9) p10.push_back(10*p10[i]);
    F(i,1,10) {
        int x = 9*p10[i-1];
        if (vs <= i) {
            F(j,0,i-vs+1) {
                if (j == i-vs) {
                    x -= (v[j]+1);
                    if (b) F(k,1,vs) if (j-k>=0) x += ((j - k == 0) ? 1 : ((j-k == 1) ? 9 : 9*(v[j-k-1]+1)));
                } else if (j == 0) {x-= 9*p10[i-vs-1];}
                else {
                    x-= 9*p10[i-vs-j-1]*(v[j]+1);
                    if (b) F(k,1,vs) if (j-k>=0) x += ((j - k == 0) ? 1 : ((j-k == 1) ? 9 : 9*(v[j-k-1]+1)));
                }
            }
        }
        v[i] = v[i-1]+x;
    }
    F(i,0,10) cout << v[i] << '\n';
    F(z,0,q) {
        cin >> n;
        vector<int> vn = dec(n); int ns = (int)vn.size();
        int x = v[ns]-1;
        //for (int )
    }
}