class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> mark(n+1,true);
        for( int i = 2 ; i*i <= n ; i++ )
            if(mark[i])
                for( int j = i*i ; j <= n ; j += i )
                    mark[j] = false;
        vector<vector<int>> ans;
        for( int i = 2 ; 2*i <= n ; i++ )
            if(mark[i] and mark[n-i])
                ans.push_back({i,n-i});
        return ans;
    }
};
