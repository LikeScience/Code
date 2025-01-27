#include <bits/stdc++.h>
#define ll long long
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

vector<int> mi, ma;

void miu(int l, int r, int x, int d, int v) {
    if (l == r) {
        mi[x] = v;
        return;
    } int m = (l+r)/2;
    if (d<=m) miu(l,m,2*x+1,d,v);
    else miu(m+1,r,2*x+2,d,v);
    mi[x] = min(mi[2*x+1], mi[2*x+2]);
}

void mau(int l, int r, int x, int d, int v) {
    if (l == r) {
        ma[x] = v;
        return;
    } int m = (l+r)/2;
    if (d<=m) mau(l,m,2*x+1,d,v);
    else mau(m+1,r,2*x+2,d,v);
    ma[x] = max(ma[2*x+1], ma[2*x+2]);
}

int mie(int l, int r, int dl, int dr, int x) {
    if (l == dl && r == dr) return mi[x];
    int m = (l+r)/2;
    if (dr<=m) return mie(l,m,dl,dr,2*x+1);
    else if (dl>m) return mie(m+1,r,dl,dr,2*x+2);
    else return min(mie(l,m,dl,m,2*x+1), mie(m+1,r,m+1,dr,2*x+2));
}

int mae(int l, int r, int dl, int dr, int x) {
    if (l == dl && r == dr) return ma[x];
    int m = (l+r)/2;
    if (dr<=m) return mae(l,m,dl,dr,2*x+1);
    else if (dl>m) return mae(m+1,r,dl,dr,2*x+2);
    else return max(mae(l,m,dl,m,2*x+1), mae(m+1,r,m+1,dr,2*x+2));
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, n, x, mm=1e9, MM = -1e9;
    cin >> t;
    F(z,0,t) {
        cin >> n;
        mi.assign(4*n, mm);
        ma.assign(4*n, MM);
        vector<int> v(n);
        F(i,0,n) {
            cin >> v[i];
            miu(0,n-1,0,i,v[i]);
            mau(0,n-1,0,i,v[i]);
        }
        vector<deque<int> >a(n+1); int cnt=0;
        vector<int> w;
        F(i,0,n) {
            if (a[v[i]].empty()) {cnt++; w.push_back(v[i]);}
            a[v[i]].push_back(i);
        }
        set<pair<int, int> > minl;
        F(i,0, cnt) {
            minl.insert(make_pair(a[w[i]][(int)a[w[i]].size()-1], w[i]));
        } vector<int> ot; int l=0;
        
        F(j,0,cnt) {
            int x = minl.begin()->first, y;
            if (!(j%2)) {
                y = mae(0,n-1,l,x,0);
            } else {
                y = mie(0,n-1,l,x,0);
            }
            ot.push_back(y);
            int k = a[y].front();
            F(i,l,k) if (v[i]!=y) while ((int)a[v[i]].size() && a[v[i]][0]<k) a[v[i]].pop_front();
            F(i,0,(int)a[y].size()) {
                miu(0,n-1,0,a[y][i],mm);
                mau(0,n-1,0,a[y][i],MM);
            }
            
            minl.erase(make_pair(a[y][(int)a[y].size()-1],y));
            l = k+1;
        }
        cout << cnt << '\n';
        F(i,0,cnt) cout << ot[i] << " \n"[i==cnt-1];
    }   
}