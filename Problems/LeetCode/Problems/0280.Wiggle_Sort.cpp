class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> ar = nums;
        sort(ar.begin(), ar.end());
        int k = n/2;
        for( int i = 0 ; i < k ; i++ )
            nums[2*i+1] = ar[n-k+i];
        for( int i = 0 ; i < n ; i += 2 )
            nums[i] = ar[i/2];
    }
};