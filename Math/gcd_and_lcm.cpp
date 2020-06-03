#define LL long long int 

LL gcd(LL a, LL b){
    if(b==0)
        return a;
    return gcd(b, a%b);
}

LL lcm(LL a, LL b){
    return (a*b)/gcd(a, b);
}