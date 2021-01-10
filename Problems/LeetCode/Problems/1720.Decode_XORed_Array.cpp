class Solution {
public:
    vector<int> decode(vector<int>& ar, int first) {
        vector<int> ans;
        ans.push_back(first);
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            ans.push_back(ans[i]^ar[i]);
        return ans;
    }
};