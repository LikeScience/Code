#include <fstream>
#include <string>
#include <vector>

#define F(i,s,e) for(int i = s; i < e; i++)

using namespace std;


int main() {
    fstream ifs ("rosalind_revc.txt", fstream::in);
    string s, t;
    ifs >> s; t = s;
    int l = (int)s.length() - 1;
    F(i,0,(int)s.length()) {
        if (s[i] == 'A') {t[l-i] = 'T';}
        else if (s[i] == 'C') {t[l-i] = 'G';}
        else if (s[i] == 'T') {t[l-i] = 'A';}
        else if (s[i] == 'G') {t[l-i] = 'C';}
    }
    ifs.close();
    fstream ofs ("CASODNA.txt", fstream::out);
    ofs << t << '\n';
    ofs.close();
}
