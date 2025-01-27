#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
#define fi first
#define se second
#include "floppy.h"
using namespace std;

vector<int> p2 = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192};

void read_array(int subtask_id, const std::vector<int> &v) {
    int n = (int)v.size();
    std::string bits = "";
    vector<pair<int, int> > x;
    F(i,0,n) {
        x.push_back(make_pair(v[i], i));
    }
    sort(x.begin(), x.end());
    vector<int> k(n);
    F(i,0,n) k[x[i].se] = i;
    string s;
    F(j,0,n) {
    for (int i = 13; i>=0; i--) {
        if ((k[j] & p2[i]) != 0) {
            bits.push_back('1');
        } else bits.push_back('0');
    }
    }
    save_to_floppy(bits);
}

vector<pair<int, int> > st;

void stb(int l, int r, int x, vector<int> &v) {
    if (l == r) {
        st[x].fi = v[l];
        st[x].se = l;
        return;
    } int m = (l+r)/2;
    stb(l,m,2*x+1,v);
    stb(m+1,r,2*x+2,v);
    if (st[2*x+1].fi > st[2*x+2].fi) {
        st[x] = st[2*x+1];
    } else st[x] = st[2*x+2];
}

pair<int, int> ste(int l, int r, int dl , int dr, int x) {
    if (l == dl && r == dr) {
        return st[x];
    } int m = (l+r)/2;
    if (dr <= m) {
        return ste(l,m,dl,dr,2*x+1);
    } else if (dl >= m+1) {
        return ste(m+1,r,dl,dr,2*x+2);
    } else {
        pair<int, int> a = ste(l,m,dl,m,2*x+1), b = ste(m+1,r,m+1,dr,2*x+2);
        if (a.fi>b.fi) {return a;} else return b;
    }
} 

std::vector<int> solve_queries(int subtask_id, int N, const std::string &bits, const std::vector<int> &a, const std::vector<int> &b) {
    st.resize(4*N);
    int m = (int)a.size();
    vector<int> v(N, 0);
    std::vector<int> ans;
    F(i,0,N) {
        F(j,0,14) {
            if (bits[14*i+j] == '1') v[i] += p2[13-j];
        }
    }
    stb(0,N-1,0,v);
    F(i,0,m) {
        ans.push_back(ste(0,N-1,a[i],b[i],0).se);
    }
    return ans;
}
