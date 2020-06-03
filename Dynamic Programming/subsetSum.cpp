vector<int> arr;

bool subsetSum(int value){
    vector<bool> subset(value+1, 0); 

    subset[0] = 1; //subset of sum zero is always possible

    for(int i=0; i<arr.size(); i++){
        for(int j=value; j>=arr[i]; j--)
            subset[j] = max(subset[j], subset[j-arr[i]]);
    }

    return subset[value]; //return if exists a subset sum of value
}

void util(int n){
    arr.resize(n);
}