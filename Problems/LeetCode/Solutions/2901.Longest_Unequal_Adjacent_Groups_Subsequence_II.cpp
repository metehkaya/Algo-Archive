class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<int> dp(n,1) , before(n,-1);
        int best_idx = -1 , best_score = -1;
        for( int i = 0 ; i < n ; i++ ) {
            int l = words[i].length();
            for( int j = 0 ; j < i ; j++ )
                if(groups[i] != groups[j] and words[j].length() == l) {
                    int c = 0;
                    for( int k = 0 ; k < l ; k++ )
                        c += words[i][k] != words[j][k];
                    if(c == 1 and dp[j]+1 > dp[i]) {
                        dp[i] = dp[j]+1;
                        before[i] = j;
                    }
                }
            if(dp[i] > best_score) {
                best_idx = i;
                best_score = dp[i];
            }
        }
        int idx = best_idx;
        vector<string> ans;
        while(idx != -1) {
            ans.push_back(words[idx]);
            idx = before[idx];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
