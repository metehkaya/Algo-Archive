class Solution {
public:
    int maximumStrongPairXor(vector<int>& v) {
        int n = v.size() , ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = i+1 ; j < n ; j++ )
                if(abs(v[i]-v[j]) <= min(v[i],v[j]))
                    ans = max(ans,v[i]^v[j]);
        return ans;
    }
};
