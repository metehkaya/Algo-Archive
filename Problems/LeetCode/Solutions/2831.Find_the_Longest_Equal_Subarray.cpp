class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,vector<int>> mp;
        for( int i = 0 ; i < n ; i++ )
            mp[nums[i]].push_back(i);
        int ans = 0;
        for(auto& it : mp) {
            vector<int>& v = it.second;
            int sz = v.size();
            for( int i = 0 , j = 1 ; i < sz ; i++ ) {
                if(j <= i)
                    j = i+1;
                while(j < sz and (v[j]-v[i]+1)-(j-i+1) <= k)
                    j++;
                ans = max(ans,j-i);
            }
        }
        return ans;
    }
};