#include <bits/stdc++.h>
#include <locale.h>

#define INF 100000

using namespace std;

int mark [INF]= {};

int BFS(int orig, int destino){
  mark[orig] = 1;
  queue<int> fila;
  fila.push(orig);
  while (!fila.empty()){
    int aux;
    aux = fila.front();
    fila.pop();
    
    if (mark[aux+1]==0){
      fila.push(aux+1);
      mark[aux+1] = mark[aux]+1;
      if (aux+1 == destino)
        return mark[aux+1];
    }
    if (mark[aux*2]==0){
      fila.push(aux*2);
      mark[aux*2] = mark[aux]+1;
      if(aux*2==destino)
        return mark[aux*2];
    }
  }
  return 0;
}

int main() {
  int orig, destino;
  setlocale(LC_ALL, "portuguese");
  
  scanf("%d %d", &orig, &destino);
  printf("Quantidade de operações necessárias para se obter a conversão do número: %d\n", BFS(orig, destino)-1); 
  //subtraimos um pois a contagem inicial já começa contando uma operação, o que não é necessário na hora de imprimir, mas é para o funcionamento do algoritmo, já que o nosso vetor de marcação utiliza o 0 como algo não visitado ainda
  //se houver uma operação de subtrair, a BFS poderia voltar para o ponto de origem, e isso ia ferrar o algoritmo
  return 0;
}
