#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;
#define ll long long
#define vi vector<int>

int n;
map<int, map<int, int> > ft;

ll fte(int d, int m) {
    ll ans=0;
    int i = d, j = m;
    while (i > 0) {
        i -= (i&-i);
        while (j > 0) {
            j -= (j&-j);
            ans+=(ll)ft[i][j];
        }
    }
    return ans;
}


void ftu(int d, int m, int v) {
    int i = d, j = m;
    while (i <= n) {
        i += (i&-i);
        while (j <=n) {
            j += (j&-j);
            ft[i][j]+=v;
        }
    }
}


int main() {
    cin >> n;
    string s; char c, k;
    F(z,0,n+1) {
        getline(cin, s);
        //cout << s << '\n';
        F(i,0,(int)s.length()) {
            string w = "";
           int d = 0, pp = 1; k = s[i++];
            while (i < (int)s.length()) {
                if (s[i]!= ' ') {w+=s[i++];}
                else break;
            }
            for (int j = (int)w.length()-1; j >= 0;j-- ) {
                d += s[j]*(pp); pp*=10;
            }
            //cout << w << '\n';
            if (k=='+') {
                ftu(z,d,1);
                cout << "Hi \n";
            }
            else if (k=='-') {
                ftu(z,d,-1);
            }
        }
    }
    ll x = 0, d;
    F(i,1,n+1) F(j,1,n+1) cout << ft[i][j] << '\n';
    F(i,0,n) {
        cin >> d;
        cout << fte(n,x) << " " << fte(d-1,x) << "\n";
        x = (x + fte(n,x)-fte(d-1,x))%((ll)n);
    }
    cout << x << '\n';
}