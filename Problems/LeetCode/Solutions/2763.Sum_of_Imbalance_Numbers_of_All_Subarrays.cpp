class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int n = nums.size() , ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            int add = 0;
            int min_val = nums[i];
            int max_val = nums[i];
            vector<bool> mark(n+1,false);
            mark[nums[i]] = true;
            for( int j = i+1 ; j < n ; j++ ) {
                int val = nums[j];
                if(!mark[val]) {
                    if(val > max_val) {
                        if(val > max_val + 1)
                            add++;
                        max_val = val;
                    }
                    else if(val < min_val) {
                        if(val < min_val - 1)
                            add++;
                        min_val = val;
                    }
                    else
                        add += 1 - mark[val+1] - mark[val-1];
                    mark[val] = true;
                }
                ans += add;
            }
        }
        return ans;
    }
};
