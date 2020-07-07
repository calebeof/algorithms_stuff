
#define mp make_pair

void radix_sort(vector<pair<pair<int, int>, int> > &a){
    int n = a.size();

    //SORT BY THE SECOND ELEMENT OF THE PAIR
    vector<int> counter(n); //counter of the element

    for(auto x : a)
        counter[x.first.second]++;
    
    vector<pair<pair<int, int>, int> > a_buckets(n); //sorting by buckets
    vector<int> pos_bucket(n); //position in the bucket

    pos_bucket[0] = 0;

    for(int i = 1; i<n; i++)
        pos_bucket[i] = pos_bucket[i-1] + counter[i-1];
    
    for(auto x : a){
        int i = x.first.second;
        a_buckets[pos_bucket[i]] = x;
        pos_bucket[i]++;
    }

    a = a_buckets;

    //SORT BY THE FIRST ELEMENT OF THE PAIR
    counter.clear();
    counter.resize(n, 0);

    for(auto x : a)
        counter[x.first.first]++;

    pos_bucket[0] = 0;

    for(int i = 1; i<n; i++)
        pos_bucket[i] = pos_bucket[i-1] + counter[i-1];
    
    for(auto x : a){
        int i = x.first.first;
        a_buckets[pos_bucket[i]] = x;
        pos_bucket[i]++;
    }

    a = a_buckets;
}

vector<int> suffix_array(string str){

    str+='$';
    int n = str.size();
    vector<int> p(n), c(n);

    // k = 0

    vector<pair<char, int> > a(n);

    for(int i=0; i<n; i++)
        a[i] = mp(str[i], i);

    sort(a.begin(), a.end());

    for(int i=0; i<n; i++) p[i] = a[i].second;
    c[p[0]] = 0;

    for(int i=1; i<n; i++) {//classification
        if(a[i].first == a[i-1].first)
            c[p[i]] = c[p[i-1]]; //strings equal = same class
        else c[p[i]] = 1+c[p[i-1]]; // strings not equal = diff class
    }

    //TRANSITION

    int k = 0;

    while((1<<k) < n){ //WHILE 2^k < n

        // k -> k+1

        vector<pair<pair<int, int>, int> > b(n); //(left, right) -> position
        
        for(int i=0; i<n; i++)
            b[i] = mp(mp(c[i], c[(i + (1<<k)) % n]), i);

        radix_sort(b);

        for(int i=0; i<n; i++) p[i] = b[i].second;
        c[p[0]] = 0;

        for(int i=1; i<n; i++) {//classification
            if(b[i].first == b[i-1].first)
                c[p[i]] = c[p[i-1]]; //strings equal = same class
            else c[p[i]] = 1+c[p[i-1]]; // strings not equal = diff class
        }
        
        k++;
    }

    for(int i=0; i<n; i++)
       cout << p[i] << " " << str.substr(p[i], n-p[i]) << endl; //suffix array number and suffix array value

    return p; //return suffix array
}
