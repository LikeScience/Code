#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i < e; i++)
#define ll long long
#define f first
#define s second
using namespace std;

struct se {
    int m;
    int u;
    int i;
};

vector<se> st;
vector<int> t;

void c(int l, int r, int x) {
  if (l==r) {
    st[x].m = t[l];
    st[x].i=l;
    return;
  }
  c(l,(l+r)/2,2*x+1);
  c((l+r)/2+1,r,2*x+2);
  if (st[2*x+1].m < st[2*x+2].m) {
    st[x].m = st[2*x+1].m;
    st[x].i = 2*x+1;
  } else {
    st[x].m = st[2*x+2].m;
    st[x].i = 2*x+2;
  }
  return;
}

int m(int l, int r, int x) {
    if (l==r) {
        st[x].m = 1000000000;
        return l;
    }
    int d;
    if (st[x].i==2*x+1) {
        d =m(l,(l+r)/2,2*x+1);
    } else {
        d = m((l+r)/2+1,r,2*x+2);
    }
    if (st[2*x+1].m-st[2*x+1].u < st[2*x+2].m-st[2*x+2].u) {
        st[x].m = st[2*x+1].m-st[2*x+1].u;
        st[x].i = 2*x+1;
    } else {
        st[x].m = st[2*x+2].m-st[2*x+2].u;
        st[x].i = 2*x+2;
    }
    return d;
}

void u(int l, int r, int x, int dl, int dr) {
  if (l==dl && r== dr) {
    st[x].u += 1;
    return;
  }
  if (dr <= (l+r)/2) {
    u(l,(l+r)/2,2*x+1,dl,dr);
  } else if (dl>= (l+r)/2 +1) {
    u((l+r)/2+1,r,2*x+2,dl,dr);
  } else {
    u(l,(l+r)/2,2*x+1,dl,(l+r)/2);
    u((l+r)/2+1,r,2*x+2,(l+r)/2+1,dr);
  }
  if (st[2*x+1].m-st[2*x+1].u < st[2*x+2].m-st[2*x+2].u) {
    st[x].m = st[2*x+1].m-st[2*x+1].u;
    st[x].i = 2*x+1;
  } else {
    st[x].m = st[2*x+2].m-st[2*x+2].u;
    st[x].i = 2*x+2;
  } return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    se a = {0,0,-1};
    st.assign(400000, a);
    int n, k;
    ll d;
    cin >> n >> d >> k;
    int o=n;
    ll v[n]; t.assign(n,0);
    vector<int> dl(n), dr(n);
    vector<bool> b(n,1);
    deque<pair<ll, int> > s;
    F(i,0,n) {
        cin >> v[i];
        while (s.size() && s[0].f < v[i]) s.pop_front();
        t[i]+=s.size();
        s.push_back({v[i]+d,i});
        dl[i] = s[0].s;
    }
    s.clear();
    for (int i = n-1; i>=0; i--) {
        while (s.size() && s[0].f > v[i]) s.pop_front();
        t[i]+=s.size();
        s.push_back({v[i]-d,i});
        dr[i] = s[0].s;
    }
    c(0,n-1,0);
    //F(i,0,2*n+1) cout << st[i].m << '\n';
    while(o && st[0].m-st[0].u < k) {
        o--;
        int x=m(0,n-1,0);
        //cout << x << '\n';
        b[x]=0;
        u(0,n-1,0,dl[x],dr[x]);
    }
    bool bo =0;
    cout << o <<'\n';
    if(o) F(i,0,n) if (b[i]) {
            if (bo) {cout << " ";}
            else bo=1;
            cout << i+1;
    }
    cout << '\n';
}