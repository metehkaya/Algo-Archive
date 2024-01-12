class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        map<int,int> mp;
        for(int x : nums1)
            mp[x] |= 1;
        for(int x : nums2)
            mp[x] |= 2;
        vector<int> cnt(3,0);
        for(auto it : mp)
            cnt[it.second-1]++;
        int ans = 0 , rem = 0;
        ans += min(n/2,cnt[0]);
        rem += n/2 - min(n/2,cnt[0]);
        ans += min(n/2,cnt[1]);
        rem += n/2 - min(n/2,cnt[1]);
        ans += min(rem,cnt[2]);
        return ans;
    }
};
