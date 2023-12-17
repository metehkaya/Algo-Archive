class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& v) {
        int n = v.size();
        vector<int> mark(n*n+1,0);
        for(auto& a : v)
            for(int b : a)
                mark[b]++;
        vector<int> ans(2);
        for( int i = 1 ; i <= n*n ; i++ )
            if(mark[i] == 2)
                ans[0] = i;
            else if(mark[i] == 0)
                ans[1] = i;
        return ans;
    }
};