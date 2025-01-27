#include <fstream>
#include <string>
#include <vector>

#define F(i,s,e) for(int i = s; i < e; i++)

using namespace std;


int main() {
    fstream ifs ("rosalind_dna.txt", fstream::in);
    string s;
    int a=0, c=0, t=0, g=0;
    ifs >> s;
    F(i,0,(int)s.length()) {
        if (s[i] == 'A') {a++;}
        else if (s[i] == 'C') {c++;}
        else if (s[i] == 'T') {t++;}
        else if (s[i] == 'G') {g++;}
    }
    ifs.close();
    fstream ofs ("RCDNAN.txt", fstream::out);
    ofs << a << " " << c << " " << g << " " << t << '\n';
    ofs.close();
}
