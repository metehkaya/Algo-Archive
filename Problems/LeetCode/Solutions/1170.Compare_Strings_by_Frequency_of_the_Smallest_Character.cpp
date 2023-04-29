class Solution {
public:
    int findFreq(string& s) {
        int n = s.length();
        vector<int> cnt(26,0);
        for( int i = 0 ; i < n ; i++ )
            cnt[s[i]-'a']++;
        for( int i = 0 ; i < 26 ; i++ )
            if(cnt[i])
                return cnt[i];
        return -1;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n = words.size() , m = queries.size();
        vector<int> total(12,0);
        for( int i = 0 ; i < n ; i++ ) {
            int f = findFreq(words[i]);
            total[f]++;
        }
        for( int i = 10 ; i >= 0 ; i-- )
            total[i] += total[i+1];
        vector<int> ans;
        for( int i = 0 ; i < m ; i++ ) {
            int f = findFreq(queries[i]);
            ans.push_back(total[f+1]);
        }
        return ans;
    }
};