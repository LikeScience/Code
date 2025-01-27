#include <bits/stdc++.h>
#define F(i,s,e) for(int i = s; i != e; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int n, d, x = 0, l = -1, j= 0;
    string s;
    cin >> n >> d;
    cin >> s;
    F(i,1,n-1) {
        x++;
        if (x == d) {
            if (s[i] == '1') {
                l=-1;
                x=0;
                j++;
            } else if (l != -1) {
                x=i-l;
                l=-1;
                j++;
            }else {
                cout << "-1\n";
                return 0;
            }
        } else if(s[i] == '1') l = i;
        //cout<<x<<'\n';
    }
    cout << j+1 << '\n';
    return 0;
}