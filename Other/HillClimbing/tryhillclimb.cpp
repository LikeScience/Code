#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
#define pdi pair<double, int>
#define fi first
#define se second
using namespace std;

int n, k, t, rep=1000000;
vector<pdi> v;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    random_device rd;
    ofstream ot("log.txt", ofstream::out);
    int id; double vl; char cc; cin >> n >> k; t = n/k;
    double diff;
    vector<double> scr(t,0), dif(n); set<pdi> m;
    //Just hill climb
    F(i,0,n) {
        cin >> id >> cc >> vl;
        v.push_back({vl, id});
    }
    F(i,0,t) {
        F(j,0,k) scr[i]+=v[k*i+j].fi;
        F(j,0,k-1) {
            dif[k*i+j]=floor(100*(v[k*i+j+1].fi-v[k*i+j].fi)*(v[k*i+j+1].fi-v[k*i+j].fi))/100;
            scr[i]+=dif[k*i+j];
        }
        dif[k*i+k-1]=0;
        m.insert({scr[i],i});
    }
    int p =1000, pp=1000;
    F(i,0,rep) {
        diff = ((--m.end())->fi-m.begin()->fi); ot << diff << '\n';
        int z = rd()%2, d;
        d = (z) ? m.begin()->se : (--m.end())->se;
        int f = d;
        f = rd()%t;
        int i1 = rd()%k, i2 = rd()%k;
        double nsd = scr[d]-v[k*d+i1].fi+v[k*f+i2].fi + (i1>0 ? floor(100*(v[k*f+i2].fi-v[k*d+i1-1].fi)*(v[k*f+i2].fi-v[k*d+i1-1].fi))/100 - dif[k*d+i1-1] : 0) + (i1<k-1 ? floor(100*(v[k*d+i1+1].fi-v[k*f+i2].fi)*(v[k*d+i1+1].fi-v[k*f+i2].fi))/100 - dif[k*d+i1] : 0); 
        double nsf = scr[f]+v[k*d+i1].fi-v[k*f+i2].fi + (i2>0 ? floor(100*(v[k*d+i1].fi-v[k*f+i2-1].fi)*(v[k*d+i1].fi-v[k*f+i2-1].fi))/100 - dif[k*f+i2-1] : 0) + (i2<k-1 ? floor(100*(v[k*f+i2+1].fi-v[k*d+i1].fi)*(v[k*f+i2+1].fi-v[k*d+i1].fi))/100 - dif[k*f+i2] : 0); 
        m.erase({scr[d],d});
        m.erase({scr[f],f});
        m.insert({nsd, d});
        m.insert({nsf, f});
        if (((--m.end())->fi-m.begin()->fi) < diff || rd()%pp >= p) {
            scr[d] = nsd; scr[f] = nsf;
            if (i1>0) dif[k*d+i1-1] = floor(100*(v[k*f+i2].fi-v[k*d+i1-1].fi)*(v[k*f+i2].fi-v[k*d+i1-1].fi))/100;
            if (i2>0) dif[k*f+i2-1] = floor(100*(v[k*d+i1].fi-v[k*f+i2-1].fi)*(v[k*d+i1].fi-v[k*f+i2-1].fi))/100;
            if (i1<k-1) dif[k*d+i1] = floor(100*(v[k*d+i1+1].fi-v[k*f+i2].fi)*(v[k*d+i1+1].fi-v[k*f+i2].fi))/100;
            if (i2<k-1) dif[k*f+i2] = floor(100*(v[k*f+i2+1].fi-v[k*d+i1].fi)*(v[k*f+i2+1].fi-v[k*d+i1].fi))/100;
            swap(v[k*d+i1], v[k*f+i2]);
        }
        else {
            m.erase({nsd, d}); m.erase({nsf, f});
            m.insert({scr[d], d}); m.insert({scr[f], f});
        }
        //cout << (int)m.size() << "DAS\n";
    }
    //cout << m.begin()->fi << " " << (--m.end())->fi << " " << (--m.end())->fi-m.begin()->fi << '\n';
    F(i,0,n) cout << v[i].se << " \n"[i==n-1];
}