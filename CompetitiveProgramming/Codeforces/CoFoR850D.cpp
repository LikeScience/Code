#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i != e; i++)
#define f first
#define ll long long
using namespace std;

struct ots {
    int a1;
    char c1;
    int a2;
    char c2;
};

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int t, m;
    string s;
    
    cin >> t;
    
    F(z,0,t) {
        cin >> m;
        vector<vector<int> > v(m,vector<int>(3,0));
         vector<ots > ot;
        ots o;
        vector<int> wpi, wpn, ipw, ipn, npw, npi;
        F(i,0,m) {
            cin >> s;
            F(j,0,3) {
                if (s[j] == 'w') {
                    v[i][0]++;
                } else if (s[j] == 'i') {
                    v[i][1]++;
                } else if (s[j] == 'n') {
                    v[i][2]++;
                }
            }
                if (v[i][0]==3) {
                    wpi.push_back(i);
                    wpn.push_back(i);
                }
                else if (v[i][1]==3) {
                    ipw.push_back(i);
                    ipn.push_back(i);
                }
                else if (v[i][2]==3) {
                    npi.push_back(i);
                    npw.push_back(i);
                } else if (v[i][0]==2) {
                    if (v[i][1]==1) {
                        wpn.push_back(i);
                    } else  {
                        wpi.push_back(i);
                    }
                } else if (v[i][1]==2) {
                    if (v[i][0]==1) {
                        ipn.push_back(i);
                    } else  {
                        ipw.push_back(i);
                    }
                }
                else if (v[i][2]==2) {
                    if (v[i][0]==1) {
                        npi.push_back(i);
                    } else  {
                        npw.push_back(i);
                    }
                }
        } 
        while(wpi.size() && ipw.size()) {
            o.a1= wpi[(int)wpi.size()-1];
            o.a2= ipw[(int)ipw.size()-1];
            o.c1 = 'w';
            o.c2= 'i';
            ot.push_back(o);
            wpi.pop_back();
            ipw.pop_back();
        }
        while(wpn.size() && npw.size()) {
            o.a1= wpn[(int)wpn.size()-1];
            o.a2= npw[(int)npw.size()-1];
            o.c1 = 'w';
            o.c2= 'n';
            ot.push_back(o);
            wpn.pop_back();
            npw.pop_back();
        }
        while(ipn.size() && npi.size()) {
            o.a1= ipn[(int)ipn.size()-1];
            o.a2= npi[(int)npi.size()-1];
            o.c1 = 'i';
            o.c2= 'n';
            ot.push_back(o);
            ipn.pop_back();
            npi.pop_back();
        }
        while(wpi.size()) {
            o.a1= wpi[(int)wpi.size()-1];
            o.a2= ipn[(int)ipn.size()-1];
            o.c1 = 'w';
            o.c2= 'i';
            ot.push_back(o);
            o.a1 = npw[(int)npw.size()-1];
            o.c1 = 'n';
            o.c2 = 'w';
            ot.push_back(o);
            wpi.pop_back();
            ipn.pop_back();
            npw.pop_back();
        } while (ipw.size()) {
            o.a1= ipw[(int)ipw.size()-1];
            o.a2= wpn[(int)wpn.size()-1];
            o.c1 = 'i';
            o.c2= 'w';
            ot.push_back(o);
            o.a1 = npi[(int)npi.size()-1];
            o.c1 = 'n';
            o.c2 = 'i';
            ot.push_back(o);
            ipw.pop_back();
            wpn.pop_back();
            npi.pop_back();
        }
        cout << (int)ot.size() << '\n';
        F(i,0,ot.size()) {
            cout << ot[i].a1+1 << " " << ot[i].c1 << " " << ot[i].a2+1 << " " << ot[i].c2 << "\n";
        }
    }
}