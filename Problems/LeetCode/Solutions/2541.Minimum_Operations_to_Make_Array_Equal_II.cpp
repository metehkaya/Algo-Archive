class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        long long diff1 = 0 , diff2 = 0;
        for( int i = 0 ; i < n ; i++ ) {
            if(k == 0 and nums1[i] != nums2[i])
                return -1;
            int diff = abs(nums1[i]-nums2[i]);
            if(k > 0 and diff % k)
                return -1;
            if(nums1[i] > nums2[i])
                diff1 += diff;
            else if(nums1[i] < nums2[i])
                diff2 += diff;
        }
        if(diff1 != diff2)
            return -1;
        return k == 0 ? 0 : diff1 / k;
    }
};
