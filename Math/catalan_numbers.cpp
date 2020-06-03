#define ULL unsigned long long int 

const int TAM = 1000;
vector<int> catalan;

void build(int n){
    
    catalan.resize(n);

    catalan[0] = 1;
    catalan[1] = 1;

    for(int i=2; i<n; i++){
        catalan[i] = 0;
        for(int j=0; j<i; j++)
            catalan[i] += catalan[j] * catalan[i-j-1];
    }

}