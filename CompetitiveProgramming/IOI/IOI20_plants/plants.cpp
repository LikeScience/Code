#include "plants.h"
#include <vector>
//#include <iostream>

using namespace std;

vector<vector<int> > g;
vector<int> t;
int n, f;

void init(int k, vector<int> r) {
    int gn = 0;
    bool p; // x2 > x1 -> 1; x2 < x1 -> 0
    n = (int) r.size();
    g.resize(n);
    f = 0;
    g[0].push_back(0); g[1].push_back(0); p = r[0];
    t.push_back(r[0]);
    for (int i = 2; i < n; i++) {
        if (r[i-1] == p) {g[i].push_back(g[i-1][0]);}
        else {t.push_back(r[i-1]); g[i].push_back(++gn); g[i-1].push_back(gn);}
        p = r[i-1];
    }
    if (r[n-1] == r[0]) {
        for (int i = n-1; (r[i] == r[n-1]) && i >= 0; i--) {
            if (r[i-1] != r[n-1]) {g[i][1] = 0; f = i;}
            else g[i][0] = 0;
        }
    } else if (r[n-2] != r[n-1]) {
        g[0].push_back(++gn); g[n-1].push_back(gn); f = 0; t[gn] = r[n-1]; 
    } else { g[0].push_back(gn); f = 0;}

    for (int i = 0; i < n; i++) {
        if ((int)g[i].size() == 1) g[i].push_back(-1);
    }
    //cout << f << endl;
    return;
}

int compare_plants(int x, int y) {
    if (n == 2) return (t[0] ? -1 : 1);
    if ((g[x][0] == g[y][0] || g[x][1] == g[y][0])) {
        if (g[y][0] != 0 && (f != 0 || x != 0)) {
            return (t[g[y][0]] ? -1 : 1);
        } else if (g[y][0] != 0 && (f == 0 && x == 0)) {
            return (t[g[y][0]] ? 1 : -1);
        }
        else {
            if ((y >= f && x < f) && f != 0) {
                //cout << 2 <<'\n';
                return (t[g[y][0]] ? 1 : -1);
            } else {
                //cout << 4 <<'\n';
                return (t[g[y][0]] ? -1 : 1);
            }
        }
    } else if ((g[x][0] == g[y][1] || (g[x][1] == g[y][1] && g[y][1] != -1))) {
        if (g[y][1] != 0 && (f != 0 || x != 0)) {
            return (t[g[y][1]] ? -1 : 1);
        } else if (g[y][1] != 0 && (f == 0 && x == 0)) {
            return (t[g[y][1]] ? 1 : -1);
        } else {
            if (y >= f && f != 0) {
                //cout << 3 <<'\n';
                return (t[g[y][1]] ? 1 : -1);
                
            } else {
                //cout << 5 <<'\n';
                return (t[g[y][1]] ? -1 : 1);
                
            }
        }
    }
    return 0;
}