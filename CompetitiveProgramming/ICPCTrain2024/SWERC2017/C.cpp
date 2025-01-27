#include <bits/stdc++.h>

using namespace std;

#define F(i,s,e) for (int i = s; i<e; i++)
#define vvi vector<vector<int>>

vvi mm(vvi &a, vvi &b) {
    int n = a.size();
    vvi o(n, vector<int>(n));
    F(i,0,n) F(j,0,n) F(k,0,n) {
        o[i][j] += a[i][k]*b[k][j]; 
    }
    return o;
}

int main() 
{
    int n, m;
    cin >> n >> m;
    int pn = 1 <<n;
    vvi ans(pn+1, vector<int>(pn+1));
    int i = 0, x = 0;
    vector<int> fib = {1, 1, 2, 3, 5, 8, 13, 21, 34};
    vector<vvi> p(66, vvi(pn+1, vector<int>(pn+1))); //Powers of the matrix

    //Identity matrix
    F(i,0,n) F(j,0,n) {
        ans[i][j] = (i == j);
    }
    //calculating p[0]
    F(i,0,pn) F(j,0,pn) {
        int a = i, b = j;
        p[0][i][j] = 1;
        bool ones = 0; int cnt = 0;
        F(k,0,n) {
            if (!(a%2) && !(b%2)) {
                p[0][i][j]=0;
                continue;
            } else if (a%2 && b%2) {
                cnt++; ones=1;
            } else {
                if (ones) p[0][i][j] *= fib[cnt];
                cnt = 0; ones=0;
            }
            a>>=1; b>>=1;
        }
        if (ones) p[0][i][j] *= fib[cnt];
    }
    //Computing the exponential matrix
    while (x<m) {
        x += (m%2);
         p[i+1]=mm(p[i],p[i]);
        if (m%2) ans = mm(ans, p[i]);
        i++;
        m>>=1;
    }
    cout << ans[pn+1][pn+1];
}