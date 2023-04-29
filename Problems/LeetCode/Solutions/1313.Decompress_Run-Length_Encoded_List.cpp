class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;
        int n = (int) nums.size();
        for( int i = 0 ; i < n/2 ; i++ ) {
            int a = nums[2*i];
            int b = nums[2*i+1];
            for( int j = 0 ; j < a ; j++ )
                ans.push_back(b);
        }
        return ans;
    }
};