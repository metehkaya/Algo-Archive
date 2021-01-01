class Solution {
public:
    bool kLengthApart(vector<int>& ar, int k) {
        int n = ar.size();
        int last = -k-1;
        for( int i = 0 ; i < n ; i++ )
            if( ar[i] == 1 ) {
                if(i-last <= k)
                    return false;
                last = i;
            }
        return true;
    }
};