#define TEMPLATE_VERSION "v0.2 06/03/2019"
#include <bits/stdc++.h>

#define MOD (1000000007LL)
#define INF (INT_MAX)
#define LINF (LL_MAX)
#define TAM (1000000)
#define LL long long int 
#define ULL unsigned long long int
#define LD long double
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define si set<int>
#define qi queue<int>
#define sti stack<int>
#define vLL vector<LL>
#define pqi priority_queue<int>
#define pii pair<int, int> 
#define vii vector<pii>
#define vvii vector<vii>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define EPS 1e-9
#define loop( n ) for(int i=0; i<n; i++)
#define LOOP(k,n) for(int i=k; i<n; i++)
#define POOL(k,n) for(int i=k; i>=n; i--)
#define FIND(v, value) find(v.begin(), v.end(), value)
#define SORT( v ) sort(v.begin(), v.end())
#define SORTC(v, comp) sort(v.begin(), v.end(), comp)
#define WW( x ) cout<<#x<<" = "<<(x)<<"\n";
#define endl '\n'

using namespace std;

void build(vi &buckets, vi &vetor, int sizeBucket){
	int nB = 0;
	for(int i=0; i<vetor.size(); i+=sizeBucket){
		int inicio = i;
		int fim = inicio + sizeBucket - 1;
		int s = 0;
		for(int j=inicio; j<=fim; j++)
			s+=vetor[j];
		buckets[nB++] = s;
	}
}
void updateVal(vi &buckets, vi &vetor, int sizeBucket, int pos, int valor){
	int nB = 0;
	for(int i=0; i<vetor.size(); i+=sizeBucket){
		int inicio = i;
		int fim = inicio + sizeBucket - 1;
		if(pos<=fim){
			buckets[nB]-=vetor[pos];
			vetor[pos] = valor;
			buckets[nB]+=valor;
			break;
		}
		nB++;
	}
}


int getSum(vi &buckets, vi &vetor, int sizeBucket, int posA, int posB){
	int nB = 0, nB1 = -1, nB2 = -1;
	for(int i=0; i<vetor.size() and (nB1==-1 or nB2==-1); i+=sizeBucket){
		int inicio = i;
		int fim = inicio + sizeBucket - 1;
		if(posA<=fim and nB1==-1)
			nB1 = nB;
		if(posB<=fim and nB2==-1)
			nB2 = nB;
		nB++;
	}
	int s = 0;
	for(int i=nB1; i<=nB2; i++){
		if(i==nB1){
			int inicio = posA;
			int fim = (nB1*sizeBucket) + sizeBucket - 1;
			for(int j=posA; j<vetor.size() and j<=posB and j<=fim; j++)
				s+=vetor[j];
		}else if(i==nB2){
			int inicio = (nB2*sizeBucket);
			int fim = posB;
			for(int j=inicio; j<vetor.size() and j<=fim; j++)
				s+=vetor[j];
		}else
			s+=buckets[i];
	}
	return s;
}
int main () {
  ios_base::sync_with_stdio(false);
  //freopen("input.txt", "r+", stdin);
  //freopen("output.txt", "w+", stdout);
  int n, queries;
  cin >> n >> queries;
  int sizeBucket = sqrt(n)+1;
  vi vetor;
  vi buckets(sizeBucket);
  loop(n){
  	int a;
  	cin >> a;
  	vetor.pb(a);
  }

  //cout << setprecision(2) << fixed;
  return 0;
}
