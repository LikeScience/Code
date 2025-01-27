#include <bits/stdc++.h>
#define F(i,s,e) for (int i= s; i<e; i++)
#define fi first
#define se second
#define pii pair<int, int>
using namespace std;

int main() {
    int n, m, k;
    vector<vector<int> > am;
    fstream fin("cowmbat.in", fstream::in);
    string s; vector<int> v;
    fin >> n >> m >> k;
    fin >> s;
    F(i,0,n) {
        v.push_back(s[i]-int('a'));
    }
    am.assign(m, vector<int>(m));
    F(i,0,m) F(j,0,m) fin >> am[i][j];
    fin.close();
    F(i,0,m) {
        vector<bool> ad(m, 0); 
        priority_queue<pii, vector<pii>, greater<pii> > p;
        p.push(make_pair(0,i));
        while (!p.empty()) {
            if (ad[p.top().se]) {
                p.pop();
            } else {
                int x = p.top().se;
                ad[x] = 1;
                p.pop();
                F(j,0,m) if (!ad[j]){
                    if (am[i][j] > am[i][x] + am[x][j]) {
                        am[i][j] = am[i][x] + am[x][j]; 
                    }p.push(make_pair(am[i][x] + am[x][j], j));
                }
            }
        }  
    }
    //F(i,0,m) {F(j,0,m) {cout << am[i][j] << " ";} cout << '\n';}
    vector<vector<int> > d(m, vector<int>(n+1, 0));
    F(i,0,m) F(j,1,n+1) {
        d[i][j] = d[i][j-1] + am[v[j-1]][i];
    }
    vector<vector<int> > dp(n, vector<int>(m, 1e9)); vector<int> mn(n, 1e9);
    F(i,k-1,min(n, 2*k-1)) {
        F(j,0,m) {
            dp[i][j] = d[j][i+1];
            mn[i] = min(mn[i], dp[i][j]);
        }
    }
    F(i,2*k-1,n) {
        F(j,0,m) {
            dp[i][j] = min(dp[i-1][j] + am[v[i]][j], mn[i-k] + d[j][i+1] - d[j][i-k+1]);
            mn[i] = min(mn[i], dp[i][j]);
        }
    }
    /*F(i,0,n) {
        F(j,0,m) {
            cout << dp[i][j] << ' ';
        } cout << '\n';
    }*/
    fstream fout("cowmbat.out", fstream::out);
    fout << mn[n-1] << '\n';
}