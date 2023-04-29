class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        set<char> wovels({'a', 'e', 'i', 'o', 'u'});
        int n = words.size();
        vector<int> dp;
        int val = 0;
        for( int i = 0 ; i < n ; i++ ) {
            int len = words[i].length();
            if(wovels.count(words[i][0]) and wovels.count(words[i][len-1]))
                val++;
            dp.push_back(val);
        }
        vector<int> ans;
        for(auto q : queries) {
            int l = q[0] , r = q[1];
            int res = dp[r] - ((l == 0) ? 0 : dp[l-1]);
            ans.push_back(res);
        }
        return ans;
    }
};
