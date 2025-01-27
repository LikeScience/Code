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

bool comp (pair<int, int> &a, pair<int, int> &b) {
    if (a.first < b.first) {return 1;}
    else if (a.first > b.first) {return 0;}
    else if (a.second < 0) {return 1;}
    else if (b.second < 0) {return 0;}
    else return (a.second > b.second);
}

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
        vector<pair<int, int> > v; //v - begins; e - ends
        int pb1 = 0, pb2 = 0; //begins of first task snake
        int pe1 = 0, pe2 = 0; //ends of first task snake
        int pb = 0, d1 = 0, d2 = 0;
        int g = 0; //To see first "snake" group;
        int alt = 1;
        F(i,0,N) {
            cin >> ai >> bi;
            v.push_back(make_pair(ai, bi));
            v.push_back(make_pair(bi, -bi));
        }
        sort(v.begin(), v.end(), comp);
        bool b = 1;
        F(i,0, (int)v.size()) {
            
                if (v[i].second < 0 && cnt == 1) {
                   cnt--;
                    if (g == 0 && pb2 != 0) {
                        pb = (pb1 > pb2) ? pb1 : pb2;
                        d1 = pe1 - pb1, d2 = pe2 - pb2;
                    }
                
                }
                else if (v[i].second < 0 && cnt == 2) {
                    cnt--;
                    if (g == 0) {
                        d1 = pe1 - pb1, d2 = pe2 - pb2;
                        
                    }
                    if (pe1 == v[i].first) {
                        alt = 1;
                    }
                    else alt = 2;
                }
                else if (v[i].second > 0) {
                
                cnt++;
                if (cnt == 1) {
                    if (pb != 0 && g == 0) {
                        g = 1;
                        if (d1 > d2) {
                            pe1 = v[i].second;
                            alt = 2;
                        } else {
                            pe2 = v[i].second;
                            alt = 1;
                        }
                    }
                                                                                                    
                    else if (g == 0) {
                    pb1 = v[i].first;
                    pe1 = v[i].second; alt = 2;
                    }
                    else {
                        pe2 = mn (pe1,pe2);
                        pe1 = v[i].second;
                        alt = 2;
                    }
                }
                else if (cnt == 2) {
                    if (g == 0) {
                        if (alt == 2) {
                        if (pb2 == 0) pb2 = v[i].first;
                        pe2 = v[i].second;
                        if (pe2 > pe1) alt = 1;
                        }
                        else {
                            if (pb1 == 0) pb1 = v[i].first;
                            pe1 = v[i].second;
                            if (pe1 > pe2) alt = 2;
                        }                        
                    } else {
                        if (alt == 2) {
                        pe2 = v[i].second;
                        }
                        else {
                            pe1 = v[i].second;
                        }  
                    }
                }
                else if (cnt > 2) {
                    b = 0;
                    break;
                }
               //cout << pe1 << "X" << pe2 << " " << pb1 << "Y" << pb2 << " " << v[i].second << " " << g << '\n';
               
            }
        }
        if (b) {
            if (g == 0) {
                if (d1 == 0 || d2 == 0) {
                    d1 = pe1 - pb1, d2 = pe2 - pb2;
                }
                cout << ((d1 < d2) ? d1 : d2) << '\n';
            } else cout << mn(pe1,pe2)-pb << '\n';

        } else cout << -1 << '\n';
    }
}