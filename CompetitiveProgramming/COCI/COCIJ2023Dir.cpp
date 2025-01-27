#include <bits/stdc++.h>
#define F(i,s,e) for(long long i = s; i < e; i++)

using namespace std;

int n;

int m(int a) {
    while (a < 0) {
        a += n;
    }
    while (a > n) {
        a -= n;
    }
    return a;
}

int main() {
    int q, a, c;
    cin >> n >> q;
    vector<int>  d(n, -1), w(n);
    map<int, int> dis;
    F(i,0,n) {
        cin >> a;
        w[a-1] = i;
        d[a-1] = m(i-(a-1));
        dis[d[a-1]]++;
 
    } 

    /*for (int i = 0; i < n; i++) {
            cout << i+1 << " " << w[i] << '\n';
        }*/

    F(y,0,q) {
        cin >> a >> c;
        dis[d[a-1]]--;
        dis[d[c-1]]--;
        if (dis[d[a-1]] == 0) dis.erase(d[a-1]);
        if (dis[d[c-1]] == 0) dis.erase(d[c-1]);

        swap(w[a-1], w[c-1]);

        d[a-1] = m(w[a-1]-(a-1));
        d[c-1] = m(w[c-1]-(c-1));
        dis[d[a-1]]++;
        dis[d[c-1]]++;
        if ((int)dis.size() == 1) {
            cout << "DA\n";
        } else cout << "NE\n";
        /*for (int i = 0; i < n; i++) {
            cout << i+1 << " " << w[i] << '\n';
        }*/
    }
}