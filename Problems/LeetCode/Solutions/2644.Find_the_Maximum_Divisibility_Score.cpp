class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        vector<int> ans(2,-1);
        for(int x : divisors) {
            int cnt = 0;
            for(int y : nums)
                cnt += !(y%x);
            if(cnt > ans[1] or (cnt == ans[1] and x < ans[0]))
                ans = {x,cnt};
        }
        return ans[0];
    }
};
