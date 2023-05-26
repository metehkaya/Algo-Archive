class Solution {
public:
    bool check(vector<int>& nums, int x, int y, int k) {
        int rem = k;
        for(int num : nums)
            if(num/y >= k) {
                num -= k*y;
                if(num > 0) {
                    int times = num/(x-y) + ((num%(x-y)) > 0);
                    rem -= times;
                    if(rem < 0)
                        return false;
                }
            }
        return true;
    }
    int minOperations(vector<int>& nums, int x, int y) {
        int l = 1 , r = *max_element(nums.begin(),nums.end()) , ans = INT_MAX;
        while(l <= r) {
            int mid = (l+r)>>1;
            if(check(nums,x,y,mid))
                ans = mid , r = mid-1;
            else
                l = mid+1;
        }
        return ans;
    }
};
