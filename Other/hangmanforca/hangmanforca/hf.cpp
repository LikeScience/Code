#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>
#include <random>

#define F(i,s,e) for(int i = s; i < e; i++)
using namespace std;


int main() {
    while(1 == -1 + 2) {
    bool l = 0;
    cout << "Welcome to the hangman game!" << '\n';
    vector<int> vis(26,-1);
    vector<vector<int> > ap(26, vector<int>(0));
    string g;
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 gen(seed);
    int es = 0;
    while (!es) {
    cout << "Please type:\n" << 
    "1 if you want to play with a word (with or without spaces) written here in the terminal;\n" <<
    "2 if you want to play with a word (with or without spaces) written in the first line of a file on this folder;\n" <<
    "3 if you want to play with a random word (from a list of 3000 common english words without spaces);\n" <<
    "4 if you want to play with a random word (from a list of 370105 english words without spaces);\n" <<
    "5 if you want to play with a random name of a country;\n"<<
    "6 if you want to play with a random Imagine Dragons song name.\n";
    int x; cin >> x;
    cin.clear(); cin.sync();
    if (x == 1) {
        cout << "Please write the word/expression you want in next line (please note this game is not case sensitive, you must only use ASCII characters (you can use e.g. spaces and hyphens if you wish) and only letters can be guessed)." << '\n';
        cin.clear(); cin.sync();
        getline(cin, g);
        es = 1;
    }
    else if (x == 2) {
        cout << "Please write the name of the file (with extension) where it is the word/expression you want written in the first line (please note the file must be in \"hangmanforca\" folder, that this game is not case sensitive, you must only use ASCII characters (you can use e.g. spaces and hyphens if you wish) and only letters can be guessed)." << '\n';
        string filename; cin >> filename;
        ifstream ifs(filename, ifstream::in);
        getline(ifs,g);
        cin.clear(); cin.sync();
        es = 1;
    }
    else if (x == 3) {
        ifstream ifs("cew.txt", ifstream::in);
        int idx = gen() % 3000;
        for(int i = 0; i < idx; i++) getline(ifs,g);
        getline(ifs,g);
        cin.clear(); cin.sync();
        es = 1;
    }
    else if (x == 4) {
        ifstream ifs("words_alpha.txt", ifstream::in);
        int idx = gen() % 370105;
        //cout << idx << '\n';
        for(int i = 0; i < idx; i++) getline(ifs,g);
        getline(ifs,g);
        cin.clear(); cin.sync();
        es = 1;
    }
    else if (x == 5) {
        ifstream ifs("countries.txt", ifstream::in);
        int idx = gen() % 196;
        for(int i = 0; i < idx; i++) getline(ifs,g);
        getline(ifs,g);
        cin.clear(); cin.sync();
        es = 1;
    }
    else if (x == 6) {
        ifstream ifs("IDSL.txt", ifstream::in);
        int idx = gen() % 132; 
        for(int i = 0; i < idx; i++) getline(ifs,g);
        
        getline(ifs,g);
        cin.clear(); cin.sync();
        es = 1;
    }
    else {
        cout << "This is not a valid number." << '\n';
    }
    }
    //cout << g << '0'<< '\n';
    string ot = g;
    int let = 0, z, cor = 0, wro = 0;
    for (int i = 0; i < (int)g.size(); i++) {
        if (g[i] == '\n') break;
        z = int(g[i]);
        if ((z < int('A') || z > int('z')) || (z > int('Z') && z < int('a'))) continue;
        if (z >= int('A') && z <= int('Z')) {z -= int('A');} else if (z >= int('a') && z <= int('z')) {z -= int('a');}
        ot[i] = '_';
        if (vis[z] == -1) {vis[z] = 0; let++;}
        ap[z].push_back(i);
    }
    cout << "Okay! Let's play!" << '\n';
    ifstream pict("pict.txt", ifstream::in);
    vector<string> pic(7);
    vector<char> gl, wl;
    for (int i = 0; i < 7; i++) {
        cin.clear(); cin.sync();
        getline(pict,pic[i]);
    }
    while(cor < let && !l) {
        for (int i = 0; i < 7; i++) {
            cout << pic[i] << '\n';
        }
        if (cor > 0) {
            cout << "Guessed letters:";
            F(i,0,(int)gl.size()) cout << " " << gl[i];
            cout << '\n';
        }
        if (wro > 0) {
            cout << "Wrong letters:";
            F(i,0,(int)wl.size()) cout << " " << wl[i];
            cout << '\n';
        }
        cout << '\n' << ot << "\n\n";
        cout << "Type the next letter you want to guess." << '\n';
        char b;
        while (!l) {
        cin.clear(); cin.sync();
        cin >> b; z = int(b);
        //cout << "EEEEE" << b << "dadsdadsdasdadasdddad"<<  '\n';
        if (z >= int('A') && z <= int('Z')) {z -= int('A');}
        else if (z >= int('a') && z <= int('z')) {z -= int('a');}
        else {
            cout << "Type a letter, please." << '\n';
            continue;
        }
        if (vis[z] == 1 || vis[z] == -2) {
            cout << "Type a letter not entered before, please." << '\n';
            continue;
        }
        else if (!vis[z] || vis[z] == -1) {
            break;
        }
        }
        if (!vis[z]) {
            vis[z] = 1; cor++; gl.push_back(char(int('a') + z));
            for (int i = 0; i < (int)ap[z].size(); i++) {
                ot[ap[z][i]] = g[ap[z][i]];
            }
        }
        else if (vis[z] == -1) {
            vis[z] = -2; wro++; wl.push_back(char(int('a') + z));
            if (wro >=6 ) l = 1;
            for (int i = 0; i < 7; i++) {
                cin.clear(); cin.sync();
                getline(pict, pic[i]);
            }
        }
    }
    if (l) {
        for (int i = 0; i < 7; i++) {
            cout << pic[i] << '\n';
        }
    }
    cout << '\n' << g << '\n';
    if (l) {
        cout << "Oh, unfortunately it seems you loss the game..." << '\n';
    } else {
        cout << "Congratulations! You won the game! :)" << '\n';
    }
    int ans;
        cout << "Do you want to play again? (Press 0 if you don't want and any other integer if you want to.)" << '\n';
        cin.clear(); cin.sync();
        cin >> ans;
    if (!ans) break;
    }
}