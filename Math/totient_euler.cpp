vector<int> primes;
vector<bool> mark;

void sieve(int n){
    mark.resize(n, 1);
    primes.resize(n);

    mark[0] = 0, mark[1] = 0;
    
    for(int i=2; i<n; i++)
        if(mark[i]){
            for(int j=i+i; j<n; j+=i)
                mark[j] = 0;
            primes.push_back(i);
        }
}

int phi(int n){
    int ans = n;

    for(int p : primes){
        if(n%p==0){
            ans-=ans/p;
            while(n%p==0)
                n/=p;
        }

        if(p>n)
            break;
    }

    if(n>1)
        ans-=ans/n;
    
    return ans;
}