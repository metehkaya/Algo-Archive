class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>res;
        for( int i=0 , j=0 ; i<m || j<n ; ) {
            if(j==n)
                res.push_back(nums1[i++]);
            else if(i==m)
                res.push_back(nums2[j++]);
            else if(nums1[i] < nums2[j])
                res.push_back(nums1[i++]);
            else
                res.push_back(nums2[j++]);
        }
        nums1 = res;
    }
};