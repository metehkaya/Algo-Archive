class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<vector<int>> ans;
        int n = arr.size();
        if(n == 0)
            return ans;
        sort(arr.begin(), arr.end());
        vector<int> curr;
        for( int i = 0 ; i < n ; i++ ) {
            if(curr.size() == 0)
                curr = arr[i];
            else if( arr[i][0] > curr[1] ) {
                ans.push_back(curr);
                curr = arr[i];
            }
            else
                curr[1] = max(curr[1], arr[i][1]);
        }
        ans.push_back(curr);
        return ans;
    }
};