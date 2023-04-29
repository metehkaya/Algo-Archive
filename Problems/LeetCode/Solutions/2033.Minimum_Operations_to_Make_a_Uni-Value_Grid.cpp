class Solution {
public:
    int minOperations(vector<vector<int>>& ar, int k) {
        vector<int> v;
        int n = ar.size();
        int m = ar[0].size();
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < m ; j++ )
                v.push_back(ar[i][j]);
        sort(v.begin(),v.end());
        n = v.size();
        for( int i = 1 ; i < n ; i++ )
            if(v[i] % k != v[0] % k)
                return -1;
        int mid = n/2 , ans = 0;
        for( int i = 0 ; i < n ; i++ )
            ans += abs(v[i]-v[mid]) / k;
        return ans;
    }
};