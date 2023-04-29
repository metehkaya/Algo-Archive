class Solution {
public:
    int countElements(vector<int>& nums) {
        map<int,int> cnt;
        for(int x : nums)
            cnt[x]++;
        int n = cnt.size() , id = 0 , ans = 0;
        for(auto it : cnt) {
            if(id > 0 && id < n-1)
                ans += it.second;
            id++;
        }
        return ans;
    }
};
