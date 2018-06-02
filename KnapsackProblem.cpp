#include <bits/stdc++.h>

#define TAM 150
using namespace std;

int knapsack(int weights[], int time[], int n, int max_weight){
  int K[TAM][TAM];
  for (int i=0; i<=n; i++)
    for (int j=0; j<=max_weight; j++){
      if (i==0 || j==0)
        K[i][j] = 0;
      else if (time[i-1]<=j)
        K[i][j] = max(weights[i-1]+K[i-1][j-time[i-1]], K[i-1][j]);
      else
        K[i][j] = K[i-1][j];
      //printf("%d\n", K[i][j]);
    }
  /*for (int i=0; i<=n; i++){
    for (int j=0; j<=max_weight; j++)
      printf("%d ", K[i][j]);
    printf("\n");
  }*/
  return K[n][max_weight];
}

int main() {
  int n, max_weight;
  while (cin >> n && n!=0){
    cin >> max_weight;
    int weights[TAM], time[TAM];
    for (int i=0; i<n; i++)
      cin >> weights[i] >> time[i];
    printf("%d min.\n",knapsack(weights, time, n, max_weight));
  }
  return 0;
}
