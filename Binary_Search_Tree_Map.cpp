#include <bits/stdc++.h>

using namespace std;

string prefixo;
string infixo;

map <char, pair<char,char> > mapa;

int aux;

void posfixa (char raiz){
    if(mapa[raiz].first!='-')
        posfixa(mapa[raiz].first);
    if(mapa[raiz].second!='-')
        posfixa(mapa[raiz].second);

        cout << raiz;
}


char func (int inicio, int fim) {
    if (inicio == fim)
        return '-';

    int c = inicio;

    while (c < fim && infixo[c] != prefixo[aux])
        c++;

    char a = prefixo [aux++];

    mapa[a].first = func (inicio, c);
    mapa[a].second = func (c+1, fim);

    return a;
}

int main () {
    int n;

    bool c2 = false;

    cin >> n;

    int cont=0;

    while (n--) {
        int n2;
        cin >> n2 >> prefixo >> infixo;

        func (0, n2);
        posfixa (prefixo[0]);

        cout << "\n";
        mapa.clear();
        aux = 0;
    }

    return 0;
}
