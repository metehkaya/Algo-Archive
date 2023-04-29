class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        map<int,int> cnt;
        for(int x : nums)
            cnt[x]++;
        vector<int> ans;
        for(int x : nums)
            if(cnt[x] == 1 && cnt[x-1] == 0 && cnt[x+1] == 0)
                ans.push_back(x);
        return ans;
    }
};
