    #include <bits/stdc++.h>
    #define F(i,s,e) for (int i = s; i < e; i++)
    using namespace std;

    #define hs (int)h.size()
    #define ld long double
    vector<ld> x, y;
    int m = 0;

    int cps(ld a1, ld a2, ld b1, ld b2) { //1 if to left; -1 if to right
        ld r = a1*b2-a2*b1;
        return (r<0) ? -1 : (r>0);
    }//cross product sign

    bool cmp (int &a, int &b) { //Sorting by increasing angle 
        int r = cps(x[a]-x[m], y[a]-y[m], x[b]-x[m], y[b]-y[m]);
        if (r) return (r+1)/2;
        return abs(x[a]-x[m]) + abs(y[a]-y[m]) < abs(x[b]-x[m]) + abs(y[b]-y[m]);
    }

    int main() {
        ios::sync_with_stdio(0); cin.tie(0);
        __builtin_ia32_ldmxcsr(40896);
        int n; cin >> n; vector<int> v, h;
        x.resize(n); y.resize(n);
        F(i,0,n) cin >> x[i] >> y[i];
        F(i,1,n) if (y[i] < y[m] || (y[i] == y[m] && x[i] < x[m])) m = i;
        F(i,0,n) if (i!=m) v.push_back(i); 
        sort(v.begin(), v.end(), cmp); v.push_back(m);  
        h = {m,v[0]}; 
        F(i,1,n) {
            while (hs > 2 && cps(x[h[hs-1]]-x[h[hs-2]],y[h[hs-1]]-y[h[hs-2]],
                                x[v[i]]-x[h[hs-1]],y[v[i]]-y[h[hs-1]]) == -1) h.pop_back(); //If right turn
            h.push_back(v[i]);
        } h.pop_back(); //Remove repeated original vertex
        int s; cin >> s;
        vector<ld> xs(s), ys(s); int cnt=0;
        F(i,0,s) cin >> xs[i] >> ys[i]; 
        F(i,0,s) if (ys[i]>=y[m]) {
            bool bb = 0; 
            F(j,1,hs-1) {
                /*cout << i << " " << j << ' '
                <<  cps(xs[i]-x[m],ys[i]-y[m],x[h[j]]  -x[m],y[h[j]]  -y[m]) << " "
                <<  cps(xs[i]-x[m],ys[i]-y[m],x[h[j+1]]-x[m],y[h[j+1]]-y[m]) << " "
                <<  cps(xs[i]-x[h[j]],ys[i]-y[h[j]],x[h[j+1]]-xs[i],y[h[j+1]]-ys[i]) << " "
                <<'\n';*/
                if (cps(xs[i]-x[m],ys[i]-y[m],x[h[j]]  -x[m],y[h[j]]  -y[m]) <=0 &&
                    cps(xs[i]-x[m],ys[i]-y[m],x[h[j+1]]-x[m],y[h[j+1]]-y[m]) >=0 &&
                    cps(xs[i]-x[h[j]],ys[i]-y[h[j]],x[h[j+1]]-xs[i],y[h[j+1]]-ys[i]) <=0) {bb=1; break;}
            }
            if (bb) cnt++;
        } cout << cnt << '\n';
    } 