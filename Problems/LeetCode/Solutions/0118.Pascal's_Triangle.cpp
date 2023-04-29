class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        vector<int> one(1,1);
        ans.push_back(one);
        for( int k = 1 ; k < n ; k++ ) {
            vector<int> v(k+1,0);
            for( int i = 0 ; i <= k ; i++ ) {
                if(i)
                    v[i] += ans[k-1][i-1];
                if(i < k)
                    v[i] += ans[k-1][i];
            }
            ans.push_back(v);
        }
        return ans;
    }
};