class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans , res(1001,-1);
        for( int i = 0 ; i <= 1000 ; i++ ) {
            int val = (i | (i+1));
            if(val < 1001 && res[val] == -1)
                res[val] = i;
        }
        for(int x : nums)
            ans.push_back(res[x]);
        return ans;
    }
};