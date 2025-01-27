#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)

using namespace std;

int mi = 0;
vector<double> x, y, an;

bool comp (const int &a, const int &b) {
    if (an[a] != an[b]) return an[a] > an[b];
    return y[a] < y[b];
}

int main() {
    int n; cin >> n;
    double mn;
    x.resize(n), y.resize(n);
    vector<int> vi, v, o;
    F(i,0,n) {
        cin >> x[i] >> y[i];
        //searching for bottom point
        if (i == 0) mn = y[i];
        else if (y[i] < mn) {
            mn = y[i]; mi = i;
        }
    }
    F(i,0,n) vi.push_back(i);
    //cosine of the angle between bottom point, horizontal line crossing the bottom point and the ith point
    F(i,0,n) an.push_back((i == mi) ? -2 : (x[i]-x[mi])/sqrt((x[i]-x[mi])*(x[i]-x[mi])+ (y[i]-y[mi])*(y[i]-y[mi])));
    //sorting in decreasing order by cosine (increasing by angle) (and if tied put first the closest)
    sort(vi.begin(), vi.end(), comp);
    
    //excluding colinear points
    F(i,0,n-1) if (an[vi[i+1]]!= an[vi[i]]) v.push_back(vi[i]);
    v.push_back(vi[n-1]);
    F(i,0,(int)v.size()) cout << v[i] << " " << an[v[i]] << '\n';
    //extending the hull
    o.push_back(mi);
    for (int i : v) {
        if ((int)o.size()>2) for (int j = (int)o.size()-1; j>1; j--) {
            if (((x[o[j]]-y[o[j-1]])*(y[i]-y[o[j]])-(y[o[j]]-y[o[j-1]])*(x[i]-y[o[j]]))<=0) {o.pop_back();}
            else break;
        }
        o.push_back(i);
    }
    o.pop_back();
    F(i,0,(int)o.size()) cout << o[i] << " \n"[i==(int)o.size()-1];
}


