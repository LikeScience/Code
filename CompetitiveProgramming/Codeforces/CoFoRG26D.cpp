#include <bits/stdc++.h>
#define ll long long
#define F(i,s,e) for (int i = s; i<e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, n; string s;
    cin >> t;
    F(z,0,t) {
        cin >> s; n = s.length();
        bool b = 1; ll cnt=0;
        F(i,0,n) if (s[i] != 'a') {
            b=0;
            break;
        } if (b) {
            cout << n-1 << '\n';
            continue;
        } int c=0; vector<int> pos;
        F(i,0,n) if (s[i]!= 'a') pos.push_back(i);
        c=(int)pos.size();
        vector<int> d;
        for (int i = 1; i*i<=c; i++) if (!(c%i)) {
            d.push_back(i); if (i*i!=c) d.push_back(c/i);
        } 
        //F(i,0,(int)d.size()) cout << d[i] << '\n';
        F(j,0,d.size()) {
            int a = d[j], dif = pos[a-1]-pos[0]+1; int x = 0, l=0; bool y = 0;
            vector<int> bef(c/a), aft(c/a);
            F(i,0,n) {
                if (x== 0 && s[i]!='a') {
                    bef[0]=i;
                    i+=dif-1;
                    x++; l = i+1;
                }
                else if (s[i]!='a') {
                    bef[x]=aft[x-1]= (i-l);
                    F(k,i,i+dif) if (s[k] != s[bef[0]+k-i]) {
                        y=1;
                        //cout << a << " " << dif << '\n';
                        break;
                    }
                    i+=dif-1;
                    x++; l=i+1;
                }
                if (y) break;
            } aft[x-1] = n-l;
            if (!y) {
                ll mb = (ll)bef[0], ma = (ll)aft[0];
                F(i,1,c/a) mb = min(mb, (ll)bef[i]);
                F(i,1,c/a) ma = min(ma, (ll)aft[i]);
                //F(i,0,c/a) cout << a << " " << bef[i] << " " << aft[i] << '\n';
                cnt+= (ll)1 + ma + mb;
                //cout << ma << " " << mb << '\n';
                if (c/a == 1) {
                    cnt += ((ll)bef[0])*((ll)aft[0]);
                } else {
                    ll mm = bef[1];
                    F(i,2,c/a) mm = min(mm, (ll)bef[i]);
                    mm-=2; ma--; mb--; ll my = min(mm, ma), mz = min(mm, mb);
                    if (mm>=0 && mb>=0 && ma>=0) {
                        ll mmm =  max(my-(mm-mz), (ll)0);
                        if (mz>my) swap(my, mz);
                        cnt += (ll)( min(mm-mz+1,my+1)*(mz+1) );
                        cnt += (ll)( mmm*min(mm-my+1,mz+1) );
                        cnt += (ll)( mmm*(mmm-1)/2 );
                    }
                }
            }
        }
        cout << cnt << '\n';
    }
}