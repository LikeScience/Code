#include <fstream>
#include <string>
#include <vector>

#define F(i,s,e) for(int i = s; i < e; i++)

using namespace std;


int main() {
    fstream ifs ("rosalind_rna.txt", fstream::in);
    string s, t;
    ifs >> s; t = s;
    F(i,0,(int)s.length()) {
        if (s[i] == 'T') {
            t[i] = 'U';
        }
    }
    ifs.close();
    fstream ofs ("RTDIR.txt", fstream::out);
    ofs << t << '\n';
    ofs.close();
}
