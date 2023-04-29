class Solution {
public:
    int widestPairOfIndices(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() , ans = 0;
        vector<int> idx(2*n+1,-1);
        idx[n] = 0;
        for( int i = 0 , val = n ; i < n ; i++ ) {
            val += nums1[i]-nums2[i];
            if(idx[val] != -1)
                ans = max(ans,i+1-idx[val]);
            else
                idx[val] = i+1;
        }
        return ans;
    }
};
