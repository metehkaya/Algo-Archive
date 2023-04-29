class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        sort(nums.begin(),nums.end());
        map<int,int> mp;
        int mx = 0;
        for(int x : nums)
            mx = max(mx,++mp[x%space]);
        for(int x : nums)
            if(mx == mp[x%space])
                return x;
        return -1;
    }
};
