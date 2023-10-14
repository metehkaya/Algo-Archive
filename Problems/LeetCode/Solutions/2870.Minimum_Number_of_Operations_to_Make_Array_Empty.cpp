class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        map<int,int> mp;
        for(int x : nums)
            mp[x]++;
        for(auto it : mp) {
            int x = it.second;
            if(x == 1)
                return -1;
            if(x % 3 == 0)
                ans += x/3;
            else if(x % 3 == 2)
                ans += (x-2)/3 + 1;
            else
                ans += (x-4)/3 + 2;
        }
        return ans;
    }
};
