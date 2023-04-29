class Solution {
public:
    int unequalTriplets(vector<int>& v) {
        int n = v.size() , ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = i+1 ; j < n ; j++ )
                for( int k = j+1 ; k < n ; k++ )
                    if(v[i] != v[j] && v[i] != v[k] && v[j] != v[k])
                        ans++;
        return ans;
    }
};
