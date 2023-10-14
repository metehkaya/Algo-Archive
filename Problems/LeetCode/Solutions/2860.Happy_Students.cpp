class Solution {
public:
    int countWays(vector<int>& v) {
        int n = v.size() , ans = 0;
        sort(v.begin(),v.end());
        for( int i = 0 ; i <= n ; i++ ) {
            bool ok = true;
            if(i > 0 and v[i-1] >= i)
                ok = false;
            if(i < n and v[i] <= i)
                ok = false;
            ans += ok;
        }
        return ans;
    }
};
