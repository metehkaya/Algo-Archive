class Solution {
public:
    const int add = 50000;
    const int maxs = 2*add+1;
    vector<int> sortArray(vector<int>& nums) {
        vector<int> cnt(maxs,0);
        for(int x : nums)
            cnt[x+add]++;
        vector<int> ans;
        for( int i = 0 ; i < maxs ; i++ )
            while(cnt[i]--)
                ans.push_back(i-add);
        return ans;
    }
};
