#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int caminho, saltos;
    cin >> caminho;
    cin >> saltos;
    string percurso;
    cin >> percurso;
    int lista[percurso.size()];
    for (int i = 0; i < percurso.size(); i++){
        lista[i] = percurso[i] - '0';
    }
    bool meta = false;
    int lugar = 0;
    int salto = 0;
    while (!meta){
        for (int i = saltos; i > 0; i--){
            if (i+lugar >= caminho) {
                lugar = caminho-1;
                salto++;
                break;
            }
            if (lista[i+lugar] == 1){
                lugar += i;
                salto += 1;
                break;
            }
            if (i == 1 && lista[i+lugar] == 0){
                salto = -1;
                break;
            }
        }
        if (lugar == caminho -1){
            break;
        }
        if (salto == -1){
            break;
        }
    }
    cout << salto << endl;
    return 0;
}