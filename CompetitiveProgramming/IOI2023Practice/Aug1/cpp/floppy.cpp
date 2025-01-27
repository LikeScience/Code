#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
#define fi first
#define se second
#include "floppy.h"
using namespace std;

vector<pair<int, int> > st;
string str;
int idididid = -2;
int nnnnn;

void stb(int al, int ar, int x, const vector<int> &v) {
    if (al == ar) {
        st[x].fi = v[al];
        st[x].se = al;
        return;
    } int m = (al+ar)/2;
    stb(al,m,2*x+1,v);
    stb(m+1,ar,2*x+2,v);
    if (st[2*x+1].fi > st[2*x+2].fi) {
        st[x] = st[2*x+1];
    } else {
        st[x] = st[2*x+2];
    }
}

pair<int, int> ste(int al, int ar, int dl , int dr, int x) {
    if (al == dl && ar == dr) {
        return st[x];
    } int m = (al+ar)/2;
    if (dr <= m) {
        return ste(al,m,dl,dr,2*x+1);
    } else if (dl >= m+1) {
        return ste(m+1,ar,dl,dr,2*x+2);
    } else {
        pair<int, int> a = ste(al,m,dl,m,2*x+1), b = ste(m+1,ar,m+1,dr,2*x+2);
        if (a.fi>b.fi) {return a;} else return b;
    }
} 

void ctb(int al, int ar) {
    idididid+=2;
    if (al == ar) return;
    pair<int, int> ap = ste(0,nnnnn-1,al,ar,0);
    if (ap.se == al) {
        str[idididid+1]='1';
        ctb(ap.se+1,ar);
    } else if (ap.se == ar) {
        str[idididid]='1';
        ctb(al, ap.se-1);
    } else {
        str[idididid]='1';
        str[idididid+1]='1';
        ctb(al, ap.se-1);
        ctb(ap.se+1,ar);
        
    }
    
}

void read_array(int subtask_id, const std::vector<int> &v) {
    int n = (int)v.size(); nnnnn = n;
    st.assign(4*n, make_pair(0,0));
    str.assign(2*n, '0');
    stb(0,n-1,0,v);
    ctb(0,n-1);
    cout << str << '\n';
    save_to_floppy(str);
}

vector<int> lalala, rarara, papapapa, sub, idx, fir, pth, dth, s2;

void dfs1(int v, const string &bits) {
    if (v != 0) dth[v] = dth[papapapa[v]]+1;
    if (str[2*idididid] == '0' && str[2*idididid+1] == '0') { return;}
    if (str[2*v] == '1') {
        lalala[v] = ++idididid;
        papapapa[idididid] = v;
        int k = idididid;
        dfs1(k,bits);
        sub[v] += sub[k];
    }
    if (str[2*v+1] == '1') {
        rarara[v] = ++idididid;
        papapapa[idididid] = v;
        int k = idididid;
        dfs1(k,bits);
        sub[v] += sub[k];
    }

}
void aridir(int le, int v) {
    idx[v] = le + (lalala[v] != -1 ? sub[lalala[v]] : 0);
    if (lalala[v] != -1) {
        aridir(le,lalala[v]);
    } if (rarara[v] != -1) {
        aridir(idx[v]+1, rarara[v]);
    } return;
}

void dfs2(int v) {
    pth.push_back(v);
    fir[idx[v]]=(int)pth.size()-1;
    if (lalala[v] != -1) {
        dfs2(lalala[v]);
        pth.push_back(v);
    } if (rarara[v] != -1) {
        dfs2(rarara[v]);
        pth.push_back(v);
    } return;
}

void s2b(int al, int ar, int x) {
    if (al == ar) {
        s2[x] = pth[al];
        return;
    } int m = (al+ar)/2;
    s2b(al,m,2*x+1);
    s2b(m+1,ar,2*x+2);
    if (dth[s2[2*x+1]] < dth[s2[2*x+2]]) {
        s2[x] = s2[2*x+1];  
    }else s2[x] = s2[2*x+2];
}
int s2e (int al, int ar, int dl, int dr, int x) {
    if (al == dl && ar == dr) {
        return s2[x];
    } int m = (al+ar)/2;
    if (dr <= m) {
        return s2e(al, m, dl, dr, 2*x+1);
    } else if (dl >= m+1) {
        return s2e( m+1, ar, dl, dr, 2*x+2);
    } else {
        int a = s2e(al, m, dl, m, 2*x+1), b = s2e( m+1, ar, m+1, dr, 2*x+2);
        if (dth[a] < dth[b]) {
            return a;
        } else return b;
    }
}

std::vector<int> solve_queries(int subtask_id, int N, const std::string &bits, const std::vector<int> &a, const std::vector<int> &b) {
    vector<int> ans;
    int m = (int)a.size();
    lalala.assign(N, -1); rarara.assign(N,-1); papapapa.assign(N,-1); sub.assign(N,1); idx.assign(N,0); dth.assign(N,0); fir.assign(N,0);
    idididid = 0;
    dfs1(0, bits);
    aridir(0, 0);
    dfs2(0);
    //F(i,0,N) cout << idx[i] << " " << idx[lalala[i]] << " " << idx[rarara[i]] << " " << idx[papapapa[i]] << " " << sub[i] << " " << dth[i] << '\n';
    int ps = (int)pth.size();
    s2.assign(4*ps, 0);
    s2b(0, ps-1, 0);
    //F(i,0,N) cout << fir[idx[i]] << " "; 
    F(i,0,m) {
        ans.push_back(idx[s2e(0,ps-1,min(fir[a[i]], fir[b[i]]),max(fir[a[i]], fir[b[i]]),0)]);
        //cout << ans[i] << " ";
    }
    return ans;
}
