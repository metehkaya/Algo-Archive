class Solution {
public:
    bool check(vector<int>& ar) {
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            ar.push_back(ar[i]);
        for( int i = 0 ; i < n ; i++ ) {
            bool ok = true;
            for( int j = i+1 ; j < i+n ; j++ )
                if(ar[j] < ar[j-1])
                    ok = false;
            if(ok)
                return true;
        }
        return false;
    }
};