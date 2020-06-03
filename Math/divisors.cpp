vector<int> div;

void divisors(int n){

    for(int i=1; i<=sqrt(n); i++){
        if(n%i==0){
            if(n/i==i) // if divisors are equal
                div.push_back(i);
            else { //if divisors aren't equal
                div.push_back(i);
                div.push_back(n/i);
            }
        }
    }
    
}