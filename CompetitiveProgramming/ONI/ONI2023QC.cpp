#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
#define ll long long
#define fi first
#define se second
using namespace std;

ll c(char A, char B) {
    if (B == '?') return 1;
    else return int(A==B);
}

vector<int> dc(int x, vector<int> &pt) {
    vector<int> v(11); 
    for (int i = 10; i>=0; i--) {
        v[i] = int(x/pt[i]);
        x -= int(x/pt[i])*pt[i];
    }
    return v;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int p, t, n;
    cin >> p >> t;
    if (p==1) {
        F(z,0,t) {
            cin >> n; bool bl=0;
            vector<char> v(n);
            vector<ll> aa(n), ab(n), av(n), ba(n), bb(n), bv(n), va(n), vb(n), vv(n);
            F(i,0,n) cin >> v[i];
            if (n ==1 ) {cout << (v[0] == '?' ? 3 : 1) << '\n'; continue;}
            aa[1] = (c('A',v[0]) && c('A',v[1]));
            ab[1] = (c('A',v[0]) && c('B',v[1]));
            av[1] = (c('A',v[0]) && c('V',v[1]));
            ba[1] = (c('B',v[0]) && c('A',v[1]));
            bb[1] = (c('B',v[0]) && c('B',v[1]));
            bv[1] = (c('B',v[0]) && c('V',v[1]));
            va[1] = (c('V',v[0]) && c('A',v[1]));
            vb[1] = (c('V',v[0]) && c('B',v[1]));
            vv[1] = (c('V',v[0]) && c('V',v[1]));
            F(i,2,n) {
                aa[i]= (ba[i-1] + va[i-1])*c('A',v[i]); 
                ab[i]= (ba[i-1] + aa[i-1])*c('B',v[i]); 
                av[i]= (aa[i-1] + va[i-1])*c('V',v[i]);
                ba[i]= (ab[i-1] + bb[i-1])*c('A',v[i]);
                bb[i]= (ab[i-1] + vb[i-1])*c('B',v[i]);
                bv[i]= (bb[i-1] + vb[i-1])*c('V',v[i]); 
                va[i]= (av[i-1] + vv[i-1])*c('A',v[i]);
                vb[i]= (bv[i-1] + vv[i-1])*c('B',v[i]);
                vv[i]= (av[i-1] + bv[i-1])*c('V',v[i]);
                if (aa[i] > 1e10) aa[i] = 1e10+1;
                if (ab[i] > 1e10) ab[i] = 1e10+1;
                if (av[i] > 1e10) av[i] = 1e10+1;
                if (ba[i] > 1e10) ba[i] = 1e10+1;
                if (bb[i] > 1e10) bb[i] = 1e10+1;
                if (bv[i] > 1e10) bv[i] = 1e10+1;
                if (va[i] > 1e10) va[i] = 1e10+1;
                if (vb[i] > 1e10) vb[i] = 1e10+1;
                if (vv[i] > 1e10) vv[i] = 1e10+1;
            }
            if (aa[n-1] + ab[n-1] + av[n-1] + ba[n-1] + bb[n-1] + bv[n-1] + va[n-1] + vb[n-1] + vv[n-1] > 1e10) bl=1;
            if (bl) {cout << "grande" << '\n';}
            else cout << aa[n-1] + ab[n-1] + av[n-1] + ba[n-1] + bb[n-1] + bv[n-1] + va[n-1] + vb[n-1] + vv[n-1] <<'\n';
        }
    } else {
        F(z,0,t) { //B->0; A->1; V->2.
            cin >> n;//cout << "DWD" << '\n';
            char c;
            vector<int> v(n);
            vector<vector<int> > ch(3, vector<int>(3));
            vector<int> pt = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049}; //Till 0 to 10
            ch[0][0] = 1; ch[1][0] = 1; ch[2][0] = 1; ch[0][1] = 0; ch[1][1] = 1; ch[2][1] = 2; ch[0][2] = 0; ch[1][2] = 0;ch[2][2] = 1;
            F(i,0,n) {
                cin >> c;
                if (c == 'B') {v[i]=0;}
                else if (c== 'A') {v[i]=1;}
                else v[i] = 2;
            } int t=0;
            if (n==1) {cout << c << '\n';continue;} 
            vector<int> nm1f = dc(n-1,pt); 
            //vector<int> y = dc(n-1,pt);
            //F(i,0,(int)y.size()) cout << y[i] << " ";
            F(i,0,n) {
                int x = 1;
                //vector<int> y = dc(i,pt);
            //F(i,0,(int)y.size()) cout << y[i] << " ";
                vector<int> ifa = dc(i,pt);
                F(i,0,11) x *= ch[nm1f[i]][ifa[i]];
                t = (t + ((n % 2) ? 1 : -1) * x*v[i]) % 3;
            }
            if (t == 0) cout << 'B' << '\n';
            else if (t == 1 || t == -2) cout << 'A' << '\n';
            else cout << 'V' << '\n';
            //vector<int> x = dc(14,pt);
            //F(i,0,(int)x.size()) cout << x[i] << " ";
        }
    }

}