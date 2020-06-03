vector<int> arr, buckets;
int sizeBucket;

void updateVal(int pos, int value){
    int nB = 0;

    //update a single position and the value of the bucket

    for(int i=0; i<arr.size(); i+=sizeBucket){
        int begin = i;
        int end = begin + sizeBucket - 1;

        if(pos<=end){
            buckets[nB]-=arr[pos];
            arr[pos] = value;
            buckets[nB]+=value;
            break;
        }

        nB++;
    }
}

int getSum(int a, int b){
    int nB = 0, nB1 = -1, nB2 = -1;

    //identify bucket number one and bucket number two

    for(int i=0; i<arr.size() and (nB1==-1 or nB2==-2); i+=sizeBucket){
        int begin = i;
        int end = begin + sizeBucket - 1;

        if(a<=end and nB1 == -1)
            nB1 = nB;
        if(b<=end and nB2 == -1)
            nB2 = nB;

        nB++;
    }

    int s = 0;

    //get the sum between a and b

    for(int i=nB1; i<=nB2; i++){
        if(i==nB1){
            int begin = a;
            int end = (nB1*sizeBucket) + sizeBucket - 1;
            for(int j=a; j<arr.size() and j<=end and j<= end; j++)
                s+=arr[j];
        }else if(i==nB2){
            int begin = (nB2*sizeBucket);
            int end = b;
            for(int j=begin; j<arr.size() and j<=end; j++)
                s+=arr[j];
        }else s+=buckets[i];
    }

    return s;
}

void build(){
    int nB = 0;

    //build the sum of the buckets

    for(int i=0; i<arr.size(); i+=sizeBucket){
        int begin = i;
        int end = begin + sizeBucket - 1;

        int s = 0;
        for(int j=begin; j<=end; j++)
            s+=arr[j];
        
        buckets[nB++] = s;
    }    

}

void util(int n){
    //get the size of the bucket
    sizeBucket = sqrt(n)+1;
    buckets.resize(sizeBucket);
    arr.resize(n);
}