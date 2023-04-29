class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long ans = 0;
        int val = 0;
        map<int,int> mp;
        mp[val] = 1;
        for(int x : nums) {
            val ^= x;
            ans += mp[val]++;
        }
        return ans;
    }
};
