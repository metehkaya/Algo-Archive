class Solution {
public:
    int minimumSum(vector<int>& v) {
        int n = v.size() , ans = INT_MAX;
        for( int i = 0 ; i < n ; i++ )
            for( int j = i+1 ; j < n ; j++ )
                for( int k = j+1 ; k < n ; k++ )
                    if(v[i] < v[j] and v[k] < v[j])
                        ans = min(ans,v[i]+v[j]+v[k]);
        return ans == INT_MAX ? -1 : ans;
    }
};
