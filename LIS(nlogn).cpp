#include <bits/stdc++.h>

using namespace std;

int lis (vector<int> &seq){
  vector<int> lis;
  lis.push_back(seq[0]);
  int k=0;
  for (int i=1; i<seq.size(); i++){
    //printf("%d, %d\n", lis[i-1], seq[i]);
    if (lis[k]<seq[i]){
      lis.push_back(seq[i]);
      k++;
    }
    else{
      lis[lower_bound(lis.begin(), lis.end(), seq[i])-lis.begin()] = seq[i];
      //printf("~TROQUEI NA %d\n", lower_bound(lis.begin(), lis.end(), seq[i])-lis.begin());
    }
  }
  /*cout << "LONGEST INCREASING SUBSEQUENCE:\n";
  for (int i=0; i<lis.size(); i++)
        cout << lis[i] << "\n";
    printf("\n");*/
  return lis.size(); 
}

int main() {
  vector<int> seq;
  int n;
  cin >> n;
  for (int i=0;i<n;i++){
    int a;
    cin >> a;
    seq.push_back(a);
  }
  printf("LENGHT: %d\n", lis(seq));
  return 0;
}
