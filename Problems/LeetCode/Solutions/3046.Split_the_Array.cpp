class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        map<int,int> mp;
        for(int x : nums)
            if(++mp[x] > 2)
                return false;
        return true;
    }
};