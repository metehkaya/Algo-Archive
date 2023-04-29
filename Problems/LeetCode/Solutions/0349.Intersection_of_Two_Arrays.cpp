class Solution {
public:
    set<int> s1,s2;
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        for( int i = 0 ; i < n ; i++ )
            s2.insert(nums2[i]);
        vector<int> ans;
        n = nums1.size();
        set<int>::iterator it;
        for( int i = 0 ; i < n ; i++ ) {
            int x = nums1[i];
            if(s1.find(x) == s1.end() && s2.find(x) != s2.end()) {
                s1.insert(x);
                ans.push_back(x);
            }
        }
        return ans;
    }
};