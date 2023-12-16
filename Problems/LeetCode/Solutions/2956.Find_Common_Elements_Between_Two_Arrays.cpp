class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(2,0);
        set<int> s1(nums1.begin(),nums1.end());
        set<int> s2(nums2.begin(),nums2.end());
        for(int x : nums1)
            ans[0] += s2.count(x);
        for(int x : nums2)
            ans[1] += s1.count(x);
        return ans;
    }
};
