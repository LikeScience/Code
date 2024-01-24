#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    set<string> s;
    cout << "Ola, sou o Shopy, o seu assistente virtual de compras. Pode indicar produtos para comprar (desde que nao tenham espacos, acentos, cedilhas ou caracteres nao ASCII no nome) e eu aviso se ja la se encontrava ou nao. Se escrever \"0\", eu indicar-lhe-ei os produtos da lista (nao, infelizmente nao o posso ajudar se houver um produto chamado \"0\"...)" << '\n';
    string inp;
    while (1) {
        cin >> inp;
        if (inp == "0") break;
        set<string>::iterator it = s.find(inp);
        if (it == s.end()) {
            s.insert(inp);
            cout << "Ok, o seu produto ainda nao estava na lista. Vamos adiciona-lo." << '\n';
        } else {
            cout << "Peco desculpa, mas o seu produto ja estava na lista." << '\n';
        }
    }
    cout << "A sua lista de compras e:" << '\n';
    for (set<string>::iterator it = s.begin(); it != s.end() ; it++) {
        cout << *it << '\n';
    }
}