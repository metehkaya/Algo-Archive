class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);
        map<int,vector<int>> mp;
        for( int i = 0 ; i < n ; i++ )
            mp[nums[i]].push_back(i);
        for(auto it : mp) {
            auto& v = it.second;
            int len = v.size();
            long long cost = 0;
            for(int idx : v)
                cost += idx-v[0];
            ans[v[0]] = cost;
            for( int i = 1 ; i < len ; i++ ) {
                int diff = i - (len-i);
                cost += (long long) diff * (v[i]-v[i-1]);
                ans[v[i]] = cost;
            }
        }
        return ans;
    }
};
