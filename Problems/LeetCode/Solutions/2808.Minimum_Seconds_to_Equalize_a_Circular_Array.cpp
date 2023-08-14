class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        int n = nums.size();
        map<int,vector<int>> mp;
        for( int i = 0 ; i < n ; i++ )
            mp[nums[i]].push_back(i);
        int ans = INT_MAX;
        for(auto& p : mp) {
            vector<int> v = p.second;
            int sz = v.size();
            v.push_back(v.front()+n);
            int mx = 0;
            for( int i = 0 ; i < sz ; i++ )
                mx = max(mx,v[i+1]-v[i]);
            ans = min(ans,mx/2);
        }
        return ans;
    }
};
