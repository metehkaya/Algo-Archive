class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        ans.push_back(words[0]);
        int last = groups[0];
        for( int i = 1 ; i < n ; i++ )
            if(groups[i] != last) {
                last = groups[i];
                ans.push_back(words[i]);
            }
        return ans;
    }
};
