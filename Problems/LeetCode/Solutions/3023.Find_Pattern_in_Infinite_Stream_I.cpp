class InfiniteStream {
public:
    InfiniteStream(vector<int> bits);
    int next();
};

class Solution {
public:
    bool check(vector<int>& v1, vector<int>& v2, int n) {
        for( int i = 0 ; i < n ; i++ )
            if(v1[i] != v2[i])
                return false;
        return true;
    }
    int findPattern(InfiniteStream* stream, vector<int>& p) {
        int n = p.size();
        vector<int> v;
        for( int i = 0 ; i < n ; i++ ) {
            int x = stream->next();
            v.push_back(x);
        }
        if(check(v,p,n))
            return 0;
        for( int i = 1 ; true ; i++ ) {
            v.erase(v.begin());
            v.push_back(stream->next());
            if(check(v,p,n))
                return i;
        }
        return -1;
    }
};
