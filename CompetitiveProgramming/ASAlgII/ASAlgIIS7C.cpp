#include <bits/stdc++.h>
#define F(z,s,e) for(int z = s; z != e; z++)
using namespace std;


int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int n, M=1, x, y, h;
    cin >> n;
    vector<int> m, ip(362, 1), pr, fac;
    F(i,2,362) if (ip[i]) {
        pr.push_back(i);
        for (int j = i*i; j <= 361; j+=i) ip[j]=0; 
    }
    map<int, int> d;
    F(z,0,n) {
        cin >> y;
        x = y; h=0;
        while(x>1) {
            if (h==pr.size()) {
                fac.push_back(x);
                break;
            }
            if (x%pr[h]==0) {
                while (x%pr[h]==0) x /= pr[h];
                fac.push_back(pr[h]);  
                h++;
            } else h++;
        }
        x=1;
        F(i,0,(int)fac.size()) {
            if (d.find(fac[i])!=d.end()) {
                x=max(x,d[fac[i]]+1);
            }
        }
        F(i,0,(int)fac.size()) d[fac[i]]=x;
        if (x>M) M=x;
        fac.clear();
    }
    cout << M << '\n';
}