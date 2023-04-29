class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> v;
        for( int i = 0 ; i < n ; i++ )
            v.push_back({nums[i],i});
        sort(v.begin(),v.end());
        vector<bool> mark(n,false);
        long long ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            int idx = v[i][1];
            if(!mark[idx]) {
                ans += v[i][0];
                mark[idx] = true;
                if(idx-1 >= 0)
                    mark[idx-1] = true;
                if(idx+1 < n)
                    mark[idx+1] = true;
            }
        }
        return ans;
    }
};
