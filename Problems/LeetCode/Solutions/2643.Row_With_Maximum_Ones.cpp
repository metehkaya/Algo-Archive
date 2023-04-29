class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> ans(2,-1);
        for( int i = 0 ; i < n ; i++ ) {
            int cnt = 0;
            for(int x : mat[i])
                cnt += x;
            if(cnt > ans[1])
                ans = {i,cnt};
        }
        return ans;
    }
};
