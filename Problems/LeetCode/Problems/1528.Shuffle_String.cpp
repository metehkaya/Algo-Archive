class Solution {
public:
    string restoreString(string s, vector<int>& idx) {
        int n = idx.size();
        string ans(n,' ');
        for( int i = 0 ; i < n ; i++ )
            ans[idx[i]] = s[i];
        return ans;
    }
};