class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int len = nums[0].length();
        for( int i = 0 ; i < queries.size() ; i++ ) {
            int k = queries[i][0];
            int trim = queries[i][1];
            vector<pair<string,int>> v;
            for( int i = 0 ; i < nums.size() ; i++ )
                v.push_back(make_pair(nums[i].substr(len-trim,trim),i));
            sort(v.begin(),v.end());
            ans.push_back(v[k-1].second);
        }
        return ans;
    }
};
