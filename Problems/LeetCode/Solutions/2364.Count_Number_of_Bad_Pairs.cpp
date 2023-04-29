class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        for( int i = 0 ; i < nums.size() ; i++ )
            mp[i-nums[i]]++;
        map<int,int>::iterator it;
        long long ans = 0;
        for(it = mp.begin() ; it != mp.end() ; it++) {
            long long x = it->second;
            ans += x*(n-x);
        }
        return ans/2;
    }
};
