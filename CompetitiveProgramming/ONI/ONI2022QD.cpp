#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;

#define ll long long
#define F(i,s,e) for(int i = s; i < e; i++)

int mx (int a, int b) {return (a >= b) ? a : b;}
int mn (int a, int b) {return (a <= b) ? a : b;}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int P, N, ai, bi, t = 1000001, cnt= 0;
    cin >> P >> N;
    if (P == 1) {
        vector<int> v(t+1,0);
        int endt = 0;
        F(i,0,N) {
            cin >> ai >> bi;
            if (v[ai] == 0 || v[ai] > bi) v[ai] = bi;
        }
        F(i, 1, t+1) {
            if (endt) { 
                if (i == endt) {
                    if (v[i] == 0) {endt = 0;}
                    else {
                        endt = v[i];
                        cnt++;
                    }
                }
                else if (v[i] != 0) {
                    if (v[i] < endt) endt = v[i];
                }
            } else if (v[i] != 0) {
                cnt++; endt = v[i];
            }
        }
        cout << cnt << '\n';
    } else if (P == 2) {
        vector<vector<int> > v(t+1); //v - begins; e - ends
        vector<int> e(t+1,0);
        int pb1 = 0, pb2 = 0; //begins of first task snake
        int pe1 = 0, pe2 = 0; //ends of first task snake
        int pb = 0, d1 = 0, d2 = 0;
        int g = 0; //To see first "snake" group;
        int alt = 1;
        F(i,0,N) {
            cin >> ai >> bi;
            v[ai].push_back(bi);
            e[bi]++;
        }
        bool b = 1;
        F(i,1,t+1) {
            
                if (e[i] == 1 && cnt == 1) {
                   cnt--;
                    if (g == 0 && pb2 != 0) {
                        pb = (pb1 > pb2) ? pb1 : pb2;
                        d1 = pe1 - pb1, d2 = pe2 - pb2;
                    }
                
                }
                else if (e[i] == 2 && cnt == 2) {
                    cnt-= 2;
                    if (g == 0) {
                        d1 = pe1 - pb1, d2 = pe2 - pb2;
                        pb = (pb1 > pb2) ? pb1 : pb2;
                    } 
                }
                else if (e[i] == 1 && cnt == 2) {
                    cnt--;
                    if (pe1 == i) {
                        alt = 1;
                    }
                    else alt = 2;
                } 
        
            F(j, 0, (int)v[i].size()) {
                cnt++;
                if (cnt == 1) {
                    if (pb != 0 && g == 0) {
                        g = 1;
                        if (d1 > d2) {
                            pe1 = v[i][j];
                            alt = 2;
                        } else {
                            pe2 = v[i][j];
                            alt = 1;
                        }
                    }
                    
                    else if (g == 0) {
                    pb1 = i;
                    pe1 = v[i][j]; alt = 2;
                    }
                    else {
                        pe2 = mn (pe1,pe2);
                        pe1 = v[i][j];
                        alt = 2;
                    }
                }
                else if (cnt == 2) {
                    if (g == 0) {
                        if (alt == 2) {
                        if (pb2 == 0) pb2 = i;
                        pe2 = v[i][j];
                        }
                        else {
                            if (pb1 == 0) pb1 = i;
                            pe1 = v[i][j];
                        }                        
                    } else {
                        if (alt == 2) {
                        pe2 = v[i][j];
                        }
                        else {
                            pe1 = v[i][j];
                        }  
                    }
                }
                else if (cnt > 2) {
                    b = 0;
                    break;
                }
               // cout << pe1 << "X" << pe2 << " " << v[i][j] << '\n'; 
            }
        }
        if (b) {
            if (g == 0) {
                
                cout << ((d1 < d2) ? d1 : d2) << '\n';
            } else cout << mn(pe1,pe2)-pb << '\n';

        } else cout << -1 << '\n';
    }
}