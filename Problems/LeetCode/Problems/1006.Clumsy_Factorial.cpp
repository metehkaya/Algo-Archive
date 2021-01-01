class Solution {
public:
    int clumsy(int n) {
        vector<int> nums;
        int curr = n;
        for( int i = 0 ; i < n-1 ; i++ ) {
            int num = n-i-1;
            if(i%4 == 0)
                curr *= num;
            else if(i%4 == 1)
                curr /= num;
            else {
                nums.push_back(curr);
                curr = num;
            }
        }
        nums.push_back(curr);
        int ans = nums[0];
        for( int i = 1 ; i < nums.size() ; i++ ) {
            if(i%2)
                ans += nums[i];
            else
                ans -= nums[i];
        }
        return ans;
    }
};