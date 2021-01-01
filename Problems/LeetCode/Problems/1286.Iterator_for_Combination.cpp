class CombinationIterator {
public:
    int n,k;
    string str;
    bool isFirst;
    vector<bool> used;
    CombinationIterator(string str, int k) {
        isFirst = true;
        n = str.length();
        used.resize(n, false);
        this->str = str;
        this->k = k;
    }
    string next() {
        string ans = "";
        if(isFirst) {
            for( int i = 0 ; i < k ; i++ ) {
                used[i] = true;
                ans.push_back( str[i] );
            }
            isFirst = false;
        }
        else {
            int cnt1 = last1s();
            for( int i = n-cnt1-2 ; i >= 0 ; i-- )
                if( used[i] ) {
                    for( int j = i ; j < n ; j++ )
                        used[j] = false;
                    for( int j = i+1 ; j <= i+cnt1+1 ; j++ )
                        used[j] = true;
                    break;
                }
            for( int i = 0 ; i < n ; i++ )
                if( used[i] )
                    ans.push_back( str[i] );
        }
        return ans;
    }
    bool hasNext() {
        int cnt1 = last1s();
        return cnt1 != k;
    }
    int last1s() {
        int i = 0;
        while(i < n && used[n-1-i] == true)
            i++;
        return i;
    }
};