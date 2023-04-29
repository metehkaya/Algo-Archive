class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> ans;
        int n = nums.size() , mx = 0;
        long long last = 0;
        for(int x : nums) {
            mx = max(mx,x);
            last += x+mx;
            ans.push_back(last);
        }
        return ans;
    }
};
