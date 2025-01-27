#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define F(i,s,e) for(int i =s; i<e; i++)
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<int> temp;
vector<pbds> st;

void stbuild (int l, int r, int x) {
    F(i,l,r+1) {
        st[x].insert({temp[i+1], i});
    }
    if (l == r) {
        return;
    }
    int m = (l+r)/2;
    stbuild(l,m,2*x+1);
    stbuild(m+1,r,2*x+2);
}

int search(int l, int r, int a, int b, int x, int k) {
    if (l == a && r == b) {
        //cout << r << " " << l << " " << (st[x].order_of_key(k+1)) << '\n';
        //for (auto it = st[x].begin(); it != st[x].end(); it++) cout << *it << " ";
        //cout << '\n';
        return (r-l+1)-(st[x].order_of_key({k+1,-1}));
    } 
    int m = (l+r)/2;
    if (b <= m) return search(l,m,a,b,2*x+1,k);
    else if (a > m) return search(m+1,r,a,b,2*x+2,k);
    else {
        return search(l,m,a,m,2*x+1,k) + search(m+1,r,m+1,b,2*x+2,k);
    }
    
}

void update(int l, int r, int x, int idx, int old) {
    st[x].erase({old,idx});
    //cout << old << '\n';
    //for (auto it = st[x].begin(); it != st[x].end(); it++) cout << *it << " ";
    //cout << "PBDS\n";
    st[x].insert({temp[idx+1],idx});
    if (l == r) {
        return;
    }
    int m = (l+r)/2;
    if (idx <= m) update(l,m,2*x+1,idx,old);
    else update(m+1,r,2*x+2,idx,old);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n;
    temp.resize(n+1);
    
    st.resize(4*n);
    F(i,1,n+1) cin >> temp[i];
    stbuild(0,n-1,0);
    cin >> m;
    F(i,0,m) {
        int type;
        cin >> type;
        if (type == 1) {
            int a, b, k;
            cin >> a >> b >> k;
            cout << search(0,n-1,a-1,b-1,0,k) << '\n';
        } else {
            int d, t; cin >> d >> t;
            int old = temp[d];
            
            temp[d] = t;
            update(0,n-1,0,d-1,old);
        }
    }
}