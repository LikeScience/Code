#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int l, g, x, r;
    while(1) {
    cin >> l >> g;
    
    if (l== 0 && g == 0) {break;}
    vector<pair<int, int> > v;
    int a, b, m=1, c=1, e;

    for (int i=0; i < g; i++) {
        cin >> x >> r;
        v.push_back({(x-r<0) ? 0 : x-r, (x+r>l) ? l : x+r});
    }
    sort(v.begin(), v.end());
    a=v[0].first;
    b=v[0].second;
    bool h, u=false;
    h= (a!=0);
    
    while (c < g && v[c].first==0)
    {
        if (v[c].second > b) b = v[c].second;
        c++;
        if (c==g) break;
    }
    c--;
    e=v[c].second;
    
    for(int j=c+1; j<g; j++) {
        if (a<=v[j].first && b >= v[j].first) {
            if (e < v[j].second) {
                e = v[j].second;
                u=1;
                if (e==l) {
                    m++;
                    break;
                }
            }
            } else if(u) {
                b=e;
                u=0;
                j--;
                m++;
            } else {
                m=g+1;
                break;
            }
    }
    if(h || (e!=l)) {
        m=g+1;
    }
    cout << g-m <<'\n';
    }
}