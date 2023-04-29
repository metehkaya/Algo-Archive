class Solution {
public:
    const int mod = (int)1e9+7;
    int countWays(vector<vector<int>>& v) {
        int n = v.size() , ans = 1;
        sort(v.begin(),v.end());
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            int mx = v[j++][1];
            while(j < n and v[j][0] <= mx)
                mx = max(mx,v[j++][1]);
            ans = (2*ans) % mod;
        }
        return ans;
    }
};
