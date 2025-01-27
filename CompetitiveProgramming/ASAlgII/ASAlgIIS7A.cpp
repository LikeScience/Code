#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i != e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int n, m, s=0, on = -100000, z;
    vector<int> op;
    cin >> n;
    F(i,0,n) {
        cin >> z;
        if (z<0) {
            if (z%2 && z>on) on=z;
           // cout << on << '\n';
        } else {
            if (z%2) {
                op.push_back(z);
            } else {
                s+=z;
            }
        }
    }
        sort(op.begin(), op.end());
        if (op.size()==0){
            s+=on;
        } else {
            if (op.size()%2) {
                s+=op[0];
            } else if (op[0]>-on) {
                s+=op[0]+on;
            }
            F(i,1,op.size()) {
                s+=op[i];
            }
        }
    
    cout << s << '\n';
}