class Solution {
public:
    vector<int> numberOfLines(vector<int>& w, string s) {
        int n = s.length();
        vector<int> ans(2);
        ans[0] = 1 , ans[1] = 0;
        for( int i = 0 ; i < n ; i++ ) {
            int c = s[i]-'a';
            int x = w[c];
            if(ans[1] + x <= 100)
                ans[1] += x;
            else
                ans[0]++ , ans[1] = x;
        }
        return ans;
    }
};