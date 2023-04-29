class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> v[2];
        for( int i = 0 ; i < n ; i++ )
            v[i%2].push_back(nums[i]);
        sort(v[0].begin(),v[0].end());
        sort(v[1].begin(),v[1].end(),std::greater<>());
        for( int i = 0 ; i < v[0].size() ; i++ )
            ans[2*i] = v[0][i];
        for( int i = 0 ; i < v[1].size() ; i++ )
            ans[2*i+1] = v[1][i];
        return ans;
    }
};
