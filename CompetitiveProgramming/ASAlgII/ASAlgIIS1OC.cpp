#include <bits/stdc++.h>
#define F(i,s,e) for(long long i = s; i < e; i++)

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    long long t, n, z, T, c, li, l, mi, h, ni, ri, nv, rv, b;
    cin >> t;
    //ofstream ot("outS1OC.txt", ofstream::out);
    F(y,0,t) {
        cin >> n;
        vector<long long> a;
        T = 0; l = 0; b = 0;

        F(i,0,n) {
            cin >> z; a.push_back(z);
            T += z;
            if (z > l) {
                l = z; li = i;
            }
        }
        cout << (l > (T-l) ? (T-l) : T/2) <<'\n';
        //ot << (l > (T-l) ? (T-l) : T/2) <<'\n';
        if (T == 0) continue;

        c = l;
        if (l >= T/2) {
            h = l - T/2;
            mi = (li+1)%n;
        }
        else {for(long long i = (li+1)%n; i != li; i = (i+1) % n) {
            c += a[i];
            if (c > T/2) {
                mi = (i+1) % n;
                h = c - T/2;
                break;
            }
        }}
        //cout << h << " "<< l <<'\n';
        //continue;
        ri = mi; rv = 0; while (1) {
                if (a[ri] != 0) break;
                ri = (ri+1) % n;
        }     
        F(nv, h, l) {
            if (ri != li) {
                cout << li+1 << " " << ri+1 << '\n';
                //ot << li+1 << " " << ri+1 << '\n';
            }
            rv++;
            if (rv == a[ri]) while (1){
                rv = 0;
                ri = (ri+1) % n;
                 if (a[ri] != 0) break;
            }
        }

        ni = (li+1)%n; while (1) {
                if (a[ni] != 0) break;
                ni = (ni+1) % n;
        } nv = 0;
        if (l < T/2) while(ri != li) {
            cout << ni+1 << " " << ri+1 << '\n';
            //ot << ni+1 << " " << ri+1 << '\n';
            rv++;
            if (rv == a[ri]) while (1) {
                rv = 0;
                ri = (ri+1) % n;
                if (a[ri] != 0) break;
            }
            nv++;
            if (nv == a[ni]) while (1) {
                nv = 0;
                ni = (ni+1) % n;
                if (a[ni] != 0) break;
            }
        }
        if (l < T/2 && ni != mi) while(rv < h) {
            cout << ni+1 << " " << ri+1 << '\n';
            //ot << ni+1 << " " << ri+1 << '\n';
            rv++;
            nv++;
            if (nv == a[ni]) while(1){
                nv = 0;
                ni = (ni+1) % n;
                if (ni == mi) {b = 1; break;}
                if (a[ni] != 0) break;
            }
            if (b) break;
        }
    }
}