#include <bits/stdc++.h>

using namespace std;

struct point {
  int x, y;
  point (){}
  point (int px, int py) > x (px), y (py){}
  bool operator < (point p) const {
    return (x < p.x or (x==p.x and y<p.y));
  }
};
double distance (point a, point b){
  return sqrt(pow(a.x - b.x, 2) + pow (a.y - b.y, 2));
}
struct vet{
  int x, y;
  vet () {}
  vet (point a, point b){
    x = b.x - a.x;
    y = b.y - a.y;
  }
};
int dot (vet a, vet b){
  return (a.x*b.x + a.y*b.y);
}

int cross (vet a, vet b){
  return (a.x*b.y - a.y*b.x);
}
double linePointDist(point a, point b, point c){
  double 
}
double segmentPointDist (point a, point b, point c){
  if (dot(vet(a,b), vet(a,c))>0)
    return distance(b,c);
  if (dot(vet(b,a), vet(b,c))>0)
    return distance(a,c);
  return linePointDist(a, b, c);
}
bool notRightTurn (point a, point b, point c){
  int cp = cross(vet(a,b), vet(a,c));
  return not(cp<0);
}
vector<point> convexHull (vector<point>&P){
  sort(P.begin(), P.end());
  vector<point> CH, L;
  CH.push_back(P[0]);
  CH.push_back(P[1]);
  for (int i=2; i<P.size(); i++){
    CH.push_back(P[i]);
    auto it=CH.end();
    while (CH.size() > 2 and notRightTurn(*(--it),*(--it),*(--it))){
      CH.erase(++it);
      it = CH.end();
    }
  }
  L.push_back(P[P.size()-1]);
  L.push_back(P[P.size()-2]);
  for (int i=P.size()-3; i>=0; i--){
    L.push_back(P[i]);
    auto it = L.end();
    while (L.size() > 2 and notRightTurn (*(--it),*(--it),*(--it))){
      L.erase(++it);
      it = L.end();
    }
    CH.insert(CH.end(), L.begin()+1, L.end());
    return CH;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(2);
  int n;
  while (cin >> n and n){
    vector<point> v(n);
    for (point &p : v)
      cin >> p.x >> p.y;
    vector<point> CH = convexHull(v);
    double fita = 0;
    for (int i=1; i<CH.size(); i++)
      fita+=distance(CH[i-1], CH[i]);
    
  }
  return 0;
}
