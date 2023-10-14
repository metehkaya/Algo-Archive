class Solution {
public:
    long long maximumTripletValue(vector<int>& v) {
        long long ans = 0;
        int n = v.size();
        for( int i = 0 ; i < n ; i++ )
            for( int j = i+1 ; j < n ; j++ )
                for( int k = j+1 ; k < n ; k++ )
                    ans = max(ans,(long long)v[k]*(v[i]-v[j]));
        return ans;
    }
};
