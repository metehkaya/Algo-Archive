class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int val = -1 , freq = -1;
        map<int,int> mp;
        for(int x : nums) {
            int cnt = ++mp[x];
            if(2*cnt > n) {
                val = x;
                freq = cnt;
            }
        }
        if(val == -1)
            return -1;
        int cnt = 0;
        for( int i = 0 ; i < n ; i++ )
            if(nums[i] == val) {
                cnt++;
                if(2*cnt > i+1 and 2*(freq-cnt) > n-i-1)
                    return i;
            }
        return -1;
    }
};