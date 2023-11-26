class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int diff) {
        int n = nums.size();
        vector<int> ans(n);
        vector<vector<int>> v;
        for( int i = 0 ; i < n ; i++ )
            v.push_back({nums[i],i});
        sort(v.begin(),v.end());
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            vector<int> values,indices;
            values.push_back(v[j][0]);
            indices.push_back(v[j][1]);
            j++;
            while(j < n and v[j][0]-v[j-1][0] <= diff) {
                values.push_back(v[j][0]);
                indices.push_back(v[j][1]);
                j++;
            }
            sort(values.begin(),values.end());
            sort(indices.begin(),indices.end());
            int len = j-i;
            for( int k = 0 ; k < len ; k++ )
                ans[indices[k]] = values[k];
        }
        return ans;
    }
};
