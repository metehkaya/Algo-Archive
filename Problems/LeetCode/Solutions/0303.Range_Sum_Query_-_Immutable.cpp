class NumArray {
public:
    vector<int> sum;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        sum.push_back(0);
        for( int i = 0 ; i < n ; i++ )
            sum.push_back(sum[i]+nums[i]);
    }

    int sumRange(int i, int j) {
        return sum[j+1] - sum[i];
    }
};