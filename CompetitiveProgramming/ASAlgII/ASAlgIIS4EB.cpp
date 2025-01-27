#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i != e; i++)
#define f first
#define s second
using namespace std;

double md(double a) {
    return (a < 0) ? -a : a;
}

int main() {
    //ios::sync_with_stdio(0); cin.tie(NULL);
    int S, c, z, t=0;
    double a, m;
    while (cin >> c >> S) {
        a = 0.00000; m=0.00000 ; t++;
        cout << "Set #" << t << '\n';
        vector<pair<int, int > > v;
        vector<vector<int> > h(c, {0});
        F(i,1,S+1) {
            cin >> z;
            a+=z;
            v.push_back({z,i});
        } a/= c;
        sort(v.begin(), v.end(), greater<pair<int, int> >());
        F(i,0,c) {
            if (i >= S) break;
            h[i][0]+=v[i].f;
            h[i].push_back(v[i].f);
            
        }
        F(i,c,2*c) {
            if (i >= S) break;
            h[2*c-i-1][0]+=v[i].f;
            h[2*c-i-1].push_back(v[i].f);
        }
        F(i,0,c) {
            cout << " " << i << ":";
            F(j,1,(int)h[i].size()) cout << " " << h[i][j];
            m += md(a-h[i][0]);
            cout << '\n';
        }
        printf("IMBALANCE = %.5f\n\n", m);
        //cout << "IMBALANCE: = " << m <<"\n\n";
    }
}