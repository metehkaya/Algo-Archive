class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> bmask(2001,0);
        for(int x : nums1)
            bmask[x+1000] |= 1;
        for(int x : nums2)
            bmask[x+1000] |= 2;
        vector<int> v1,v2;
        vector<vector<int>> ans;
        for( int i = 0 ; i < 2001 ; i++ ) {
            int x = bmask[i];
            if(x == 1)
                v1.push_back(i-1000);
            else if(x == 2)
                v2.push_back(i-1000);
        }
        ans.push_back(v1);
        ans.push_back(v2);
        return ans;
    }
};
