class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(n+1,0);
        for(int x : nums)
            cnt[x]++;
        vector<vector<int>> ans;
        while(true) {
            vector<int> v;
            for( int i = 1 ; i <= n ; i++ )
                if(cnt[i]) {
                    v.push_back(i);
                    cnt[i]--;
                }
            if(!v.empty())
                ans.push_back(v);
            else
                break;
        }
        return ans;
    }
};
