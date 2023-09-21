class Solution {
public:
    int maxSubarrayLength(vector<int>& nums) {
        int n = nums.size() , ans = 0 , r = -1;
        map<int,vector<int>> mp;
        for( int i = 0 ; i < n ; i++ )
            mp[nums[i]].push_back(i);
        for(auto it : mp) {
            vector<int>& v = it.second;
            for(int idx : v)
                ans = max(ans,r-idx+1);
            for(int idx : v)
                r = max(r,idx);
        }
        return ans;
    }
};
