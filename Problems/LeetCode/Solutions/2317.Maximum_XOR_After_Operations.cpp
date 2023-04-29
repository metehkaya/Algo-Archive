class Solution {
public:
    int maximumXOR(vector<int>& ar) {
        int n = ar.size() , ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int k = 0 ; k < 30 ; k++ )
                if(ar[i] & (1<<k))
                    ans |= (1<<k);
        return ans;
    }
};
