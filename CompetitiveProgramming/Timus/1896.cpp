#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int MAXN = 1<<20;

vector<int> ft(2*MAXN+1,0);

void ftu(int x, int a) {
    while (x<=MAXN) {
        ft[x]+=a;
        x += x & -x;
    }
}

int fte(int x) {
    int ans = 0;
    while (x>0) {
        ans += ft[x];
        x -= x & -x;
    }
    return ans;
}


int ftlb(int a) {
    int x = 0, sum=0;
    for (int i = MAXN; i>0; i>>=1) {
        if (sum+ft[x|i]<a) {
            x |= i;
            sum+= ft[x|i];        
        }
    }
    //cout << x << '\n' << flush;
    return x;
}

int main() {
    int n, k, x=0, ans=0;
    cin >> n >> k;
    F(i,1,n+1) ftu(i,1);
    F(i,1,n+1) {
        x= (x+k)%(n+1-i);
        if (x == 0) x = n+1-i;
        //cout << x << " " << flush;
        int v = ftlb(x)+1;
        //cout << v << '\n' << flush;
        
        //cout << '\n';
        ftu(v,-1);
        //F(i,1,n+10) cout << fte(i) << " ";
        ans ^= abs(i-v);
        //cout << '\n';
        x--;
    }
    cout << ans << '\n';
}