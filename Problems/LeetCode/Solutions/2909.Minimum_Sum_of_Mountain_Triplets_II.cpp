class Solution {
public:
    int minimumSum(vector<int>& v) {
        int n = v.size() , ans = INT_MAX;
        vector<int> l(n) , r(n);
        l[0] = v[0];
        for( int i = 1 ; i < n ; i++ )
            l[i] = min(l[i-1],v[i]);
        r[n-1] = v[n-1];
        for( int i = n-2 ; i >= 0 ; i-- )
            r[i] = min(r[i+1],v[i]);
        for( int i = 1 ; i < n-1 ; i++ )
            if(l[i] < v[i] and r[i] < v[i])
                ans = min(ans,l[i]+r[i]+v[i]);
        return ans == INT_MAX ? -1 : ans;
    }
};
