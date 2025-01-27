#include <bits/stdc++.h>
#define F(i,s,e) for (int i = s; i<e; i++)

#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    F(z,0,t) {
        string s, w;
        cin >> s >> w;
        int cnt=0, cnt2=0;
        string a = "", b = "";
        for (auto c : s) {
            if (c == 'B') cnt++;
            else a += c;

        }
        for (auto c : w) {
            if (c == 'B') cnt2++;
            else b += c;
        }
        if ((cnt %2) != (cnt2%2)) {cout << "NO" << '\n'; continue;}
        int as = a.size(), bs = b.size();
        vector<bool> av(as, 1), bv(bs, 1);
        
        while(1) {
            bool brk = 0; 
            char p; int pi = -1;brk=0;
        F(i,0,as) {
           
            if (av[i]) {
                if (pi != -1 && a[i] == p) {
                    av[pi] = av[i] = 0;
                    brk=1;
                    break;
                    
                }
                pi = i;
                p = a[i];

            }
           

            
        }
            if (!brk) break;
        }
       while(1) {
            bool brk = 0;
             char p ;int pi = -1;brk=0;
        F(i,0,bs) {
           
            
            if (bv[i]) {
                if (pi != -1 && b[i] == p) {
                    bv[pi] = bv[i] = 0;
                    brk=1;
                    break;
                    
                }
                pi = i;
                p = b[i];

            }
           
            

        }
           if (!brk) break;
        }
        string fa = "", fb = "";
        F(i,0,as) if (av[i]) fa += a[i];
        F(i,0,bs) if (bv[i]) fb += b[i];
        cout << ((fa == fb) ? "YES" : "NO" ) << '\n';


    }   

}