#include <bits/stdc++.h>

using namespace std;

int main() {
    fstream f("rosalind_gc.txt", fstream::in);
    
    string s, l = ".";
    double gc = 0, sz = 0, r;
    pair<double, string> mx;
    while(f >> s) {
        if (s[0] == '>') {
            if (l != ".") {
                r= 100*gc/sz;
                if (r > mx.first) {
                    mx.first = r;
                    mx.second = l;
                }
            }
            gc = 0; sz = 0;
            l.assign(s, (int)s.length()-4, 4);
        }
        else {
            sz += double(s.length());
            for(int i = 0; i < (int)s.length(); i++) {
                if (s[i] == 'C' || s[i] == 'G') gc += 1.0;
            }
        }
    }
    r= 100*gc/sz;
    if (r > mx.first) {
        mx.first = r;
        mx.second = l;
    }
    f.close();
    fstream o("CGCC.txt", fstream::out);
    o << "Rosalind_" << mx.second << '\n' << mx.first << '\n';
    o.close();

}