#define mp make_pair

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
            b[i] = mp(mp(c[i], c[(i + (1<<k) % n)]), i);

        sort(b.begin(), b.end());

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