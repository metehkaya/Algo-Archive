class Solution {
public:
    vector<int> runningSum(vector<int>& ar) {
        int n = ar.size();
        vector<int> ans;
        ans.push_back(ar[0]);
        for( int i = 1 ; i < n ; i++ )
            ans.push_back(ans.back() + ar[i]);
        return ans;
    }
};