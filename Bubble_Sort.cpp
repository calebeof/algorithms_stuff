#include <bits/stdc++.h>

using namespace std;

void bubbleSort (vector <int> Vector){
  for (int i=0; i<Vector.size()-1; i++){
    bool swapped = false;
    for (int j=0; j<Vector.size()-1; j++){
      if (Vector[j]>Vector[j+1]){
        swap (Vector[j], Vector[j+1]);
        swapped = true;
      }
    }
    if (swapped==false)
      break;
  }

  for (int i=0; i<Vector.size(); i++)
    cout << Vector[i] << "\n";
}

int main() {
  int n, num;
  vector <int> arr;
  cout << "Write the number of numbers that you want to put in order: \n";
  cin >> n;
  for (int i=0; i<n; i++){
    cin >> num;
    arr.push_back(num);
  }
  bubbleSort(arr);
  return 0;
}
