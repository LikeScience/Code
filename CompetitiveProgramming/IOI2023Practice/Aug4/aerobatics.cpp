#include "aerobatics.h"
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cmath>
#define F(i,s,e) for (int i = s; i<e; i++)
#define pii pair<int, int> 
#define fi first
#define se second
using namespace std;
using namespace __gnu_pbds;
typedef tree<double, null_type, less<double>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int n, z0;
vector<pii> c;
vector<int> v, pos;
vector<double> an;
pbds a;
random_device rd;

int rdm(int x) {return (rd()%x);}

double eval(double a1, double a2, double t) {
    if (a2<85) return (a1 > a2);
    if (a1<a2/2) return 0;
    double g = (a1-a2)*tan(asin(1)*a1/z0);
    return 1/(1+exp(-t*7*g)); //85; 7 good pair
}

int main() {
    //cout << GetAngle(0, 0, 1, 0, 0, 1);
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    uniform_real_distribution<double> dis(0.0,1.0);
    int repcnt=10000000, avg = 18; vector<int> vb;
    cin >> n >> z0; double besta=0;
    c.resize(n); pos.resize(n);
    an.resize(n-2);
    F(i,0,n) cin >> c[i].fi >> c[i].se;
    F(i,0,n) v.push_back(i);
    random_shuffle(v.begin(), v.end(), rdm);
    //F(i,0,n) cout << v[i] << " ";
    F(i,0,n) pos[v[i]] = i;
    F(i,0,n-2) {
        an[i] = GetAngle(c[v[i+1]].fi, c[v[i+1]].se, c[v[i]].fi, c[v[i]].se, c[v[i+2]].fi, c[v[i+2]].se);
        a.insert(an[i]);
        //cout << an[i] << '\n';
    }
    F(z,0,repcnt) {
        int x = rd()% n, y = rd()% n;
        double aver=0, averl = 0;
        while(x == y) {y = rd()% n;} 
        if (pos[x]>pos[y]) swap(x,y);
        vector<double> ang(6, -1); pbds tst;
        auto it = a.begin();
        F(i,0,avg) {
            aver+= *it;
            tst.insert(*it);
            it++;
        } aver/= avg;
        swap(pos[x], pos[y]);
        //cout << x << y << '\n';
        swap(v[pos[x]], v[pos[y]]);
        if (pos[y] >= 2) {
            ang[0] = GetAngle(c[v[pos[y]-1]].fi, c[v[pos[y]-1]].se, c[v[pos[y]-2]].fi, c[v[pos[y]-2]].se,c[y].fi, c[y].se);
            tst.insert(ang[0]);
            tst.erase(an[pos[y]-2]);
            //cout << an[pos[y]-2] << " " <<  *tst.begin() << " " <<"ADAUWDA\n" ;
        } 
        if (pos[y] >= 1) {
            ang[1] = GetAngle(c[y].fi, c[y].se, c[v[pos[y]-1]].fi, c[v[pos[y]-1]].se,c[v[pos[y]+1]].fi, c[v[pos[y]+1]].se);
            tst.insert(ang[1]);
            tst.erase(an[pos[y]-1]);
            //cout << an[pos[y]-1] << " " <<  *tst.begin() << " " <<"ADAUWDA\n" ;
        }
        if (pos[y] < n-2) {
            //cout << v[pos[y]+1] << " " << y << " " << v[pos[y]+2] << '\n';
            ang[2] = GetAngle(c[v[pos[y]+1]].fi, c[v[pos[y]+1]].se, c[y].fi, c[y].se, c[v[pos[y]+2]].fi, c[v[pos[y]+2]].se);
            tst.insert(ang[2]);
            tst.erase(an[pos[y]]);
            //cout << an[pos[y]] << " " <<  *tst.begin() << " " <<"ADAUWDA\n" ;
        }
        if (pos[x] >= 2) {
            //cout << v[pos[x]-1] << " " << x << " " << v[pos[x]-2] << '\n';
            ang[3] = GetAngle(c[v[pos[x]-1]].fi, c[v[pos[x]-1]].se, c[v[pos[x]-2]].fi, c[v[pos[x]-2]].se, c[x].fi, c[x].se);
            tst.insert(ang[3]);
            tst.erase(an[pos[x]-2]);
            //cout << an[pos[x]-2] << " " <<  *tst.begin() << " " <<"ADAUWDA\n" ;
        }
        if (pos[x] <= n-2) {
            ang[4] = GetAngle(c[x].fi, c[x].se, c[v[pos[x]-1]].fi, c[v[pos[x]-1]].se,c[v[pos[x]+1]].fi, c[v[pos[x]+1]].se);
            tst.insert(ang[4]);
            tst.erase(an[pos[x]-1]);
            //cout << an[pos[x]-1] << " " <<  *tst.begin() << " " <<"ADAUWDA\n" ;
        }
        if (pos[x] < n-2) {
            ang[5] = GetAngle(c[v[pos[x]+1]].fi, c[v[pos[x]+1]].se, c[x].fi, c[x].se, c[v[pos[x]+2]].fi, c[v[pos[x]+2]].se);
            tst.insert(ang[5]);
            tst.erase(an[pos[x]]);
            //cout << an[pos[x]] << " " <<  *tst.begin() << " " <<"ADAUWDA\n" ;
        }
        it = tst.begin();
        F(i,0,avg) {averl += *it; it++;}
        //F(i,0,6) cout << ang[i] << " \n"[i==5];
        averl /= avg;
        //cout << averl << " " << aver << ' ' << eval(averl, aver, /*max(double(z)/double(repcnt-1), 0.9)*/0.8) << '\n';
        if (/*averl > aver*/ dis(rd) <= eval(averl, aver, (double(z)/double(repcnt-1)))) {
        if (pos[y] >= 2) {
            a.erase(an[pos[y]-2]);
            a.insert(ang[0]);
            an[pos[y]-2] = ang[0];
        } 
        if (pos[y] >= 1) {
            a.erase(an[pos[y]-1]);
            a.insert(ang[1]);
            an[pos[y]-1] = ang[1];
        }
        if (pos[y] < n-2) {
            a.erase(an[pos[y]]);
            a.insert(ang[2]);
            an[pos[y]] = ang[2];
        }
        if (pos[x] >= 2) {
            a.erase(an[pos[x]-2]);
            a.insert(ang[3]);
            an[pos[x]-2] = ang[3];
        }
        if (pos[x] <= n-2) {
           a.erase(an[pos[x]-1]);
            a.insert(ang[4]);
            an[pos[x]-1] = ang[4];
        }
        if (pos[x] < n-2) {
            a.erase(an[pos[x]]);
            a.insert(ang[5]);
            an[pos[x]] = ang[5];
        }
            //F(i,0,n) cout << v[i] << " \n"[i==n-1];
            if (*a.begin() > besta) {
                besta = *a.begin();
                vb = v;
            }
        } else {
            swap(pos[x], pos[y]);
            swap(v[pos[x]], v[pos[y]]);
        }
        
    }
    //F(i,0,n-2) cout << *a.find_by_order(i) << " \n"[i==n-3];
    cout << besta << '\n';
    F(i,0,n) cout << vb[i]+1 << '\n';
}