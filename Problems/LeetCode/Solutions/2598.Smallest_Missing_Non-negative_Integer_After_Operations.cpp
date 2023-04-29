class Solution {
public:
    static const int maxv = 100000;
    int cnt[maxv];
    int findSmallestInteger(vector<int>& nums, int value) {
        for(int x : nums) {
            x %= value;
            if(x < 0)
                x += value;
            cnt[x]++;
        }
        int ans = 0;
        while(cnt[ans%value]) {
            cnt[ans%value]--;
            ans++;
        }
        return ans;
    }
};
