class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans(1,0);
        for( int i = 0 ; i < n ; i++ ) {
            int sz = (1<<i);
            for( int j = sz-1 ; j >= 0 ; j-- )
                ans.push_back(ans[j]+sz);
        }
        return ans;
    }
};