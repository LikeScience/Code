#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i != e; i++)
#define f first
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int t, n, s = 6, x, y=0, sw1=1, sw2=2;
    cin >> t;
    vector<int> v, w1, w2;
    while(s <= 1e6) {
        v.push_back(s);
        w1.push_back(sw1); w2.push_back(sw2);
        y++;
        s+= 16*y + 6;
        sw1+=4*y+1;
        sw2+=4*y+2;
    }
    F(z,0,t) {
        cin >> n; int aw= 0, ab = 0, bw=0, bb=0;
        vector<int>::iterator it = upper_bound(v.begin(), v.end(), n);
        x = it - v.begin();
        //cout << x-1 << " "<< v[x-1] << '\n';
        if (it != v.begin()) {
            aw+= w1[x-1];
            ab+= 4*(x-1)*x + x - w1[x-1];
            bw += w2[x-1];
            bb += v[x-1] - aw - ab - bw;
            
            n -= v[x-1];
        } //cout << aw << " " << ab << " " << bw << " " <<  bb << '\n';
        F (i,0,2) {
            if (n== 0) break;
            if (x*4 + i < n) {
                aw += x*2 + i;
                ab += x*2;
                n -= x*4 + i;
            }
            else {
            ab+=n/2;
            aw += n/2 + (n%2);
            n=0;
            }
        }
         F (i,2,4) {
            if (n== 0) break;
            if (x*4 + i < n) {
                bw += x*2 + 1;
                bb += x*2 + i-1;
                n -= x*4 + i;}
            else {
            bw+=n/2;
            bb += n/2 + (n%2);
            n=0;
            }
        }
        cout << aw << " " << ab << " " << bw << " " <<  bb << '\n';
    }
}