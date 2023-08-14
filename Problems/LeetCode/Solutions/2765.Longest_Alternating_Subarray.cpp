class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size() , ans = -1;
        for( int i = 0 ; i < n ; i++ ) {
            int j = i;
            while(j < n and nums[j]-nums[i] == (j-i) % 2)
                j++;
            if(j-i > 1)
                ans = max(ans,j-i);
        }
        return ans;
    }
};
