class Solution {
public:
    vector<int> getConcatenation(vector<int>& ar) {
        vector<int> ans = ar;
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            ans.push_back(ar[i]);
        return ans;
    }
};