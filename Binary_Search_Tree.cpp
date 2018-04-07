#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int valor;
    int posesq=-1, posdir=-1;
} No;

No no;

vector <No> arvore;

bool c;

void insercao (int raiz, int pos) {
    if (arvore[raiz].valor > no.valor){
            if (arvore[raiz].posesq==-1)
                arvore[raiz].posesq=pos;
            else
                insercao (arvore[raiz].posesq, pos);
        }
        else {
            if (arvore[raiz].posdir==-1)
                arvore[raiz].posdir=pos;
            else
                insercao(arvore[raiz].posdir, pos);
        }

}

void infixa (int raiz){
  if(arvore[raiz].posesq!=-1)
    infixa(arvore[raiz].posesq);
   if (c)
        cout << " " <<arvore[raiz].valor;
   else{
        cout << arvore[raiz].valor;
        c=true;
   }

    if(arvore[raiz].posdir!=-1){
        infixa(arvore[raiz].posdir);
    }
}

void posfixa (int raiz){
    if(arvore[raiz].posesq!=-1){
        posfixa(arvore[raiz].posesq);
    }
  if(arvore[raiz].posdir!=-1)
    posfixa(arvore[raiz].posdir);
    if (c)
        cout << " " <<arvore[raiz].valor;
   else{
        cout << arvore[raiz].valor;
        c=true;
   }
}

void prefixa (int raiz) {
    if (c)
        cout << " " << arvore[raiz].valor;
    else {
        cout << arvore[raiz].valor;
        c = true;
    }
    if(arvore[raiz].posesq!=-1){
        prefixa(arvore[raiz].posesq);
    }
    if(arvore[raiz].posdir!=-1){
        prefixa(arvore[raiz].posdir);
    }
}

bool existe (int valor, int raiz) {
    //cout<<arvore[raiz].valor<<" "<<valor<<endl;
    if (arvore[raiz].valor==valor)
        return true;
    if (arvore[raiz].valor > valor){
        if (arvore[raiz].posesq!=-1)
            return existe(valor, arvore[raiz].posesq);
        return false;
    }
    else {
        if (arvore[raiz].posdir!=-1)
            return existe(valor, arvore[raiz].posdir);
        return false;
    }
    return false;
}

int main () {
    string op;
    while (cin >> op) {
        if (op=="I"){
            cin >> no.valor;
            getchar();
            arvore.push_back (no);
            if (arvore.size()!=1)
                insercao (0, arvore.size()-1);
        }
        else if (op=="P") {
            cin >> no.valor;
            if (!existe (no.valor, 0))
                cout << no.valor << " nao existe\n";
            else
                cout << no.valor << " existe\n";
        }
        else if (op=="INFIXA") {
                c = false;
                infixa (0);
                cout << "\n";
        }
        else if (op=="POSFIXA") {
                c = false;
                posfixa (0);
                cout << "\n";
        }
        else if (op == "PREFIXA"){
                c = false;
                prefixa (0);
                cout << "\n";
        }
    }

    return 0;
}
