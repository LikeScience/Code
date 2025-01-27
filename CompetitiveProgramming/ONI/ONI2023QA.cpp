#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
#define ll long long
#define fi first
#define se second
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int p, n, m,t,k;
    char x;
    cin >> p >> n >> m;
    if (p==1) {
        vector<vector<bool> > v(n, vector<bool>(m,0));
        F(i,0,n) F(j,0,m) {cin >> x; v[i][j] = (x=='#');}
        cin >> t;
        F(i,0,t) {
            cin >> k; int l=0, c=0;
            F(i,0,k) {
                cin >> x;
                if (x == 'D' && c<m-1 && !v[l][c+1]) c++;
                if (x == 'B' && l<n-1 && !v[l+1][c]) l++;
                if (x == 'E' && c>0 && !v[l][c-1]) c--;
                if (x == 'C' && l>0 && !v[l-1][c]) l--;
            }
            cout << l+1 << " " << c+1 << '\n';
        }
    } else {
        vector<vector<char> > v(n, vector<char>(m));
        vector<vector<bool> > cv(n, vector<bool>(m,0));
        map<char, pair<int, int> > dir; dir.insert({'D',{0,1}}); dir.insert({'B',{1,0}}); dir.insert({'E',{0,-1}}); dir.insert({'C',{-1,0}}); 
        F(i,0,n) F(j,0,m) {cin >> v[i][j];}
        cin >> t;
        F(y,0,t) {
            bool bb=0; char di;
            cin >> k; int l=0, c=0;
            vector<char> is(k);
            F(i,0,k) cin >> is[i];
            F(i,0,k+1) {
                if (v[l][c] != '.' && v[l][c] != '#') {
                    vector<pair<int, int> > cs = {{l,c}};
                    di = v[l][c];
                    cv[l][c]=1;
                    while(1) {
                        if (l+dir[di].fi > n-1 || l+dir[di].fi < 0 || c+dir[di].se > m-1 || c+dir[di].se < 0 || v[l+dir[di].fi][c+dir[di].se] == '#') {
                            F(z,0,(int)cs.size()) cv[cs[z].fi][cs[z].se] =0;
                            break;
                        } else {
                            l += dir[di].fi; c += dir[di].se;
                            if (v[l][c] != '.') {
                                if (cv[l][c]) {
                                    bb=1;
                                    break;
                                }
                                cv[l][c]=1;
                                cs.push_back({l,c});
                                di = v[l][c];
                            }
                        }
                        //cout << l << " " << c << '\n';
                    }
                }
                if (i != k) {
                if (is[i] == 'D' && c<m-1 && v[l][c+1] != '#') c++;
                if (is[i] == 'B' && l<n-1 && v[l+1][c] != '#') l++;
                if (is[i] == 'E' && c>0 && v[l][c-1] != '#') c--;
                if (is[i] == 'C' && l>0 && v[l-1][c] != '#') l--;
                //cout << l << " " << c << '\n';
                }
            } if (bb) {cout << "ciclo" << '\n';}
            else cout << l+1 << " " << c+1 << '\n';
        }
    }

}