class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        map<int,int> mp;
        for(int num : nums)
            mp[num]++;
        int n = moveFrom.size();
        for( int i = 0 ; i < n ; i++ )
            if(moveFrom[i] != moveTo[i]) {
                mp[moveTo[i]] += mp[moveFrom[i]];
                mp[moveFrom[i]] = 0;
            }
        vector<int> ans;
        for(auto it : mp)
            if(it.second)
                ans.push_back(it.first);
        return ans;
    }
};
