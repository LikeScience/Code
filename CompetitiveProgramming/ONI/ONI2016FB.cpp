#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
#define ll long long
using namespace std;

vector<vector<int> > h, st;

void stb(int l, int r, int x, int d) {
    if (l == r) {
        st[d][x] = h[d][l];
        return;
    } int m = (l+r)/2;
    stb(l,m,2*x+1,d);
    stb(m+1,r,2*x+2,d);
    st[d][x] = max(st[d][2*x+1], st[d][2*x+2]);
    return;
}

int stf (int l, int r, int dl, int dr, int x, int d) {
    if (l==dl && r == dr) {
        return st[d][x];
    } int m = (l+r)/2;
    if (dr <= m) {return stf(l,m,dl,dr,2*x+1,d);}
    else if (dl >= m+1){return stf(m+1,r,dl,dr,2*x+2,d);}
    else {
        int a = stf(l,m,dl,m,2*x+1,d), b = stf(m+1,r,m+1,dr,2*x+2,d);
        return max(a,b);
    }
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int l, c, r, rl, rc;
    cin >> l >> c;
    h.assign(l, vector<int>(c));
    F(i,0,l) F(j,0,c) cin >> h[i][j];
    st.assign(l, vector<int>(4*c));
    F(i,0,l) stb(0,c-1,0,i);
    cin >> r;
    F(z,0,r) {
        int m = 10000000;
        cin >> rl >> rc; 
        F(i,0,c-rc+1){
            vector<int> v(l);
          
            //multiset<int> s;
            map<int, int> s;
            F(j,0,rl) {
                
                v[j] = stf(0,c-1,i,i+rc-1,0,j);
                //s.insert(v[j]);
                s[v[j]]++;
            } //multiset<int>::iterator it = s.end();
            map<int, int>::iterator it = s.end();
            it--;
            //int mn = *it;
            int mn = it->first;
            F(j,rl,l) {
                
                v[j] = stf(0,c-1,i,i+rc-1,0,j);
                //s.insert(v[j]);
                s[v[j]]++;
                //s.erase(lower_bound(s.begin(), s.end(), v[j-rl]));
                s[v[j-rl]]--;
                if (s[v[j-rl]] == 0) s.erase(v[j-rl]);
                it = s.end(); it--;
                //mn = min(*it,mn);
                mn = min(it->first,mn);
            }
            m = min(mn, m);
        }
        cout << m+1 << '\n';
    }
    return 0;
}