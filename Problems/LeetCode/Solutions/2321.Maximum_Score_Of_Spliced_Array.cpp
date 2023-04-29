class Solution {
public:
    int f(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int maxInc = 0 , sum = 0 , mx = 0 , curr = 0;
        for( int i = 0 ; i < n ; i++ ) {
            sum += a[i];
            curr += a[i]-b[i];
            maxInc = max(maxInc,mx-curr);
            mx = max(mx,curr);
        }
        return sum+maxInc;
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        return max(f(nums1,nums2),f(nums2,nums1));
    }
};
