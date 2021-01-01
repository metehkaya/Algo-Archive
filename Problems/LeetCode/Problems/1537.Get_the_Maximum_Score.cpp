typedef long long LL;

class Solution {
public:
    const int mod = (int) 1e9 + 7;
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() , m = nums2.size();
        vector<LL> dp1(n+1);
        vector<LL> dp2(m+1);
        dp1[n] = dp2[m] = 0;
        int i = n-1 , j = m-1;
        while(i >= 0 && j >= 0) {
            if(nums1[i] > nums2[j]) {
                dp1[i] = dp1[i+1] + nums1[i];
                i--;
            }
            else if(nums1[i] < nums2[j]) {
                dp2[j] = dp2[j+1] + nums2[j];
                j--;
            }
            else {
                dp1[i] = dp2[j] = max( dp1[i+1] , dp2[j+1] ) + nums1[i];
                i--,j--;
            }
        }
        while(i >= 0) {
            dp1[i] = dp1[i+1] + nums1[i];
            i--;
        }
        while(j >= 0) {
            dp2[j] = dp2[j+1] + nums2[j];
            j--;
        }
        return max(dp1[0],dp2[0]) % mod;
    }
};