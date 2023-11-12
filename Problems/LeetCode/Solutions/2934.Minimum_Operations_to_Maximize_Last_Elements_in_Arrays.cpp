class Solution {
public:
    int f(vector<int>& nums1, vector<int>& nums2, int cnt) {
        int n = nums1.size();
        for( int i = 0 ; i < n-1 ; i++ ) {
            if(nums1[i] <= nums1[n-1] and nums2[i] <= nums2[n-1])
                continue;
            else if(nums1[i] <= nums2[n-1] and nums2[i] <= nums1[n-1])
                cnt++;
            else
                return INT_MAX;
        }
        return cnt;
    }
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int ans = f(nums1,nums2,0);
        swap(nums1[n-1],nums2[n-1]);
        ans = min(ans,f(nums1,nums2,1));
        return ans == INT_MAX ? -1 : ans;
    }
};
