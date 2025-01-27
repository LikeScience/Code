#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define F(i,s,e) for(int i = s; i < e; i++) 

int main() {
    int n, mx = 0; char c;
    cin >> n; vector<string> v(n);
    vector<int> let(26,0), w(26,0);
    F(i,0,n) {
        cin >> v[i];
    }
    int A = int('A');
    F(i,0,7) {
        cin >>c;
        let[int(c)-A]++;
        //cout << int(c)-A << '\n';
    }
    F(i,0,n) {
        int b = 1;
        int s = (int)v[i].length();
        F(j,0,s) {
            int d = int(v[i][j])-A;
            w[d]++;
            if (w[d]> let[d]) {
                b = 0;
                break;
            } 
        }
        if (b && s > mx) mx = s;
        w.assign(26,0);
    }
    cout << ((mx > 3) ? 2*mx : mx) << '\n';
}